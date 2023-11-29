/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include <vector>
#include <string>

#define MAYBE_UNUSED [[maybe_unused]]

int project(MAYBE_UNUSED const std::vector<std::string> &args);

int main(int ac, char **av)
{
    std::vector<std::string> args(av, av + ac);
    return project(args);
}
