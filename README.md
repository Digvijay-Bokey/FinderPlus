# Finder Plus

Finder Plus is an advanced file explorer built using the Qt framework. This application provides a user-friendly interface for navigating through your file system, focusing on usability and simplicity.

## Features

- Navigate through directories: Click on a directory to navigate into it. The path of the current directory is displayed at the bottom of the window.
- Go back and forth: Use the back and forward arrows at the bottom left of the window to navigate through your directory history.
- Grid layout: Files and directories are displayed in a grid layout, with file names and creation dates displayed under the file icons. 

## Building

Finder Plus is built using CMake. Make sure you have Qt and Boost installed on your machine. Then you can clone the repository and build the application:

\``bash
git clone https://github.com/yourusername/finderplus.git
cd finderplus
mkdir build && cd build
cmake ..
make
\`

## Running

You can run Finder Plus directly from the build directory:

\``bash
./fileExplorer
\`

## Contributing

There are no guidelines for contributing at the moment. Feel free to open issues if you find any bugs or have any feature requests.

