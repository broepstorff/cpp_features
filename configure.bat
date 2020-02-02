pushd %~dp0%
if not exist build mkdir build
cd build
rem add --trace-expand to debug
cmake ..
popd
exit /b 0