# Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the MIT License.
# See <https://opensource.org/licenses/MIT>.

set(TARGET factory-method)

add_executable(${TARGET} main.cpp)

add_executable(${PROJECT_NAME}::${TARGET} ALIAS ${TARGET})

target_include_directories(${TARGET} PRIVATE "factory" "product")
