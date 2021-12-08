#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string lineSplit(string line, int pos){
    if (line.length() >= 14){
        switch(pos) {
            case 1:
                return line.substr(0,1) + "." + line.substr(1,4);
                break;
            case 2:
                if (line.substr(6,1) == "-"){
                    return line.substr(6,8);
                    break;
                } else {
                    return line.substr(7,7);
                    break;
                }
        }
    }
    return "";
}

int main(int argc, char *argv[]){
    ifstream inFile;
    ofstream outFile;
    string line;
    string filename = argv[1];
    string outname = filename.substr(0, filename.find(".scn")) + ".csv";
    inFile.open(filename, ios::in);
    outFile.open(outname, ios_base::app);
    for(int i = 0;!inFile.eof();i++){
        getline(inFile,line);
        if(i>=6){
            outFile << lineSplit(line,1) << "," + lineSplit(line,2) << "\n";
        }
    }
    cout << filename << "'s data output to: " << outname << "\n";
    return 0;
}


