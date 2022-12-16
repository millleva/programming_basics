#include <iostream>

using namespace std;

bool isPrime (int num){
    if(num <= 1) return false;
    for(int curr = 2; curr < num; curr++){
        if(num % curr == 0) return false;
    }
    return true;
}

void printPrimesBetween (int lower, int upper){
    if(lower > upper) return;
    for(int curr = lower; curr <= upper; curr++){
        if(isPrime(curr)) cout << curr << ' ';
    }
    cout << endl;
}

int main()
{
    int lower;
    cout << "Enter lower border: ";
    cin >> lower;
    int upper;
    cout << "Enter upper border: ";
    cin >> upper;

    cout << "Primes: ";
    printPrimesBetween(lower, upper);

    return 0;
}
