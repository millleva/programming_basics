#include <iostream>
#include <string>
#include <vector>

#ifndef CIPHER_H
#define CIPHER_H

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
        int temp = bitVector[a];
        bitVector[a] = bitVector[b];
        bitVector[b] = temp;
        updateReprFromBitVector();
    }
    
};

BinaryNum createBinaryNumFromDec(int decimal);

std::string intToBin(int n);

std::vector<int> bitVectorFromString(std::string binary);

#endif 