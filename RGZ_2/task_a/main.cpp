#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cipher.h" 

using namespace std;

#define ARGS_NUM 4
#define USAGE_MSG ":USAGE: exe [encipher|decipher] input bits output"

bool fileExists(string path){
    ifstream f(path);
    return f.good();
}

bool cliArgvValid(char** argv){
    string mode = argv[1];
    string input = argv[2];
    string bits = argv[3];
    
    if(mode != "encipher" && mode != "decipher"){
        cout << "Mode can be encipher or decipher" << endl;
        return false;
    }

    if(!fileExists(input)){
        cout << "Input file missing" << endl;
        return false;
    }

    if(!fileExists(bits)){
        cout << "Bits file missing" << endl;
        return false;
    }

    return true;
}

bool cliArgcValid(int argc){
    return argc == 1 + ARGS_NUM;
}

int main(int argc, char** argv)
{
    if(!cliArgcValid(argc) || !cliArgvValid(argv)){
        cout << USAGE_MSG << endl;
        return 1;
    }

    return 0;
}