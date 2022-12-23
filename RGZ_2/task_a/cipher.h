#include <iostream>
#include <string>
#include <vector>

#ifndef CIPHER_H
#define CIPHER_H

// STRUCTS
//Binary number as string and as vector
struct BinaryNum{
    std::string repr;
    std::vector<int> bitVector;

    void printBitVector(){
        for(auto ch : bitVector){
            std::cout << ch << ' ';
        }
        std::cout << std::endl;
    }

    void printRepr(){
        std::cout << repr << std::endl;
    }

    void updateReprFromBitVector(){
        repr = "";
        for(int index = bitVector.size() - 1; index >= 0; index--){
            repr += std::to_string(bitVector[index]);
        }
    }

    void swapBits(int a, int b){
        if(a > bitVector.size()-1 || b > bitVector.size()-1) return;
        int temp = bitVector[a];
        bitVector[a] = bitVector[b];
        bitVector[b] = temp;
        updateReprFromBitVector();
    }
};

BinaryNum createBinaryNumFromDec(int decimal);
std::string intToBin(int n);
std::vector<int> bitVectorFromString(std::string binary);

// Bit pairs for exchange
struct IntPair{
    int first;
    int second;

    void printPair(){
        std::cout << first << ' ' << second << std::endl;
    }
};

IntPair castLineToIntPair(std::string line);

// Ciphering
std::vector<int> readIntsFromFileName(std::string srcName);
std::vector<IntPair> readBitPairsFromFileName(std::string bitsFile);
void writeBinaryNumsToFileName(std::string destName, std::vector<BinaryNum> binaryNums);
void encipherFileToOtherFile(std::string srcName, std::string bitsFile, std::string destName);

//Deciphering
std::vector<BinaryNum> readBinaryNumsFromFileName(std::string srcName);
int binToInt(BinaryNum binaryNum);
void writeIntNumsToFile(std::string destName, std::vector<int> intNums);
void decipherFileToOtherFile(std::string srcName, std::string bitsFile, std::string destName);

#endif 