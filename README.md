Uni Repository Setup and Compilation Script

This script automates the process of cloning the `Uni` repository, checking for the necessary tools, compiling, and executing a selected C++ file from the repository.

Features

- Checks if `g++` is installed and attempts to install MinGW if it is not.
- Clones the specified repository.
- Lists all C++ (`.cpp`) files in the repository for user selection.
- Compiles and executes the selected C++ file.

Prerequisites

- A Unix-based operating system (Linux, macOS, etc.).
- Internet connection for cloning the repository and installing packages.
- A package manager (such as `apt-get`, `yum`, `pacman`, etc.) for installing MinGW if `g++` is not available.

Usage

1. Clone the repository and change directory:

    The script first clones the `Uni` repository and navigates into it.

    ```bash
    repo_url="https://github.com/MrAmirRezaie/Uni.git"
    git clone "$repo_url" Uni
    cd Uni
    ```

2. Check for `g++` installation:

    The script checks if `g++` is installed. If not, it attempts to install MinGW using the available package manager.

3. List C++ files and select one for compilation:

    The script lists all `.cpp` files in the repository and prompts the user to select a file for compilation.

    ```bash
    files=(*.cpp)
    echo "C++ files in the repository:"
    for i in "${!files[@]}"; do
        echo "$i) ${files[$i]}"
    done
    ```

4. Compile and execute the selected file:

    The script compiles and executes the selected C++ file.

    ```bash
    if [ -f "$selected_file" ]; then
        compile_and_run
    else
        echo "Selected file does not exist."
    fi
    ```

## Running the Script

To run the script, save it to a file (e.g., `install.sh`) and execute it:

```bash
chmod +x install.sh
install.sh
