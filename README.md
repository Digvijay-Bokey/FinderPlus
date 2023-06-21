# FinderPlus

FinderPlus is a lightweight file explorer application built with the Qt framework. This application allows you to navigate your file system with a user-friendly interface.

## Features

- Browse files and directories.
- Navigate directly into directories by clicking on them.
- View detailed file information such as name and creation date.

## Requirements

- Qt 5 or newer
- CMake 3.17 or newer

## Building the Application

### Using Command Line (Linux/Mac)

1. Open a terminal and navigate to the project directory.
2. Create a build directory: `mkdir build && cd build`.
3. Generate the build files: `cmake ..`.
4. Build the project: `make`.

### Using Qt Creator

1. Open the project in Qt Creator.
2. Configure the project to use your desired kit.
3. Click the "Build" button or use the `Ctrl+B` shortcut to build the project.

## Running the Application

### Using Command Line (Linux/Mac)

1. From the build directory, run the application: `./fileExplorer`.

### Using Qt Creator

1. After building the project, click the "Run" button or use the `Ctrl+R` shortcut to start the application.

## Notes

At this point, the application allows navigation into directories by clicking the "Open" button next to each directory. The application starts in the home directory of the current user. The "Back" button functionality is not yet implemented in this version.
