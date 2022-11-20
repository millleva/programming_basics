#include <iostream>

using namespace std;

int main()
{
    int mySize;
    cout << "Enter a size: ";
    cin >> mySize;
    int* myArray = new int[mySize];
    for(int index = 0; index < mySize; index++){
        cout << "Enter myArray[" << index << "]: ";
        cin >> myArray[index];
    }

    int curr, prev, next;
    int amount = 0;
    for(int* ptr = &myArray[1]; ptr <= &myArray[mySize-2]; ptr++){
        curr = *ptr;
        prev = *(ptr-1);
        next = *(ptr+1);
        if(curr < prev && curr < next){
            cout << curr << " is less than " << prev << " and " << next << endl;
            amount++;
        }
    }
    cout << "Amount: " << amount << endl;

    delete[] myArray;
    return 0;
}


/*int arr[5] = {10, 15, 5, 2, 10}, sum = 0;
    int* ptr;
    for (ptr = &arr[0]; ptr <= &arr[4]; ptr++){
        sum = sum + *ptr;
        cout << ptr << endl;
    }

    cout<<sum; */
