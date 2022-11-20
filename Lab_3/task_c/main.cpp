#include <iostream>

using namespace std;

int main()
{
    int rows;
    int cols;
    cout << "Enter a number of rows: ";
    cin >> rows;
    cout << "Enter a number of cols: ";
    cin >> cols;

    int** myMatrix = new int*[rows];
    for(int row = 0; row < rows; row++)
        myMatrix[row] = new int[cols];
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cout << "Enter myMatrix[" << row << "][" << col << "]: ";
            cin >> myMatrix[row][col];
        }
    }


    // mean arithmetic
    cout << "|| Mean for every row ||" << endl;
    double mean;
    double rowSum;
    for(int row = 0; row < rows; row++){
        rowSum = 0;
        for(int col = 0; col < cols; col++){
            rowSum += myMatrix[row][col];
        }
        mean = rowSum / cols;
        cout << "Mean for row " << row << " = " << mean << endl;
    }

    // max and min for every col
    cout << "|| Max and min for every col ||" << endl;
    int maxInCol, minInCol, curr;
    for(int col = 0; col < cols; col++){
        maxInCol = minInCol = myMatrix[0][col];
        for(int row = 0; row < rows; row++){
            curr = myMatrix[row][col];
            if(curr > maxInCol) maxInCol = curr;
            if(curr < minInCol) minInCol = curr;
        }
        cout << "Maximum in col[" << col << "]: " << maxInCol << endl;
        cout << "Minimum in col[" << col << "]: " << minInCol << endl;
    }

    for(int row = 0; row < rows; row++)
        delete[] myMatrix[row];
    delete[] myMatrix;


    return 0;
}

/*
    cout << "|| Max and min for every col ||" << endl;
    int maxInCol, minInCol, curr1, curr2;
    for(int col = 0; col < cols; col++){
        minInCol = myMatrix[0][col];
        for(int row = 0; row < rows; row++){
            curr1 = myMatrix[row][col];
            if(curr1 < minInCol) minInCol = curr1;
        }
        cout << "Minimal in col[" << col << "]: " << minInCol << endl;
   }
    for(int col = 0; col < cols; col++){
        maxInCol = myMatrix[0][col];
        for(int row = 0 ; row < rows; row++){
            curr2 = myMatrix[row][col];
            if(curr2 > maxInCol) maxInCol = curr2;
        }
        cout << "Maximum in col[" << col << "]: " << maxInCol << endl;
   }
   */
