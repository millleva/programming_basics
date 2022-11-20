#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number from 1 to 100: ";
    cin >> num;
    int signCount;
    if (num/100 == 1) signCount = 3;
    else if (num/10 > 0) signCount = 2;
    else signCount = 1;
    cout << signCount << endl;
    return 0;
}
