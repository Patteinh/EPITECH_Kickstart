#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## main.py
## File description:
## main
##

import sys
import project

def main(ac, av):
    return project.project(ac, av)

if __name__ == "__main__":
    main(len(sys.argv), sys.argv)
