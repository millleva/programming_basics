#include <iostream>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

using namespace std;

void printMatrix(int** matrix, int rowSize){
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < rowSize; j++){
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

int setCurrNumber(int a, int b, int curr){
    if(curr+1 <= b){
        return curr+1;
    }
    return a;
}

int main()
{
    int a;
    cout << "Enter a: ";
    cin >> a;
    int b;
    cout << "Enter b: ";
    cin >> b;
    int N;
    cout << "Enter N: ";
    cin >> N;
    int** myMatrix = new int*[N];
    for (int i = 0; i < N; i++)
        myMatrix[i] = new int[N];

    bool isFilledMatrix[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            isFilledMatrix[i][j] = false;
        }
    }

    int currNumber = a;
    int currX = 0;
    int currY = 0;
    int cellsAmount = N*N;
    int filledAmount = 0;
    int currDirection = RIGHT;

    while(filledAmount < cellsAmount){
        if(currDirection == RIGHT){
            if(!isFilledMatrix[currX][currY]){
                isFilledMatrix[currX][currY] = true;
                myMatrix[currX][currY] = currNumber;
                currNumber = setCurrNumber(a,b,currNumber);
                if(currY < N-1 && !isFilledMatrix[currX][currY+1]) currY++;
                else {
                    currDirection = DOWN;
                    currX++;
                }
            }
        }
        else if(currDirection == DOWN){
            if(!isFilledMatrix[currX][currY]){
                isFilledMatrix[currX][currY] = true;
                myMatrix[currX][currY] = currNumber;
                currNumber = setCurrNumber(a,b,currNumber);
                if(currX < N-1 && !isFilledMatrix[currX+1][currY]) currX++;
                else{
                    currDirection = LEFT;
                    currY--;
                }
            }
        }
        else if (currDirection == LEFT){
            if(!isFilledMatrix[currX][currY]){
                isFilledMatrix[currX][currY] = true;
                myMatrix[currX][currY] = currNumber;
                currNumber = setCurrNumber(a,b,currNumber);
                if(currY > 0 && !isFilledMatrix[currX][currY-1]) currY--;
                else {
                    currDirection = UP;
                    currX--;
                }
            }
        }
        else if (currDirection == UP){
            if(!isFilledMatrix[currX][currY]){
                isFilledMatrix[currX][currY] = true;
                myMatrix[currX][currY] = currNumber;
                currNumber = setCurrNumber(a,b,currNumber);
                if(currX > 0 && !isFilledMatrix[currX-1][currY]) currX--;
                else {
                    currDirection = RIGHT;
                    currY++;
                }
            }
        }

        filledAmount++;
        printMatrix(myMatrix, N);
        cout << endl;
    }

    //printMatrix(myMatrix, N);
    return 0;
}
/*for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            myMatrix[i][j] = (i + 1)*(j + 1);
        }
    }
*/

//matrix filling
    //1-4
       /* for(int j = 0; j < N; j++){
            int i = 0;
            myMatrix[i][j] = a;
            a++;
        }
        //4-7
        for(int i = 0; i < N; i++){
            int j = N-1;
            myMatrix[i][j] = a-1;
            a++;
        }
        //7-10
        for(int j = N-1; j >= 0; j--){
            int i = N-1;
            myMatrix[i][j] = a-2;
            a++;
        }
        //10-12
        for(int i = N-1; i > 0; i--){
            int j = 0;
            myMatrix[i][j] = a-3;
            a++;
        }

        //12-14
    for(int j = 0; j < N-1; j++){
        int i = 1;
        myMatrix[i][j] = a-4;
        a++;
    }*/



