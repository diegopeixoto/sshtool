
# SSH Tool CLI

This project is a Command-Line Interface (CLI) tool written in C that helps manage SSH connections and configurations. The original implementation was in Python, but it has been converted to C for better portability and performance.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Building the Project](#building-the-project)
- [Cleaning the Build](#cleaning-the-build)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## Features

- Initialize and manage SSH configurations.
- Add, remove, and connect to hosts.
- Add and remove users and keys.
- Advanced operations like nuking the database.

## Requirements

- GCC (GNU Compiler Collection)
- Make
- pkg-config
- json-c library

On macOS, you can install these dependencies using Homebrew:

```sh
brew install gcc make pkg-config json-c
```

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/diegopeixoto/sshtool.git
cd sshtool
```

## Usage

To compile and use the SSH Tool CLI, follow these steps:

1. **Build the Project**: Use the provided `compile.sh` script to compile the project. This script will ensure the necessary include and library paths for `json-c` are set correctly.

```sh
./compile.sh
```

2. **Run the CLI Tool**: Once compiled, you can run the `sshtool` executable:

```sh
./sshtool
```

## Building the Project

The project uses a `Makefile` for building. If you prefer to use `make`, you can run:

```sh
make
```

### Makefile

The `Makefile` is configured to use `pkg-config` to dynamically determine the include and library paths for `json-c`, making it more portable and flexible.

### compile.sh

The `compile.sh` script is designed to:

- Clean previous build files.
- Compile the source files.
- Link the object files into the final executable.

The script also checks for `pkg-config` and uses it to find `json-c` paths if available.

## Cleaning the Build

To clean the build files, use the following command:

```sh
make clean
```

Or, if you are using `compile.sh`:

```sh
./compile.sh clean
```

## Troubleshooting

### Common Issues

- **json-c/json.h file not found**: Ensure that `json-c` is installed and the paths are correctly set. Use `pkg-config` to verify the installation:

```sh
pkg-config --cflags json-c
pkg-config --libs json-c
```

- **CMake Issues**: If you are using CLion or another IDE that requires `CMakeLists.txt`, ensure you have a valid CMake configuration. This project primarily uses `Makefile` for simplicity.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
