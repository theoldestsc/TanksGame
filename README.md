# TanksGame
Simple Tanks game based on SDL2. In development yet.
# Build
```
mkdir build
cd build
cmake ..
make -j4
```
# Build and Run Tests
```
mkdir build
cd build
cmake -DENABLE_UNIT_TESTS=ON ..
make -j4
ctest
```
