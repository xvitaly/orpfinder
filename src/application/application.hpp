/**
 * SPDX-FileCopyrightText: 2022 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/** @file application/application.hpp
 *  This file is a part of orpfinder application.
 */

#include <vector>
#include <string>

namespace solv {
extern "C" {
#include <solv/pool.h>
#include <solv/poolarch.h>
#include <solv/repo_rpmdb.h>
#include <solv/solver.h>
}
}

/**
 *  Main class of the application.
*/
class Application
{
public:
    /**
     *  Main constructor of the Application class.
    */
    Application();

    /**
     *  Main destructor of the Application class.
    */
    ~Application();

    /**
     *  Runs an application and return the exit code.
     * @returns Exit code.
    */
    int Run();
private:
    /**
     *  Returns an unsorted collection of unneded packages.
    */
    std::vector<std::string> GetUnneededPackages() const;

    /**
     *  Stores a pointer to an instance of the solv::Pool structure.
    */
    solv::Pool *SlvPool = nullptr;

    /**
     *  Stores a pointer to an instance of the solv::Repo structure.
    */
    solv::Repo *SlvDatabase = nullptr;

    /**
     *  Stores a pointer to an instance of the solv::Repo structure.
    */
    solv::Solver *SlvSolver = nullptr;
};

#endif // APPLICATION_HPP
