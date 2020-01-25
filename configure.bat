pushd %~dp0%
if not exist build mkdir build
cd build
cmake ..
popd
exit /b 0