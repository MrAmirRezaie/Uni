#!/bin/bash

echo "############################################"
echo "#       AmirHossein Karbalaie Rezaie       #"
echo "############################################"

check_gpp_installed() {
    if ! command -v g++ &> /dev/null; then
        echo "g++ is not installed. Attempting to install MinGW..."
        if [ -x "$(command -v apt-get)" ]; then
            sudo apt-get update && sudo apt-get install mingw-w64 -y
        elif [ -x "$(command -v yum)" ]; then
            sudo yum install mingw64-gcc -y
        elif [ -x "$(command -v pacman)" ]; then
            sudo pacman -Sy mingw-w64-gcc
        elif [ -x "$(command -v zypper)" ]; then
            sudo zypper install mingw64-cross-gcc
        elif [ -x "$(command -v dnf)" ]; then
            sudo dnf install mingw64-gcc -y
        elif [ -x "$(command -v apk)" ]; then
            sudo apk add mingw-w64
        elif [ -x "$(command -v emerge)" ]; then
            sudo emerge -av crossdev && sudo crossdev -t x86_64-w64-mingw32
        elif [ -x "$(command -v xbps-install)" ]; then
            sudo xbps-install -S mingw-w64-gcc
        elif [ -x "$(command -v eopkg)" ]; then
            sudo eopkg install mingw-w64
        else
            echo "Package manager not recognized. Please install MinGW manually."
            exit 1
        fi
    else
        echo "g++ is already installed."
    fi
}

compile_and_run() {
    if command -v g++ &> /dev/null; then
        g++ "$selected_file" -o output
    elif command -v x86_64-w64-mingw32-g++ &> /dev/null; then
        x86_64-w64-mingw32-g++ "$selected_file" -o output
    else
        echo "Neither g++ nor MinGW is installed. Exiting."
        exit 1
    fi

    if [ $? -eq 0 ]; then
        echo "Compilation successful. Executing the program..."
        ./output
    else
        echo "Compilation failed."
    fi
}

check_gpp_installed

repo_url="https://github.com/MrAmirRezaie/Uni.git"
git clone "$repo_url" repo && cd repo || { echo "Failed to navigate to repository directory"; exit 1; }

files=(*.cpp)
echo "C++ files in the repository:"
for i in "${!files[@]}"; do
    echo "$i) ${files[$i]}"
done

read -p "Enter the number of the file to compile and execute: " file_number
selected_file=${files[$file_number]}

if [ -f "$selected_file" ]; then
    compile_and_run
else
    echo "Selected file does not exist."
fi
