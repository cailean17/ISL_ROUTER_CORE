DV_MODULE_DIRS=("./CRC" "./CROSSBAR_ARBITER" "./L3_BUFFER" "./L3_BUFFER_ARBITER" "./LINK_ADAPTER_RX" "./LINK_ADAPTER_TX" "./ROUTER_CORE")
for dir in "${DV_MODULE_DIRS[@]}"; do
	cd $dir
	make
	cd ../
done
