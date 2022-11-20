#include <iostream>

using namespace std;

int main() {
    double startMember;
    double progressionStep;

    cout << "Enter a start member: ";
    cin >> startMember;

    cout << "Enter a progression step: ";
    cin >> progressionStep;

    double member = startMember;
    while (member < 500) {
       cout << member << endl;
       member *= progressionStep;
    }
    return 0;
}
