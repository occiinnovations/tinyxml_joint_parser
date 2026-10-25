# C++ URDF Joint Parser

A C++ program that uses TinyXML2 to parse a URDF file and extract joint data.

For TinyXML Documentation, visit their official [GitHub](https://github.com/leethomason/tinyxml2).

## Features

* Prompts the user for the path to a URDF file.
* Counts the total number of joints and links.
* Extracts raw string attributes (`xyz` axis, parent/child links, origin offsets, and limits) and converts them into numerical `double` variables.

## File Directory

```text
cpp_urdf_parser/
│
├── external/                 
│   ├── tinyxml2.cpp
│   └── tinyxml2.h
│
├── src/
│   ├── main.cpp
│   └── puma.urdf   <- Included for Sample
│
├─ .gitignore
├─ CMakeLists.txt
├─ LICENSE
└─ README.md
```

## How to Build and Run

Open PowerShell in the project root folder and run:

```powershell
cmake --build build --config Debug; .\build\Debug\urdf_parser.exe
```

When prompted, enter the path to your URDF file.
