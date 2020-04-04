#!/bin/bash
CUR_DIR=${PWD}
ProjectRootFolder=${CUR_DIR}
HostBuildPath=${CUR_DIR}/build
HostCmakePath=${ProjectRootFolder}
BuildType="Debug" #Release|Debug
CpuCount=$(cat /proc/cpuinfo| grep "processor"| wc -l)


function build_x86()
{
    rm -rf $HostBuildPath
    mkdir -p $HostBuildPath
    cd $HostBuildPath
    cmake -DCMAKE_BUILD_TYPE=$BuildType \
          ${HostCmakePath}
    make -j$CpuCount
}

function build_all()
{
#build host
    build_x86

#clean existing binaries
    rm -rf ${ProjectRootFolder}/bin
#copy device library
    if [ ! -d ${ProjectRootFolder}/bin ];then
        mkdir -p ${ProjectRootFolder}/bin
    fi
    #cp $HostBuildPath/*/*.so ${ProjectRootFolder}/bin/

#copy host executable to bin
    cp $HostBuildPath/shared_ptr_test/shared_ptr_test ${ProjectRootFolder}/bin/
}

# function copy_files()
# {

# }

# function package_files()
# {

# }

function run_demo()
{
    cd ${ProjectRootFolder}/bin
    ${ProjectRootFolder}/bin/shared_ptr_test
    cd ${CUR_DIR}
}

function main()
{
    build_all
    run_demo
    
}

main
