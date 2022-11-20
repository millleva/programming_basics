#include <iostream>
#include <string.h>

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

    char * currWord = strtok(myStr, " ");
    strcpy(resultStr, currWord);
    currWord = strtok(NULL, " ");
    while(currWord != NULL){
        strcat(resultStr, " ");
        strcat(resultStr, currWord);
        currWord = strtok(NULL, " ");
    }

    cout << "String without extra spaces: " << resultStr << endl;

    return 0;
}
