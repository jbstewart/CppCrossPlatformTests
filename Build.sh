#!/bin/bash

GCC="/opt/intel/system_studio_2018/compilers_and_libraries_2018.2.199/linux/bin/intel64/icc"
GXX="/opt/rh/devtoolset-7/root/usr/bin/g++"
INTEL="/opt/intel/system_studio_2018/compilers_and_libraries_2018.2.199/linux/bin/intel64/icc" 
GCC_BUILD_DIR=".build_gcc"
INTEL_BUILD_DIR=".build_intel"
CMAKE_GCC="cmake3 -DCMAKE_C_COMPILER=$GCC -DCMAKE_CXX_COMPILER=$GXX -H. -B$GCC_BUILD_DIR"
CMAKE_BUILD_GCC="cmake3 --build $GCC_BUILD_DIR"
CMAKE_INTEL=""

if [[ $# -eq 0  || ! ( $1 == 'gcc' || $1 == 'intel' ) ]] ; then
    echo "Build [ gcc | intel ]"
    exit 1
fi

if [[ $1 == 'gcc' ]] ; then
    if eval $CMAKE_GCC ; then fail "Build gcc - CMake phase failed"; fi
    if eval $CMAKE_BUILD_GCC; then fail "Build gcc - Make phase failed"; fi
else if [[ $1 == 'intel' ]] ; then
    echo "Intel not implemented";
fi

exit 0

function fail() {
    echo "$1"
    exit 1
}