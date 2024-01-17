#!/bin/bash

REPO_DIR=$(pwd)
REPO_NAME=$(basename "$REPO_DIR")

HOME_DIR="$HOME"

if [[ "$REPO_DIR" != "$HOME_DIR/$REPO_NAME" ]]; then
  mv "$REPO_DIR" "$HOME_DIR/"
fi

mv "$HOME_DIR/$REPO_NAME" "$HOME_DIR/.starter"

cd "$HOME_DIR/.starter"

cat > starter.sh << 'EOL'
#!/bin/bash

modify_project() {
    local project_name=$1
    local language=$2
    local project_dir="$HOME/.starter/${language}_starter"
    local new_project_dir="$(pwd)/${project_name}"

    cp -r "$project_dir" "$new_project_dir"

    cd "$new_project_dir" || exit

    if [[ $language == "c" ]]; then
        local new_c_file=src/${project_name}.c
        local new_header_file=include/${project_name}.h
        local new_test_file=tests/tests-${project_name}.cpp

        [ -f src/project.c ] && mv src/project.c "$new_c_file"
        [ -f include/project.h ] && mv include/project.h "$new_header_file"
        [ -f tests/tests-project.cpp ] && mv tests/tests-project.cpp "$new_test_file"

        sed -i "s/#include \"project.h\"/#include \"${project_name}.h\"/" src/main.c "$new_c_file" "$new_test_file"
        sed -i "s/project(/${project_name}(/g" src/main.c "$new_c_file" "$new_test_file"
        sed -i "s/main\.c/main.c/" src/main.c
        sed -i "s/TEST(ProjectTest, TestProjectFunction)/TEST(${project_name^}Test, Test${project_name^}Function)/" "$new_test_file"
        sed -i "s/\\*\\* tests-project\\.cpp/\\*\\* tests-${project_name}.cpp/" "$new_test_file"
        sed -i "s/int project(/int ${project_name}(/" "$new_header_file"
        sed -i "s/\\*\\* project header/\\*\\* ${project_name} header/" "$new_header_file"
    elif [[ $language == "cpp" ]]; then
	    local new_cpp_file=src/${project_name}.cpp
        local new_test_file=tests/tests-${project_name}.cpp
        local main_cpp_file=src/main.cpp

        [ -f src/project.cpp ] && mv src/project.cpp "$new_cpp_file"
        [ -f tests/tests-project.cpp ] && mv tests/tests-project.cpp "$new_test_file"

        sed -i "s/int project(/int ${project_name}(/" "$new_cpp_file" "$main_cpp_file"
        sed -i "s/project(args)/${project_name}(args)/g" "$main_cpp_file"
        sed -i "s/TEST(ProjectTests, TestProjectFunction)/TEST(${project_name^}Tests, Test${project_name^}Function)/" "$new_test_file"
        sed -i "s/\\*\\* tests-project\\.cpp/\\*\\* tests-${project_name}.cpp/" "$new_test_file"
        sed -i "s/project.cpp/${project_name}.cpp/" "$new_cpp_file"
	    sed -i "s/int project(/int ${project_name}(/" "$new_test_file"
        sed -i "s/project(args)/${project_name}(args)/g" "$new_test_file"
    fi

    sed -i "s/NAME\s*:=\s*project/NAME        :=  ${project_name}/" Makefile
    local files_to_update=$(find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \))
    for file in $files_to_update; do
        sed -i "s/\\*\\* project/\\*\\* ${project_name}/" "$file"
    done

    if [[ $language == "python" ]]; then
        local new_py_file=src/${project_name}.py
        local new_test_file=tests/tests_${project_name}.py
        local main_py_file=src/main.py

        [ -f src/project.py ] && mv src/project.py "$new_py_file"
        [ -f tests/tests_project.py ] && mv tests/tests_project.py "$new_test_file"

        sed -i "s/import project/import ${project_name}/" "$main_py_file"
        sed -i "s/project.project/${project_name}.${project_name}/" "$main_py_file"
        sed -i "s/from src.project import project, SUCCESS/from src.${project_name} import ${project_name}, SUCCESS/" "$new_test_file"
        sed -i "s/NAME\s*:=\s*project/NAME        :=  ${project_name}/" Makefile
        sed -i "s/project\.py/${project_name}.py/" "$new_py_file"
        sed -i "s/## project/## ${project_name}/" "$new_py_file"
        sed -i "s/def project(/def ${project_name}(/" "$new_py_file"
        sed -i "s/project(/${project_name}(/g" "$new_test_file"
	    sed -i "s/test_project_with_one_arg/test_${project_name}_with_one_arg/" "$new_test_file"
	    sed -i "s/## tests_project.py/## tests_${project_name}.py/" "$new_test_file"
    fi
}

if [[ "$#" -lt 1 ]]; then
    echo "Usage: starter <language> | -help"
    echo "Available languages: c, cpp, python"
    exit 1
fi

if [ "$1" = "-help" ]; then
    echo "Usage: starter <language>"
    echo "The starter command creates a new project in the specified language by copying the corresponding starter template."
    echo "Available languages: c, cpp, python"
    exit 0
fi

read -p "Project Name: " project_name

modify_project "$project_name" "$1"
echo "Project $project_name has been created."

EOL

chmod +x "$HOME_DIR/.starter/starter.sh"
sudo mv "$HOME_DIR/.starter/starter.sh" "/usr/local/bin/starter"
echo "Installation successful. You can now use the starter script from anywhere."

