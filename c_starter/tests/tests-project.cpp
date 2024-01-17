/*
** EPITECH PROJECT, 2024
** tests-project.cpp
** File description:
** Unit tests using Google Test
*/

#include <gtest/gtest.h>

extern "C" {
    #include "project.h"
    #include "lib.h"
}

TEST(ProjectTest, TestProjectFunction) {
    int ac = 3;
    const char * const av[] = {"./binary", "arg1", "arg2", nullptr};
    int ret = project(ac, av);

    EXPECT_EQ(ret, SUCCESS) << "Expected: " << SUCCESS << ", Got: " << ret;
}
