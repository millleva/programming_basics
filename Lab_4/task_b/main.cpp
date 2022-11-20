#include <iostream>
#include <string>

using namespace std;

#define WORD_OUT 0
#define WORD_IN 1

int main()
{
    string givenStr;
    cout << "Enter a string: ";
    getline(cin, givenStr);
    int state = WORD_OUT;
    int wordCounter = 0;

    for(auto ch : givenStr){
        if(ch == ' ' || ch == ',' || ch == '!' || ch == '.' ||
        ch == '-' || ch == '?' || ch == ';' || ch == ':')
           state = WORD_OUT;
        else if(state == WORD_OUT){
            state = WORD_IN;
            wordCounter++;
        }
    }

    cout << "Number of words: " << wordCounter << endl;

    return 0;
}


/*bool isPunctuation(char ch) {
    char punctSymbols[] = {' ', ',', '!', '.', '-', '?', ';', ':'};
    for (auto punct : punctSymbols)
        if (punct == ch) return true;
    return false;
}*/
