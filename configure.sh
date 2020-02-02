#!/bin/sh
mkdir -p build
pushd build
#add --trace-expand to debug
cmake -G "Xcode" ..
popd
exit 0