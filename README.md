## SCN2CSV
 SCN2CSV is a basic C++ script that converts the .scn files output by Camspec's K3 software into comma separated value files.

### Why make this?
K3's built-in Excel exporter is less than reliable and this way you can easily convert your scn files into a format that can be painlessly opened by Excel without manually modifying the files or setting up the import data wizzard.

### How to run?
If you download the compiled binaries from the releases folders, just type `scn2csv file.scn` and a csv of the same name will appear in that folder

### What platforms and compilers does it support?
In theory? All of them since it only employs the C++ standard library and no platform specific libraries, I have tested it on Windows 11 with MSVC and Fedora 34 with g++ sucessfully, try compiling it on other platforms and compilers at your own risk.

### How to compile the file?
```bash
#With MSVC:
cl.exe scn2csv.cpp /EHsc

#With g++:
g++ ./scn2scv.cpp -o scn2csv
```