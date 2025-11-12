# Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the MIT License.
# See <https://opensource.org/licenses/MIT>.

set(TARGET observer)

add_executable(${TARGET} observer.cpp)

add_executable(${PROJECT_NAME}::${TARGET} ALIAS ${TARGET})
