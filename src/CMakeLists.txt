cmake_minimum_required(VERSION 3.29)
project(node)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        source/twoParameterOperation.cpp
        source/node.cpp
        source/calculationMethod.cpp
        source/basicUpdate.cpp
        source/activateFunction.cpp
        source/lossFunction.cpp
        source/tensor.cpp
        source/utils.cpp
        source/netFunction.cpp
)

add_library(nodeLib STATIC ${SOURCE_FILES})

add_executable(node
        ${SOURCE_FILES}
)

