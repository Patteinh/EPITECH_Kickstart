/*
** EPITECH PROJECT, 2024
** tests-project.cpp
** File description:
** Unit tests using Google Test
*/

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "common-defs.hpp"

int project(M_UNUSED const std::vector<std::string> &args);

TEST(ProjectTests, TestProjectFunction) {
    std::vector<std::string> args = {"./binary", "arg1", "arg2"};
    int ret = project(args);

    EXPECT_EQ(ret, SUCCESS) << "Expected: " << SUCCESS << ", Got: " << ret;
}
