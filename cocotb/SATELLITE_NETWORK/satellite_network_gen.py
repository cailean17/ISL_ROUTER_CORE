from __future__ import annotations

import math
import random
from dataclasses import dataclass

import matplotlib

# from CONSTANTS.constants import NUM_LINKS, NUM_PLANES, SATS_PER_PLANE
NUM_PLANES = 4
NUM_LINKS = 4
SATS_PER_PLANE = 4
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import numpy as np
from jinja2 import Environment, FileSystemLoader
import heapq

# Configuration
ORBIT_RADIUS = 1.0
INCLINATION_DEG = 53
PLANE_COLORS = [
    "red",
    "darkorange",
    "gold",
    "yellowgreen",
    "seagreen",
    "teal",
    "cyan",
    "deepskyblue",
    "royalblue",
    "navy",
    "blueviolet",
    "magenta",
    "deeppink",
    "saddlebrown",
    "slategray",
    "black",
]
JINJA_TEMPLATE_NAME = "satellite_network_tb.sv.j2"
TEMPLATE_EXPORT_LOCATION = "../../RTL/VERIFICATION_WRAPPERS/satellite_network.sv"
FIB_EXPORT_DIRECTORY = "../../utils/FIBS/"

@dataclass
class Edge:
    src_sat_id: int
    src_link_id: int
    dest_sat_id: int
    dest_link_id: int
    weight: int


@dataclass
class NetworkNode:
    id: int
    allocated_link_count: int
    inactive_links: set
    edges: list[Edge]


def generate_random_network_topology(num_sats, max_links_per_sat):
    network_adjacency_list: list[NetworkNode | None] = []
    for _ in range(num_sats):
        network_adjacency_list.append(None)

    for i in range(num_sats):
        allocated_link_count = random.randint(max_links_per_sat, max_links_per_sat)
        inactive_link_set = {i for i in range(allocated_link_count)}
        network_adjacency_list[i] = NetworkNode(
            id=i,
            allocated_link_count=allocated_link_count,
            inactive_links=inactive_link_set,
            edges=[],
        )

    for j in range(num_sats):
        src_sat = network_adjacency_list[j]
        if src_sat is None:
            print(
                "WARNING: Found Empty NoneType Object in Network Adjacency List after initialization"
            )
            continue
        for src_link_id in network_adjacency_list[j].inactive_links.copy():
            candidates = [
                node
                for node in network_adjacency_list
                if node is not None
                and node.id != src_sat.id
                and node.inactive_links
                and node.id not in {edge.dest_sat_id for edge in src_sat.edges}
            ]
            if not candidates:
                break
            candidate_dest_sat = random.choice(candidates)
            dest_link_id = random.choice(list(candidate_dest_sat.inactive_links))
            src_sat.edges.append(
                Edge(
                    src_sat_id=src_sat.id,
                    src_link_id=src_link_id,
                    dest_sat_id=candidate_dest_sat.id,
                    dest_link_id=dest_link_id,
                )
            )
            candidate_dest_sat.edges.append(
                Edge(
                    src_sat_id=candidate_dest_sat.id,
                    src_link_id=dest_link_id,
                    dest_sat_id=src_sat.id,
                    dest_link_id=src_link_id,
                )
            )
            src_sat.inactive_links.remove(src_link_id)
            candidate_dest_sat.inactive_links.remove(dest_link_id)
    return network_adjacency_list


def visualize_random_network(network_adjacency_list):
    import matplotlib.pyplot as plt
    import networkx as nx

    G = nx.Graph()

    for sat in network_adjacency_list:
        if sat is None:
            continue

        G.add_node(sat.id)

        for edge in sat.edges:
            G.add_edge(edge.src_sat_id, edge.dest_sat_id)

    pos = nx.spring_layout(G)

    fig, ax = plt.subplots(figsize=(14, 14))
    sat_labels = {node: f"Sat {node}" for node in G.nodes()}
    nx.draw_networkx_edges(G, pos, ax=ax, edge_color="gray", width=1.5)
    nx.draw_networkx_nodes(G, pos, ax=ax, node_color="skyblue", node_size=800)
    nx.draw_networkx_labels(G, pos, labels=sat_labels, ax=ax, font_size=9)
    ax.set_title("Satellite OISL Network Topology")
    ax.axis("off")
    fig.savefig("Network.png", dpi=200, bbox_inches="tight")
    plt.close(fig)


def generate_topology():
    """Generate a ring topology with intra and inter-orbital-plane links."""
    network_adjacency_list: list[NetworkNode | None] = []
    # Node creation
    for plane in range(NUM_PLANES):
        for sat_pos in range(SATS_PER_PLANE):
            sat_id = plane * SATS_PER_PLANE + sat_pos
            node : NetworkNode = NetworkNode(
                id=sat_id, 
                allocated_link_count=4, 
                inactive_links=set(), 
                edges=[]
            )
            network_adjacency_list.append(node)
    for plane in range(NUM_PLANES):
        next_plane = (plane + 1) % NUM_PLANES
        for sat_pos in range(SATS_PER_PLANE):
            # Intra-plane links: connect each satellite to its next neighbor.
            # Modulo arithmetic creates the wraparound link.
            src = plane * SATS_PER_PLANE + sat_pos
            dst = plane * SATS_PER_PLANE + (sat_pos + 1) % SATS_PER_PLANE
            network_adjacency_list[src].edges.append(Edge(src_sat_id=src, src_link_id=1, dest_sat_id=dst, dest_link_id=0, weight=1))
            network_adjacency_list[dst].edges.append(Edge(src_sat_id=dst, src_link_id=0, dest_sat_id=src, dest_link_id=1, weight=1))

            # Inter-plane links: connect matching positions in adjacent planes.
            src = plane * SATS_PER_PLANE + sat_pos
            dst = next_plane * SATS_PER_PLANE + sat_pos
            network_adjacency_list[src].edges.append(Edge(src_sat_id=src, src_link_id=2, dest_sat_id=dst, dest_link_id=3, weight=2))
            network_adjacency_list[dst].edges.append(Edge(src_sat_id=dst, src_link_id=3, dest_sat_id=src, dest_link_id=2, weight=2))

    return network_adjacency_list


def calculate_positions():
    """Place satellites on tilted 3D orbital rings."""

    positions = {}
    F = 3
    inclination = math.radians(INCLINATION_DEG)

    for plane in range(NUM_PLANES):
        # Rotate each orbital plane around Earth's Z axis.
        ascending_node_angle = 2 * math.pi * plane / NUM_PLANES

        for sat_pos in range(SATS_PER_PLANE):
            # Angular position of satellite within its orbit.
            theta = (
                2 * math.pi * sat_pos / SATS_PER_PLANE
                + 2 * math.pi * F * plane / (NUM_PLANES * SATS_PER_PLANE)
            )

            # Circle in the orbital plane.
            x0 = ORBIT_RADIUS * math.cos(theta)
            y0 = ORBIT_RADIUS * math.sin(theta)

            # Tilt the orbital plane about the X axis.
            x1 = x0
            y1 = y0 * math.cos(inclination)
            z1 = y0 * math.sin(inclination)

            # Rotate around Earth's Z axis.
            omega = ascending_node_angle
            x = x1 * math.cos(omega) - y1 * math.sin(omega)
            y = x1 * math.sin(omega) + y1 * math.cos(omega)
            z = z1

            sat_id = plane * SATS_PER_PLANE + sat_pos
            positions[sat_id] = (x, y, z)

    return positions

def visualize_network(network_adjacency_list: list[NetworkNode], positions):
    """Draw the 3D satellite network."""
    fig = plt.figure(figsize=(12, 10))
    ax = fig.add_subplot(111, projection="3d")

    # Draw Earth.
    u = np.linspace(0, 2 * math.pi, 20)
    v = np.linspace(0, math.pi, 20)
    earth_radius = 6371 / (6371 + 550)   # ≈ 0.92

    x_earth = earth_radius * np.outer(np.cos(u), np.sin(v))
    y_earth = earth_radius * np.outer(np.sin(u), np.sin(v))
    z_earth = earth_radius * np.outer(np.ones_like(u), np.cos(v))

    ax.plot_surface(
        x_earth,
        y_earth,
        z_earth,
        color="steelblue",
        alpha=0.25,
        linewidth=0,
    )

    # Draw complete orbital paths.
    theta_values = np.linspace(0, 2 * math.pi, 200)
    inclination = math.radians(INCLINATION_DEG)

    for plane in range(NUM_PLANES):
        omega = 2 * math.pi * plane / NUM_PLANES
        orbit_points = []

        for theta in theta_values:
            x0 = ORBIT_RADIUS * math.cos(theta)
            y0 = ORBIT_RADIUS * math.sin(theta)

            # Tilt the orbit around X
            x1 = x0
            y1 = y0 * math.cos(inclination)
            z1 = y0 * math.sin(inclination)

            # Rotate the orbit around Z.
            x = x1 * math.cos(omega) - y1 * math.sin(omega)
            y = x1 * math.sin(omega) + y1 * math.cos(omega)
            z = z1

            orbit_points.append((x, y, z))

        orbit_points = np.array(orbit_points)

        ax.plot(
            orbit_points[:, 0],
            orbit_points[:, 1],
            orbit_points[:, 2],
            color=PLANE_COLORS[plane],
            alpha=0.6,
            linewidth=1.5,
        )

    # Draw ISL connections.
    for node in network_adjacency_list:
        for edge in node.edges:
            x1, y1, z1 = positions[node.id]
            x2, y2, z2 = positions[edge.dest_sat_id]

            ax.plot(
                [x1, x2],
                [y1, y2],
                [z1, z2],
                color="black",
                linestyle="solid",
                linewidth=0.5,
            )

    # # Draw satellites and labels.
    for plane in range(NUM_PLANES):
        satellite_ids = [plane * SATS_PER_PLANE + i for i in range(SATS_PER_PLANE)]

        coords = np.array([positions[sat_id] for sat_id in satellite_ids])

        ax.scatter(
            coords[:, 0],
            coords[:, 1],
            coords[:, 2],
            color=PLANE_COLORS[plane],
            s=45,
            edgecolors="white",
            linewidths=0.5,
            label=f"Plane {plane}",
        )

        for sat_id in satellite_ids:
            x, y, z = positions[sat_id]

            ax.text(
                x * 1.06,
                y * 1.06,
                z * 1.06,
                str(sat_id),
                fontsize=8,
            )

    ax.set_title(
        "3D Satellite ISL Network Topology\n"
        f"{NUM_PLANES} planes × {SATS_PER_PLANE} satellites"
    )

    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Z")

    ax.set_box_aspect((1, 1, 1))
    ax.set_xlim(-1.25, 1.25)
    ax.set_ylim(-1.25, 1.25)
    ax.set_zlim(-1.25, 1.25)
    ax.view_init(elev=24, azim=35)
    ax.legend()

    plt.tight_layout()
    plt.savefig("satellite_isl_3d_visualization.png", dpi=180)
    plt.show()


def dijkstras(network_adjacency_list: list[NetworkNode], start_node: int):
    mh = []
    heapq.heapify(mh)
    dist = [float("inf")] * len(network_adjacency_list)
    path = {node.id: None for node in network_adjacency_list}
    visited = [False] * len(network_adjacency_list) 
    dist[start_node] = 0
    heapq.heappush(mh, (0, start_node))
    while len(mh) != 0:
        top = heapq.heappop(mh)
        curr_dist = top[0]
        curr_sat_id : int  = top[1]
        if (not visited[curr_sat_id]):
            visited[curr_sat_id] = True
            for edge in network_adjacency_list[curr_sat_id].edges:
                if ((curr_dist + edge.weight) < dist[edge.dest_sat_id]):
                    dist[edge.dest_sat_id] = curr_dist + edge.weight
                    path[edge.dest_sat_id] = curr_sat_id
                    heapq.heappush(mh, (curr_dist + edge.weight, edge.dest_sat_id))
    return path

def generate_fibs(network_adjacency_list: list[NetworkNode]):
    n = SATS_PER_PLANE * NUM_PLANES
    fibs = [[0] * n for _ in range(n)]
    for node in network_adjacency_list:
        # Running Dijkstras from the dest node outwards for every node in the graph (many to one)
        next_hops_to_get_to_node = dijkstras(network_adjacency_list, node.id)
        for sat_id, fib in enumerate(fibs):
            # find ISL link id that maps to the next hop
            next_hop_isl_link = list(filter(lambda x: x.dest_sat_id == next_hops_to_get_to_node[sat_id], network_adjacency_list[sat_id].edges))
            fib[node.id] = None if len(next_hop_isl_link) == 0 else next_hop_isl_link[0].src_link_id
    print(fibs)
    return fibs

def export_fibs(fibs):
    for i,fib in enumerate(fibs):
        with open(FIB_EXPORT_DIRECTORY+"SAT"+str(i)+"_FIB.mem", "w", encoding="utf-8") as file:
            file.truncate(0)
        with open(FIB_EXPORT_DIRECTORY+"SAT"+str(i)+"_FIB.mem", "a+", encoding="utf-8") as file:
            for link in fib:
                if link is None:
                    file.write(f"{NUM_LINKS:08x}\n") # downlink sink is mapped to the NUM_LINKsth link_adapter_tx
                else:
                    file.write(f"{link:08x}\n")        

def generate_satellite_tb_file(network_adjacency_list: list[NetworkNode]):
    env = Environment(loader=FileSystemLoader('JinjaTemplates'))
    template = env.get_template(JINJA_TEMPLATE_NAME)
    input = {
        "input" :{
            "constants":{
                "NUM_LINKS": NUM_LINKS, 
                "NUM_PLANES": NUM_PLANES,
                "SATS_PER_PLANE": SATS_PER_PLANE
            },
            "fib_dir": FIB_EXPORT_DIRECTORY,
            "network_adjacency_list": network_adjacency_list
        }
    }
    tb = template.render(input)
    with open(TEMPLATE_EXPORT_LOCATION, "w", encoding="utf-8") as file:
        file.write(tb)

if __name__ == "__main__":
    graph = generate_topology()
    positions = calculate_positions()
    generate_satellite_tb_file(graph)
    export_fibs(generate_fibs(graph))
    visualize_network(graph, positions)
    print(f"Satellites: {len(graph)}")
    print(f"Links: {len(graph)*4}")
