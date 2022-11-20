#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int mySize;
    cout << "Enter a size: ";
    cin >> mySize;

    int myMatrix[mySize][mySize];
    for(int i = 0; i < mySize; i++){
        for(int j = 0; j < mySize; j++){
            cout << "Enter matrix[" << i << "][" << j << "]: ";
            cin >> myMatrix[i][j];
        }
    }

    int maxOnMain = myMatrix[0][0];
    int curr;
    for(int index = 0; index < mySize; index++){
        curr = myMatrix[index][index];
        if(curr > maxOnMain) maxOnMain = curr;
    }
    cout << "Maximum on main: "<< maxOnMain << endl;

    int minOnSecond = myMatrix[mySize-1][0];
    for (int index = 0; index < mySize; index ++){
        curr = myMatrix[mySize-1-index][index];
        if (curr < minOnSecond) minOnSecond = curr;
    }
    cout << "Minimal on secondary: " << minOnSecond << endl;

    int module = abs(maxOnMain - minOnSecond);
    cout << "Module: " << module << endl;
    return 0;
}
