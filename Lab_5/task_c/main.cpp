#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <cfloat>

using namespace std;

//MATHS
double logFromBase(double base, double num){
    return log(num) / log(base);
}

double arithmeticMeanMatrix (double** matrix, int matrSize){
    double arithmeticMean = 0;
    double sum = 0;
    for(int i = 0; i < matrSize; i++){
        for(int j = 0; j < matrSize; j++){
            sum += matrix[i][j];
        }
    }
    arithmeticMean = sum / pow(matrSize, 2);
    return arithmeticMean;
}

double roundTo (double value, double precision){
    return round(value / precision) * precision;
}
//MATHS


//MATRIX
double** initMatrix (int matrSize){
    double** matrix = new double*[matrSize];
    for(int i = 0; i < matrSize; i++)
        matrix[i] = new double[matrSize];
    return matrix;
}

double calculateMatrixElement(int i, int j){
    double numerator = pow(logFromBase(5, (i*i + j*j)), 2) - pow(M_E, M_E);
    double denominator = pow(3.7, i) - 0.5*pow(i, 2);
    double a = numerator / denominator;
    return a;
}

void fillMatrix (double** matrix, int matrSize){
    for(int i = 0; i < matrSize; i++){
        for(int j = 0; j < matrSize; j++){
            matrix[i][j] = calculateMatrixElement(i+1, j+1);
        }
    }
}

void printMatrix(double** matrix, int rowSize){
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < rowSize; j++){
            cout << roundTo(matrix[i][j], 0.0001) << '\t';
        }
        cout << endl;
    }
}

void cleanUpMatrix (double** matrix, int matrSize){
    for(int i = 0; i < matrSize; i++)
        delete[] matrix[i];
    delete[] matrix;
}
//MATRIX

//VECTOR
int colNumCloseToMean (double** matrix, int matrSize){
    double arithmeticMean = arithmeticMeanMatrix(matrix, matrSize);
    double currNum;
    double minDifference = DBL_MAX;
    int minColNum = 0;
    double currDifference;
    for(int row = 0; row < matrSize; row++){
        for(int col = 0; col < matrSize; col++){
            currNum = matrix[row][col];
            currDifference = abs(currNum - arithmeticMean);
            if(currDifference < minDifference){
                minDifference = currDifference;
                minColNum = col;
            }
        }
    }
    return minColNum;
}

double* getVectorX (double** matrix, int matrSize){
    double* vectorX = new double[matrSize];
    int colNum = colNumCloseToMean(matrix, matrSize);
    for(int i = 0; i < matrSize; i++){
        vectorX[i] = matrix[i][colNum];
    }
    return vectorX;
}

void printVector (double* vec, int vecSize){
    for(int i = 0; i < vecSize; i++){
        cout << roundTo(vec[i], 0.0001) << "    ";
    }
    cout << endl;
}

void cleanUpVector (double* vec){
    delete[] vec;
}
//VECTOR

//G
double calculateG (double* vectorX, int vectorLength){
    double sum = 0;
    double addendum;
    double product;
    for(int q = 0; q < vectorLength; q++){
       product = 1;
       for(int k = 0; k <= q; k++){
            product *= (vectorX[k] / M_E);
       }
       addendum = vectorX[q] + product;
       sum += addendum;
    }
    double G = sqrt(abs(sum));
    return G;
}
//G

int main()
{
    int N;
    cout << "Enter a size of matrix: ";
    cin >> N;
    cout << endl;

    double** matrix = initMatrix(N);
    fillMatrix(matrix, N);

    cout << "Matrix: " << endl;
    printMatrix(matrix, N);
    cout << endl;

    cout << "Arithmetic mean: " << arithmeticMeanMatrix(matrix, N) << endl;

    cout << "Column number: " << colNumCloseToMean(matrix, N) << endl;

    double* vectorX = getVectorX(matrix, N);
    cout << "Vector X: ";
    printVector(vectorX, N);

    cout << "G: " << calculateG(vectorX, N) << endl;

    cleanUpMatrix(matrix, N);
    cleanUpVector(vectorX);
    return 0;
}
