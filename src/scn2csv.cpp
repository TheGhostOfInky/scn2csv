#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

struct dataSet {
    string wl;
    string abs;
};

struct dataSet parseLine(string line) {
    struct dataSet ret;
    if (line.length() >13) {
        ret.wl = line.substr(0,4) + "." + line.substr(4,1);
        ret.abs = line.substr(6,8);
    } else {
        ret.wl = "";
        ret.abs = "";
    }
    return ret;
}


int main(int argc,char *argv[]) {
    string path;
    if(argc > 1) {
        path = string(argv[1]);
    } else {
        cout << "No path specified" << endl;
        return 1;
    }
    unordered_map<string,unordered_map<string,string>> collection;
    string line, key;
    for(const auto & entry : filesystem::directory_iterator(path) ) {
        if(entry.path().extension() == ".scn" ) {
            ifstream inFile;
            unordered_map<string,string> parsedFile;
            inFile.open(entry.path(), ios::in);
            for(int n=0;!inFile.eof();n++) {
                getline(inFile,line);
                if(!n) key = line;
                if(n<6) continue;
                struct dataSet values = parseLine(line);
                if(values.wl != "") {
                    parsedFile[values.wl] = values.abs;
                }
            }
            collection[key] = parsedFile;
        }
    }
    if(collection.empty()) {
        cout << "no .scn files found in the path" << endl;
        return 1;
    }
    vector<string> mapkeys;
    vector<string> wls;
    string outfile = "wl(nm),";
    for(const auto& mapkey: collection) {
        mapkeys.push_back(mapkey.first);
        outfile += mapkey.first + ",";
    }
    outfile += "\n";

    for(const auto& wl: collection[mapkeys[0]]) {
        wls.push_back(wl.first);
    }
    sort(wls.begin(),wls.end());

    for(string i: wls) {
        outfile += i + ",";
        for(string j: mapkeys) {
            outfile += collection[j][i] + ",";
        }
        outfile += "\n";
    }
    ofstream output;
    output.open("./join.csv",ios_base::app);
    output << outfile;
    output.close();
}