/**
 * SPDX-FileCopyrightText: 2022-2023 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <iostream>
#include <stdlib.h>

namespace solv {
extern "C" {
#include <solv/pool.h>
#include <solv/poolarch.h>
#include <solv/queue.h>
#include <solv/repo_rpmdb.h>
}
}

#include "application/application.hpp"

std::vector<std::string> Application::GetUnneededPackages() const
{
    std::vector<std::string> Result;
    solv::Queue SlvQueue;

    solv::queue_init(&SlvQueue);
    solv::solver_solve(SlvSolver, &SlvQueue);
    solv::solver_get_unneeded(SlvSolver, &SlvQueue, 1);

    for (int i = 0; i < SlvQueue.count; i++)
    {
        Result.push_back(solv::pool_solvid2str(SlvPool, SlvQueue.elements[i]));
    }

    solv::queue_free(&SlvQueue);
    return Result;
}

int Application::Run()
{
    for (const std::string& Element: GetUnneededPackages())
    {
        std::cout << Element << std::endl;
    }
    return EXIT_SUCCESS;
}

Application::Application()
{
    SlvPool = solv::pool_create();
    solv::pool_setarch(SlvPool, nullptr);
    solv::pool_set_flag(SlvPool, POOL_FLAG_IMPLICITOBSOLETEUSESCOLORS, 1);

    SlvDatabase = solv::repo_create(SlvPool, "@system");
    solv::repo_add_rpmdb(SlvDatabase, nullptr, 0);
    SlvPool -> installed = SlvDatabase;

    SlvSolver = solv::solver_create(SlvPool);
    solv::solver_set_flag(SlvSolver, SOLVER_FLAG_KEEP_EXPLICIT_OBSOLETES, 1);
    solv::solver_set_flag(SlvSolver, SOLVER_FLAG_BEST_OBEY_POLICY, 1);
    solv::solver_set_flag(SlvSolver, SOLVER_FLAG_YUM_OBSOLETES, 1);
}

Application::~Application()
{
    solv::solver_free(SlvSolver);
    SlvSolver = nullptr;

    solv::repo_free(SlvDatabase, 0);
    SlvDatabase = nullptr;

    solv::pool_free(SlvPool);
    SlvPool = nullptr;
}
