#
# SPDX-FileCopyrightText: 2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

cmake_minimum_required(VERSION 3.12)

project(orpfinder
    VERSION 0.1.0
    DESCRIPTION "Command-line tool to find orphaned packages"
    HOMEPAGE_URL "https://github.com/EasyCoding/orpfinder"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSOLV IMPORTED_TARGET libsolv)
pkg_check_modules(LIBSOLVEXT IMPORTED_TARGET libsolvext)

include(GNUInstallDirs)

include_directories("src")

set(SOURCES
    src/application/application.cpp
    src/main.cpp
)

set(HEADERS
    src/application/application.hpp
)

set(INTERNAL_LIBS
    ${HEADERS}
    ${SOURCES}
)

set(EXTERNAL_LIBS
    PkgConfig::LIBSOLV
    PkgConfig::LIBSOLVEXT
)

add_executable(${CMAKE_PROJECT_NAME} ${INTERNAL_LIBS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${EXTERNAL_LIBS})

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
