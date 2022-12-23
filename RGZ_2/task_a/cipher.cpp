#include <fstream>
#include <sstream>
#include <cmath>

#include "cipher.h"

using namespace std;

// Creating binary num
string intToBin(int n){
    string res;
    while(n != 0){
        res = (n % 2 == 0 ? "0" : "1") + res; 
        n /= 2;
    }

    return res;
}

vector<int> bitVectorFromString(string binary){
    vector<int> bits;
    for(int index = binary.size() - 1; index >= 0; index--){
        int bit = binary[index] - '0';
        bits.push_back(bit);
    }

    return bits;
}

BinaryNum createBinaryNumFromDec(int decimal){
    string repr = intToBin(decimal);
    vector<int> bits = bitVectorFromString(repr);
    BinaryNum b = {repr, bits};

    return b;
}

// Ciphering
vector<int> readIntsFromFileName(string srcName){
    ifstream file;
    file.open(srcName);
    vector<int> numbers;
    string line;
    while(getline(file, line)){
        numbers.push_back(stoi(line));
    }

    file.close();
    return numbers;
}

IntPair castLineToIntPair(string line){
    stringstream ss(line);
    string buf;
    vector<int> bits;
    while(getline(ss, buf, ' ')){
        bits.push_back(stoi(buf));
    }
    IntPair pair = {0,0};
    if(bits.size() < 2) return pair;
    pair.first = bits[0];
    pair.second = bits[1];

    return pair;
}

vector<IntPair> readBitPairsFromFileName(string bitsFile){
    ifstream file;
    file.open(bitsFile);
    vector<IntPair> bitPairs;
    string line;
    while(getline(file, line)){
        bitPairs.push_back(castLineToIntPair(line));
    }

    file.close();
    return bitPairs;
}

void writeBinaryNumsToFileName(string destName, vector<BinaryNum> binaryNums){
    ofstream file;
    file.open(destName);
    for(auto binaryNum : binaryNums){
        file << binaryNum.repr << endl;
    }

    file.close();
}

void encipherFileToOtherFile(string srcName, string bitsFile, string destName){
    vector<int> numbers = readIntsFromFileName(srcName);
    vector<BinaryNum> binaryNums;
    for(auto num : numbers){
        binaryNums.push_back(createBinaryNumFromDec(num));
    }
    vector<IntPair> bitPairs = readBitPairsFromFileName(bitsFile);

    for(int index = 0; index < binaryNums.size(); index++){
        for(auto pair:bitPairs){
            binaryNums[index].swapBits(pair.first, pair.second);
        }
    }

    writeBinaryNumsToFileName(destName, binaryNums);
}

//Deciphering
vector<BinaryNum> readBinaryNumsFromFileName(string srcName){
    vector<BinaryNum> binaryNums;
    ifstream file;
    file.open(srcName);
    string line;
    while(getline(file, line)){
        vector<int> bitVector = bitVectorFromString(line);
        BinaryNum binaryNum = {line, bitVector};
        binaryNums.push_back(binaryNum);
    }

    file.close();
    return binaryNums;
} 

int binToInt(BinaryNum binaryNum){
    int result = 0;
    for(int index = 0; index < binaryNum.bitVector.size(); index++){
        if(binaryNum.bitVector[index] == 1){
            result += pow(2, index);
        }
    } 

    return result;
}

void writeIntNumsToFile(string destName, vector<int> intNums){
    ofstream file;
    file.open(destName);
    for(auto intNum : intNums){
        file << intNum << endl;
    }

    file.close();
}

void decipherFileToOtherFile(string srcName, string bitsFile, string destName){
    vector<BinaryNum> binaryNums = readBinaryNumsFromFileName(srcName);
    vector<IntPair> bitPairs = readBitPairsFromFileName(bitsFile);

    for(int index = 0; index < binaryNums.size(); index++){
        for(auto pair:bitPairs){
            binaryNums[index].swapBits(pair.first, pair.second);
        }
    }

    vector<int> decimals;
    for(auto binaryNum : binaryNums){
        int decimal = binToInt(binaryNum);
        decimals.push_back(decimal);
    }

    writeIntNumsToFile(destName, decimals);
}


