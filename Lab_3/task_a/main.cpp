#include <iostream>

using namespace std;

int main(){


    int prev, curr, next;
    int mySize;
    cout << "Enter a size: ";
    cin >> mySize;
    int myArray[mySize];
    for(int index = 0; index < mySize; index++){
        cout << "Enter array[" << index << "]: ";
        cin >> myArray[index];
    }

    int amount = 0;

    for(int index = 1; index < mySize-1; index++){
        prev = myArray[index - 1];
        curr = myArray[index];
        next = myArray[index + 1];
        if(curr < prev && curr < next){
            cout << curr << " is less than " << prev << " and " << next << endl;
            amount++;
        }
    }
    cout << "Amount: " << amount << endl;

    return 0;
}

