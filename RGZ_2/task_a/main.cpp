#include <iostream>

#include "cipher.h" 

using namespace std;

int main()
{
    BinaryNum b = createBinaryNumFromDec(11);
    b.printBitVector();
    b.printRepr();

    return 0;
}