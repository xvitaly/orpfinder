/**
 * SPDX-FileCopyrightText: 2022 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <iostream>
#include <stdexcept>
#include <memory>

#include "application/application.hpp"

/**
 * The main entry point.
*/
int main()
{
    try
    {
        return std::make_unique<Application>() -> Run();
    }
    catch (std::exception& e)
    {
        std::cerr << "An error occured: " << e.what() << std::endl;
    }
    return EXIT_FAILURE;
}
