/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <vector>
#include <string>

#include "common-defs.hpp"

int project(M_UNUSED const std::vector<std::string> &args);

int main(const int ac, const char *const av[])
{
    std::vector<std::string> args(av, av + ac);
    return project(args);
}
