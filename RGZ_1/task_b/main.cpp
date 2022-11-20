#include <iostream>
#include <climits>

#define BRACKET_OUT 0
#define BRACKET_IN 1

using namespace std;

string getPreparedString(){
    return "hi (hello) ! how) are) you (your friends) ?";
}

int main()
{
    int choice = 0;
    string myText;
    while(choice != 1 && choice != 2){
        cout << "Prepared string - enter 1, your string - enter 2: ";
        cin >> choice;
        cin.ignore(INT_MAX, '\n');
        if(choice == 1){
            myText = getPreparedString();
            cout << myText << endl;
        }
        else if(choice == 2){
            cout << "Enter a string: ";
            getline(cin, myText);
        }
        else cout << "Incorrect input" << endl;
    }
    int stringLength = myText.length();
    char currChar;
    int state = BRACKET_OUT;
    bool isCorrectPlacedBrackets = true;
    int amountExtraOpened = 0;
    bool foundFirstExtraClosed = false;
    int firstExtraClosedIndex;

    for(int index = 0; index < stringLength; index++){
        currChar = myText[index];
        if(state == BRACKET_OUT){
            if(currChar == '('){
                state = BRACKET_IN;
                continue;
            }
            else if(currChar == ')'){
                isCorrectPlacedBrackets = false;
                if(!foundFirstExtraClosed){
                    foundFirstExtraClosed = true;
                    firstExtraClosedIndex = index;
                }
            }
            else continue;
        }
        else if(state == BRACKET_IN){
            if(currChar == ')'){
                state = BRACKET_OUT;
                continue;
            }
            else if(currChar == '('){
                isCorrectPlacedBrackets = false;
                amountExtraOpened++;
            }
            else continue;
        }
    }

    if(state == BRACKET_IN){
        isCorrectPlacedBrackets = false;
        amountExtraOpened++;
    }

    string response = isCorrectPlacedBrackets ? "TAK" : "HI";
    cout << "My response: " << response << endl;
    if(!isCorrectPlacedBrackets){
        if(amountExtraOpened > 0){
            cout << "Amount of extra OPENED brackets: " << amountExtraOpened << endl;
        }
        if(foundFirstExtraClosed){
            cout << "First found extra CLOSED bracket: " << firstExtraClosedIndex << endl;
        }
    }



    return 0;
}
