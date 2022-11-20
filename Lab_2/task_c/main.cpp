#include <iostream>
#include <cmath>

using namespace std;

int factorial(int number){
    if (number <= 1) return number;
    else return number * factorial(number - 1);
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    double a;
    int membersAmount = 0;
    double condition1, condition2, power1;
    for(int m = 1; m <= n; m += 1){
        cout << "Enter a[" << m << "]: ";
        cin >> a;

        power1 = (m * 1.0) / 2;
        condition1 = pow(2.0, power1);
        condition2 = factorial(m + 1);

        if (a > condition1 && a < condition2){
            cout << "It's a member  :)" << endl;
            membersAmount += 1;
        }
        else cout << "It's NOT a member  :(" << endl;
        cout << condition1 << " < " << a << " < " << condition2 << endl;
    }
    cout << "Members amount: " << membersAmount << endl;
    return 0;
}






