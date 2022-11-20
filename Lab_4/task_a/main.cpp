#include <iostream>

using namespace std;

int main()
{
    int mySize = 0;
    cout << "Enter a size: ";
    cin >> mySize;
    cin.ignore(INT_MAX, '\n');

    char myStr[mySize];
    cout << "Enter a string: ";
    cin.get(myStr, mySize);

    char resultStr[mySize];
    int currResultIndex = 0;

    for(int index = 0; myStr[index] != 0; index++){
        if (index >= 1 && myStr[index] == ' ' && myStr[index-1] == ' ')
            continue;
        resultStr[currResultIndex] = myStr[index];
        currResultIndex++;
    }
    resultStr[currResultIndex] = '\0';
    cout << "String without extra spaces: " << resultStr << endl;

    return 0;
}



/*if(myStr[index] != ' '){
            resultStr[currResultIndex] = myStr[index];
            currResultIndex++;
        }*/
