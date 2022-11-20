#include <iostream>

using namespace std;

int main()
{
    int mySize = 5;
    int myMatrix[mySize][mySize] = {
        {1, 2, 3, 4, 5},
        {2, 1, 8, 9, 4},
        {3, 8, 1, 4, 3},
        {4, 9, 4, 1, 2},
        {5, 4, 3, 2, 1}
    };

    bool isSymmMainDiag = true;
    for(int row = 1; row < mySize; row++)
        for(int col = 0; col < row; col++)
            if(myMatrix[row][col] != myMatrix[col][row])
                isSymmMainDiag = false;

    cout << boolalpha;
    cout << "Matrix is symmetric by main diagonale: " << isSymmMainDiag << endl;




    int my2Matr[mySize][mySize] = {
        {5, 4, 3, 2, 1},
        {4, 3, 2, 1, 2},
        {3, 2, 1, 2, 3},
        {2, 1, 2, 3, 4},
        {1, 2, 3, 4, 5}
    };

    bool isSymmSecondDiag = true;
    for(int row = 0; row < mySize-1; row++)
        for(int col = 0; col < mySize-1-row; col++)
            if(my2Matr[row][col] != my2Matr[col][row])
                isSymmSecondDiag = false;

    cout << "Second matrix is symmetric by second diagonale: " << isSymmSecondDiag << endl;

    return 0;
}

/*bool checkSymmMainDiag(int[][] matrix, int mSize)
{
    for(int row = 1; row < mSize; row++)
        for(int col = 0; col < row; col++)
            if(matrix[row][col] != matrix[col][row])
                return false;
    return true;
}*/

    // check symmetric main diagonale
    /*for(int row = 1; row < mySize; row++){
        for(int col = 0; col < row; col++){
            if(myMatrix[row][col] != myMatrix[col][row]){}
        }
    }*/
