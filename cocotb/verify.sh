DV_MODULE_DIRS=("./CRC" "./CROSSBAR_ARBITER" "./L3_BUFFER" "./L3_BUFFER_ARBITER" "./LINK_ADAPTER_RX" "./LINK_ADAPTER_TX" "./ROUTER_CORE", "./SATELLITE_NETWORK")
for dir in "${DV_MODULE_DIRS[@]}"; do
	cd $dir
	make
	verilator_coverage --line --write-info coverage.info coverage.dat
	lcov -a coverage.info -o coverage.info
	cd ../
done
