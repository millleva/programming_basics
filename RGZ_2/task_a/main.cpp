#include <iostream>
#include <vector>
#include <string>

#include "cipher.h" 

using namespace std;

#define ARGS_NUM 4
#define USAGE_MSG ":USAGE: exe [encipher|decipher] input bits output"

bool cliArgsValid(char** argv){
    string mode = argv[1];
    
    if(mode != "encipher" && mode != "decipher"){
        cout << "Mode can be encipher or decipher" << endl;
        return false;
    }

    return false;
}

int main(int argc, char** argv)
{
    // if(argc != ARGS_NUM || !cliArgsValid(argv)){
    //     cout << USAGE_MSG << endl;
    //     return 1;
    // }

    cliArgsValid(argv);

    // encipherFileToOtherFile(
    //     "data/numbers_input.txt",
    //     "data/bits_exchange.txt",
    //     "data/numbers_output.txt"
    // );

    // decipherFileToOtherFile(
    //     "data/numbers_output.txt",
    //     "data/bits_exchange.txt",
    //     "data/numbers_deciphered.txt"
    // );

    return 0;
}