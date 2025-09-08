# Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the MIT License.
# See <https://opensource.org/licenses/MIT>.

cmake_minimum_required(VERSION 3.10)

project(DesignPatternsCPP)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_SOURCE_DIR}/config.cmake)

add_subdirectory(creational_patterns)
