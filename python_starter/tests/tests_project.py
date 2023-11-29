import pytest

from src.project import project, SUCCESS

def test_project_with_one_arg():
    assert project(1, ["arg1"]) == SUCCESS
