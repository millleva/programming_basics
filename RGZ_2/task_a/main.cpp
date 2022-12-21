#include <iostream>

#include "cipher.h" 

using namespace std;

void printVector(vector<int> vec){
    for(auto ch : vec){
        cout << ch << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> bits = bitVectorFromString("1011");
    printVector(bits);

    return 0;
}