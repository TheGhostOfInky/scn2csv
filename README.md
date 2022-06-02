## SCN2CSV
 SCN2CSV is a basic C++ script that converts and joins the .scn files output by Camspec's K3 software into comma separated value files.

### Why make this?
K3's built-in Excel exporter is less than reliable and this way you can easily convert your scn files into a format that can be painlessly opened by Excel without manually modifying the files or setting up the import data wizzard.

### How to run?
If you download the compiled binaries from the releases folders, just type `scn2csv <folderpath>` and all scn files in that folder will be combined into a CSV file, for example `scn2csv .` will combine all files in the current folder.

### What platforms and compilers does it support?
In theory? All of them since it only employs the C++17 standard library and no platform specific libraries, I have tested it on Windows 11 with both MSVC 19.32.31329 and Clang 14.0.4 and Fedora 36 with both gcc(g++) 12.1.1 and Clang 14.0.0, sucessfully, try compiling it on other platforms and compilers at your own risk.

### How to compile the file?
The makefile includes basic compilation scripts for all 4 configurations tested.
 - For MSVC open a Visual Studio developer cmd/powershell window, create a bin folder in the project root and run `make msvc`
 - For Clang under windows open a cmd/powershell window with clang binaries on path, create a bin folder in the project root and run `make clang-win`
 - For GCC under POSIX systems open a terminal shell on the folder and run `make createbin && make gcc`
 - For Clang under POSIX systems open a terminal shell on the folder and run `make createbin && make clang`

In case you don't have make installed you can compile the files by running the commands listed on the makefile with `$(base)` replaced with `scn2csv` and `$(target)` with `scn2csv.cpp`