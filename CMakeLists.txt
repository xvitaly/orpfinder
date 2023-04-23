#
# SPDX-FileCopyrightText: 2022-2023 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

# ======================================================
# =============== Project initialization ===============
# ======================================================

cmake_minimum_required(VERSION 3.12)

project(orpfinder
    VERSION 0.2.0
    DESCRIPTION "Command-line tool to find orphaned packages"
    HOMEPAGE_URL "https://github.com/xvitaly/orpfinder"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================================================
# ================= Internal imports ===================
# ======================================================

include(GNUInstallDirs)

# ======================================================
# ================= libsolv detection ==================
# ======================================================

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSOLV REQUIRED IMPORTED_TARGET libsolv)
pkg_check_modules(LIBSOLVEXT REQUIRED IMPORTED_TARGET libsolvext)

# ======================================================
# ================= Application target =================
# ======================================================

set(HEADERS
    src/application/application.hpp
)

set(SOURCES
    src/application/application.cpp
    src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    "src"
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    PkgConfig::LIBSOLV
    PkgConfig::LIBSOLVEXT
)

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
