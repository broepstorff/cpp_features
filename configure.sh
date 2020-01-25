#!/bin/sh
mkdir -p build
pushd build
cmake -G "Xcode" ..
popd
exit 0