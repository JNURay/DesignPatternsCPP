# Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the MIT License.
# See <https://opensource.org/licenses/MIT>.

set(TARGET class_adapter)

add_executable(${TARGET} class_adapter.cpp)

add_executable(${PROJECT_NAME}::${TARGET} ALIAS ${TARGET})

target_include_directories(${TARGET} PRIVATE "inc")

set(TARGET object_adapter)

add_executable(${TARGET} object_adapter.cpp)

add_executable(${PROJECT_NAME}::${TARGET} ALIAS ${TARGET})

target_include_directories(${TARGET} PRIVATE "inc")
