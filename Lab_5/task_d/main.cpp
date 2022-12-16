#include <iostream>
#include <climits>

using namespace std;

void printReverseString (string myString, int index = INT_MAX){
    if(index == -1) return;
    else if(index == INT_MAX){
        int lastSymbolIndex = myString.length()-1;
        printReverseString(myString, lastSymbolIndex);
    }
    else {
        cout << myString[index];
        printReverseString(myString, index-1);
    }
}

int main()
{
    string myString;
    cout << "Enter a string: ";
    getline(cin, myString);
    cout << "Reverse string: ";
    printReverseString(myString);
    cout << endl;

    return 0;
}
