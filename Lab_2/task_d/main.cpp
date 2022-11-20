#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int factorial(int number){
    if (number <= 1) return number;
    else return number * factorial(number - 1);
}

int main()
{
    int n;
    double x;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;

    double sum = 1;
    double currentMember;
    double angleMultiplier = 0.25;
    double angle = M_PI * angleMultiplier;
    cout << "Expression: " << sum << " ";
    for(int counter = 1; counter < n; counter += 1){
        cout << "+ [cos(pi*" << angleMultiplier <<
        ") * " << x << "^" << counter << " / " << counter << "!] ";
        currentMember = cos(angle) * pow(x, counter) / factorial(counter);
        sum += currentMember;
        angle *= 2;
        angleMultiplier *= 2;
    }
    cout << endl;
    cout << "SUM: " << sum << endl;

    return 0;
}
