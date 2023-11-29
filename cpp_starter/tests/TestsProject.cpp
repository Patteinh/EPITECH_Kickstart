/*
** EPITECH PROJECT, 2023
** TestsProject.cpp
** File description:
** TestsProject
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static const int ERROR = 84;
static const int SUCCESS = 0;
static const int FAILURE = -1;
#define MAYBE_UNUSED [[maybe_unused]]

int project(MAYBE_UNUSED const std::vector<std::string> &args);

Test(project_tests, test_project_function)
{
    std::vector<std::string> args = {"./binary", "arg1", "arg2"};
    int ret = project(args);

    cr_assert_eq(ret, SUCCESS, "Expected: %d, Got: %d", SUCCESS, ret);
}
