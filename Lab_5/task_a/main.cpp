#include <iostream>
#include <cmath>

using namespace std;

int factorial (int i){
    if (i <= 1) return 1;
    else return i * factorial(i-1);
}

double fNumerator (double a, double b){
    double sum = 0;
    double addendum;
    for(int i = 0; i <= 5; i++){
        addendum = (pow(a, i) - pow(b, i)) / factorial(i);
        sum += addendum;
    }
    return sum;
}

double fDenominator (double a, double b){
    double sum = 0;
    double addendum;
    for(int i = 1; i <= 7; i++){
        addendum = (3 * pow(a, 3*i) + 4 * pow(b, 2*i)) / pow(i, 2);
        sum += addendum;
    }
    return sum;
}

double f (double a, double b){
    return fNumerator(a, b) / fDenominator(a, b);
}

double calculateExpression (double x, double y){
    double firstAddendum = (0.5 * f(x, y)) / f(0, y);
    double secondAddendum = f(0.5*x, x+y) / f(x, 0);
    return firstAddendum + secondAddendum;
}

int main()
{
    double x;
    double y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    double result = calculateExpression(x, y);
    cout << "Result: " << result << endl;

    return 0;
}
