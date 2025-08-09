# Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
# This file is part of DesignPatternsCPP.
# Licensed under the GNU General Public License v3.0 or later.
# See <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.10)

project(DesignPatternsCPP)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_SOURCE_DIR}/config.cmake)

add_subdirectory(creational_patterns)
