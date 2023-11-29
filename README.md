# EPITECH Kickstart 🚀

Fast-track your project development with EPITECH Kickstart!

EPITECH Kickstart is a comprehensive project initiation tool that aims to reduce the time and effort you spend on project setup. This tool provides you with a set of predefined starter kits for popular programming languages: C, C++, Haskell, and Python. Each kit is equipped with a standardized project structure, an automated build system via Makefiles, and unit testing frameworks. These kits are also enriched with a collection of utility functions and libraries for C projects.

With EPITECH Kickstart, you can focus more on developing your core project functionalities and less on the mundane setup tasks. Whether you are a student, a professional developer, or a hobbyist programmer, EPITECH Kickstart is designed to give your projects a flying start.

## Supported Programming Languages 🛠️

The starter kit supports projects in:

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Haskell](https://img.shields.io/badge/Haskell-5D4F85?style=for-the-badge&logo=haskell&logoColor=white)
![Python](https://img.shields.io/badge/Python-14354C?style=for-the-badge&logo=python&logoColor=white)

## Starter Pack Features 📂

Each language-specific starter comes with:

- `Makefile` for seamless build automation and dependency management.
- `src` directory containing all source files.
- `tests` directory with unit tests. For C, C++ and Python starters, testing generates a `coverage` directory in `tests` which includes a comprehensive coverage `html` report.

Detailed explanations of functions, macros, constants, and Makefile rules are in the respective starter sections below.

## Makefile Rules 🧰

- `all`: Default rule. Compiles the source code into the `project` binary.
- `debug`: Adds debugging information to the `project` binary using `-g3` flag.
- `tests_run`: Executes unit tests by calling `make` in the `tests` directory.
- `clean`: Removes all object files and cleans libraries and test directories.
- `fclean`: Removes the `project` binary, and then executes `clean`.
- `re`: Executes the `fclean` rule followed by the `all` rule (clean rebuild).

These rules are declared as phony targets to prevent conflicts with file names and to ensure that the command associated with the rule is executed regardless of the state of the file system.

## C Starter 📁

The C Starter have `Makefile`, `src` and `tests` directories. It creates a `coverage` directory in `tests` on running unit tests for a thorough code coverage analysis using the [Criterion](https://github.com/Snaipe/Criterion) framework.
Apart from the standard structure C Starter offer a librairy with general and linked list functions, macros and constants.

### Librairy details 📚

#### General Utility Functions:
- `arraylen(array)`: Returns the length of a given array.
- `clean_str(str, delim)`: Cleans a string by removing the provided delimiters.
- `str_to_array(str, delim)`: Splits a string into an array of substrings, based on the provided delimiter.
- `free_array(array)`: Freely deallocates the memory used by an array.

#### Linked List Utility Functions:
- `add_first_node(l)`: Adds a node at the beginning of the list.
- `add_front_node(l)`: Adds a node at the front of the list.
- `add_back_node(l)`: Adds a node at the end of the list.
- `add_node_at_position(l, pos)`: Adds a node at a specified position in the list.
- `get_front_node(l)`: Returns the first node from the list.
- `get_back_node(l)`: Returns the last node from the list.
- `get_node_at_position(l, pos)`: Returns a node at a specific position from the list.
- `del_front_node(l)`: Removes and frees the first node from the list.
- `del_back_node(l)`: Removes and frees the last node from the list.
- `del_node_at_position(l, pos)`: Removes and frees a node at a specific position from the list.
- `listlen(l)`: Returns the length of the list.
- `free_list(l)`: Frees all the nodes of the list.

#### Macros:
- `PERROR(e)`: Error message display and program termination with the exit code `ERROR`.
- `CERROR(is_error, e)`: Condition-based error message display and program termination with the exit code `ERROR`.
- `MAYBE_UNUSED`: Marks a variable as possibly unused, suppressing compiler warnings.

#### Constants:
- `SUCCESS`: Indicates a successful operation.
- `FAILURE`: Indicates a failed operation.
- `ERROR`: Exit code for errors.

## C++ Starter 📁

The C++ Starter mirrors the C Starter with its `Makefile` and well-organized `src` and `tests` directories but without `lib`. It creates a `coverage` directory in `tests` on running unit tests for a thorough code coverage analysis using the [Criterion](https://github.com/Snaipe/Criterion) framework.

## Haskell Starter 📁

The Haskell Starter uses Stack as the build tool. The `Makefile` provides the following rules:

- `make`: Builds the project using Stack and copies the executable to the root directory.
- `clean`: Cleans up the project files using Stack.
- `fclean`: Executes `make clean` and removes the project executable.
- `re`: Executes `make fclean` and then `make` for clean rebuild.

The `app` directory contains the `Main.hs` file, which serves as the entry point of the Haskell project. The `project.cabal` file is the project configuration file, and the `package.yaml` and `stack.yaml` files are used by Stack for project management.

## Python Starter 📁

The Python Starter has a `Makefile` at the root and in the `tests` directory, using [pytest](https://docs.pytest.org/en/7.4.x/) for testing. Its `Makefile` rules streamline project cleaning and recompilation, facilitating Python project development.

## Unit Testing 🔬

### Unit Testing with Criterion

The C/C++ Starter includes unit testing using the `Criterion` framework. Criterion is a powerful and easy-to-use testing framework for programming. It provides expressive syntax, built-in test fixtures, and detailed failure reporting.

To write and run unit tests in the C Starter, follow these steps:

1. Create your unit tests in the `tests` directory, using the `.c`/`.cpp` file extension.
2. Use the Criterion framework syntax to define your tests and assertions. Refer to the [Criterion documentation](https://github.com/Snaipe/Criterion) for detailed information on writing tests with Criterion.
3. Build and run the tests using the `tests_run` Makefile rule. This rule executes the unit tests and generates a comprehensive HTML coverage report in the `tests/coverage` directory.

### Unit Testing with Pytest

The Python Starter includes unit testing using the `pytest` framework. Pytest is a popular testing framework for Python that offers a simple and scalable approach to writing tests.

To write and run unit tests in the Python Starter, follow these steps:

1. Create your unit tests in the tests directory, using the `tests_*.py` file naming convention.
2. Use the pytest framework syntax to define your tests and assertions. Refer to the [pytest documentation](https://docs.pytest.org/en/7.4.x/) for detailed information on writing tests with Pytest.
3. Build and run the tests using the `tests_run` Makefile rule. This rule executes the unit tests and generates a comprehensive HTML coverage report in the `tests/htmlcov` directory.

## Installation 💾

1. Clone this repository:

    ```bash
    git clone git@github.com:Patteinh/EPITECH_Kickstart.git
    ```

2. Navigate to the cloned repository:

    ```bash
    cd EPITECH_Kickstart
    ./install.sh
    ```

   This will move the repository to your home directory, rename it to `.starter`, and install all the starter scripts in the `/usr/local/bin` directory so that you can use the commands from anywhere.

   > Note: The installation and uninstallation scripts provided should work on most Linux distributions. However, please ensure that you have the necessary dependencies installed and appropriate privileges to execute the scripts.

## Uninstallation 🗑️

If you wish to uninstall, you can use the uninstall.sh script:

```bash
./uninstall.sh
```

This will remove the .starter directory and all the installed starter scripts.

## Usage 🎯

You can now start your project in any of the supported programming languages by using the starter command followed by the language of your choice:

```bash
starter c
starter cpp
starter haskell
starter python
```

This command will create a copy of the corresponding language's starter template in your current directory.

If you're unsure about how to use the starter command or want to check the available languages, you can use the `-help` option:

```bash
starter -help
```
This command will display a helpful message explaining how to use the `starter` command and what languages are available.
Happy Coding! 🚀

# License ⚖️
MIT License
