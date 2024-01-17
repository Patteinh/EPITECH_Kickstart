##
## EPITECH PROJECT, 2024
## tests_project.py
## File description:
## Unit tests using Pytest
##

import pytest

from src.project import project, SUCCESS

def test_project_with_one_arg():
    assert project(1, ["arg1"]) == SUCCESS
