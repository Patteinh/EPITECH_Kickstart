/*
** EPITECH PROJECT, 2023
** tests_project.c
** File description:
** tests_project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "project.h"
#include "lib.h"

int project(MAYBE_UNUSED int ac, MAYBE_UNUSED char **av);

Test(project_tests, test_project_function)
{
    int argc = 3;
    char *argv[] = {"./binary", "arg1", "arg2", NULL};
    int ret = project(argc, argv);

    cr_assert_eq(ret, SUCCESS, "Expected: %d, Got: %d", SUCCESS, ret);
}
