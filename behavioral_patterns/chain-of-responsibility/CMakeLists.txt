# Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the MIT License.
# See <https://opensource.org/licenses/MIT>.

set(TARGET chain_of_responsibility)

add_executable(${TARGET} chain_of_responsibility.cpp)

add_executable(${PROJECT_NAME}::${TARGET} ALIAS ${TARGET})
