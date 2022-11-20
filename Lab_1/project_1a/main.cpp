#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cout << "Enter x: ";
    cin >> x;

    int y;
    cout << "Enter y: ";
    cin >> y;

    int z;
    cout << "Enter z: ";
    cin >> z;

    float A = (x + y + z)/3;
    cout << "Arithmetic mean = " << A << endl;

    float G = cbrt(x*y*z);
    cout << "Geometric mean = " << G << endl;

    return 0;
}
