#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int mySize = 4;
    int myArray[mySize][mySize] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int* startPtr = &myArray[0][0];
    int currMain;
    int maxMain = *startPtr;
    for(int row = 0; row < mySize; row++){
        currMain = *(startPtr + (mySize*row + row));
        if(currMain > maxMain) maxMain = currMain;
    }

    cout << "Max on main: " << maxMain << endl;

    int* secondPtr = &myArray[0][0];
    int currSecond;
    int minSecond = myArray[mySize-1][0];
    for(int row = 0; row < mySize; row++){
        currSecond = *(secondPtr +(mySize-1-row)*mySize + row);
        if(currSecond < minSecond) minSecond = currSecond;
    }

    cout << "Min on second: " << minSecond << endl;

    int module = abs(maxMain - minSecond);
    cout << "Module: " << module << endl;

    return 0;
}
