@echo off
REM Check if CMake is installed
cmake --version >nul 2>&1
if %errorlevel% neq 0 (
    echo CMake is not installed. Please install CMake.
    exit /b 1
)

REM Check if GCC is installed
gcc --version >nul 2>&1
if %errorlevel% neq 0 (
    echo GCC is not installed. Please install GCC.
    exit /b 1
)

REM Clean previous build
if exist build (
    rmdir /s /q build
)

REM Generate and build
cmake -B build
cmake --build build
