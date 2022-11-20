#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Enter a: ";
    cin >> a;
    cout << endl;
    int a2 = a * a;
    int a3 = a2 * a;
    int a5 = a3 * a2;
    int a10 = a5 * a5;
    int a13 = a10 * a3;

    cout << "a^5 = " << a5 << endl;
    cout << "a^13 = " << a13 << endl;
    return 0;
}
