#include <iostream>

#include "cipher.h" 

using namespace std;

int main()
{
    BinaryNum b = createBinaryNumFromDec(500);
    b.printRepr();

    b.swapBits(0, 1);
    b.printRepr();

    return 0;
}