#include <iostream>

#include "cipher.h" 

using namespace std;

int main()
{
    encipherFileToOtherFile(
        "data/numbers_input.txt",
        "data/bits_exchange.txt",
        ""
    );

    return 0;
}