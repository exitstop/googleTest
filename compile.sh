rm -rf build_dbg
mkdir -p build_dbg
cd build_dbg
cmake -GNinja .. -DCMAKE_BUILD_TYPE=Debug -DTEST=ON
ninja
ninja test
