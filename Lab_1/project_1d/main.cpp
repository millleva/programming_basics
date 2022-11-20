#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double pi = 3.14159265358979323846;

    double functionValue;

    double num;
    cout << "Enter a number: ";
    cin >> num;

    if (num >= 0 && num <= pi) functionValue = sin(num);
    else functionValue = 1;
    cout << "f(x)= " << functionValue << endl;
    return 0;
}
