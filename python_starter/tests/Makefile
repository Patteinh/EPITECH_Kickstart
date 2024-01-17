##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		:=	pytest

SRC_DIR		:=	../src/

COVFLAGS	:=	coverage run -m
COV_RC		:=	--rcfile=.coveragerc

all: coverage

coverage:
	$(COVFLAGS) $(COV_RC) $(NAME) -v -ra -k "not failing" tests_*.py || true
	coverage html

clean:
	find . -name "__pycache__" -exec rm -r {} +
	find . -name "*.pyc" -delete
	$(RM) -r .pytest_cache
	$(RM) -r htmlcov
	$(RM) .coverage

.PHONY: all tests coverage clean
