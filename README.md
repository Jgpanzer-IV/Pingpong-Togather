# SDL-LinuxBased-Template
        This repository store The Graphical-Based Application for starter project written in C++ and use SDL as the main library.
    This readme file containing information about the project itself. - Project structure - How to Run and Build the project with cmake - How add additional library - How to clean project with cmake

# Project Structure

    build                      <--- Containing Binary and Executable file for runtime. 
        program.exe                       
    
    src                        <--- Containing sources file for the project including .cpp .c .h file.
        core          *contain core system for the project (Game Engine, Actor,).
            *.h
            *.cpp
        components    *contain actor's components for the project.
            componentA
                *.h
                *.cpp
            componentB
                *.h
                *.cpp
        static        *contain static system manager source code for the project.
            systemA
                *.h
                *.cpp
            systemB
                *.h
                *.cpp
        ui            *contain ui manager source code for the project.
            *.h
            *.cpp   
        master.cpp    *contain main function for the project.
        ...


    assets                           <--- Containing resources for appplication such as image icon and audio file.
        fonts
            .ttf ...
        imgs
            .png ...
            .jpg ...
        icon    
            .svg ...
        auds
            .mp3 ...
        anims 
            .mp4 ...
            .gif ...
        sprites
            name
            .png ...
            .jpg ...

# Prerequisite
    You have to install GNU compiler collection and CMake to build and run the project.
    ```
        sudo apt install build-essential cmake
    ```

# Installing necessary SDL2 and its additional library for the project.
    Run this following command on the terminal to install the SDL2 Library on Debian-Based OS such as Ubuntu,  and so on.
    ```
        sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev
    ```

# Checking the installed library on the system-wide.
    Run the following command in the terminal to check the installed library on the system-wide.
    ```
        pkg-config --libs sdl2
        pkg-config --libs SDL2_mixer
        pkg-config --libs SDL2_ttf
        pkg-config --libs SDL2_image
    ```

# About CMakeLists.txt
    The Cmake file is contained in the root of the project and it ready to use.
    If you want to add additional library to the project, you can add it to the CMakeLists.txt file.
    There are comment in the file to guide you to add the library and set it up.

# Step to Build and Run the project using cmake.

    1. Open the terminal in the project directory.

    2. Run the following command to build the cmake for the project.
        ```
            cmake -S . -B build
        ```
    3. Run the following command to compile the project using builded cmake folder.
        ```
            cmake --build build
        ```
    4. Run the following command to Execute the project.
        ```
            ./build/program.exe
        ```

# How to clean the project

    Run the following command to clean the project.
    ```
        cmake --build build --config Release --target clean
    ```

# Executing command executor file
    To execute the cMake command easily and quickly, you can use the command executor file to automatically compile, build and execute the project.

    If not compiled the executor file, run the following command to compile the executor file.
    ```
        cd commands
        gcc -o executor executor.c
    ```
    Execute the command executor file.
    ```
        ./executor
    ```

