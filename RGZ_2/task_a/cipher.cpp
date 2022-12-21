#include "cipher.h"

string intToBin(int n){
    string r;
    while(n != 0){
        r = (n % 2 == 0 ? "0" : "1") + r; 
        n /= 2;
    }

    return r;
}

vector<int> bitVectorFromString(string binary){
    vector<int> bits;
    for(int index = binary.size() - 1; index >= 0; index--){
        int bit = binary[index] - '0';
        bits.push_back(bit);
    }

    return bits;
}