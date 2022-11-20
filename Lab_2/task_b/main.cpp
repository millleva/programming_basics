#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    int sum = 0;
    for (int num = a; num <= b; num += 1){
        if (num % 2 == 0) {
            sum += num*num;
            cout << " + " << num << "^2";
        } else {
            sum += num*num*num;
            cout << " + " << num << "^3";
        }
    }
    cout << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
