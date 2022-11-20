#include <iostream>
#include <string>

using namespace std;

int main()
{
    string myString;
    cout << "Enter a string: ";
    getline(cin, myString);
    int stringLength = myString.length();
    string searchResult;

    bool isDashAfterComma = false;
    int commaIndex = 0;
    for(int index = 0; index < stringLength; index++){
        isDashAfterComma = false;
        if(myString[index] == ','){
            for(int currIndex = index + 1; currIndex < stringLength; currIndex++){
                if(myString[currIndex] == '-'){
                    isDashAfterComma = true;
                    break;
                }
                else if(myString[currIndex] == ' ') continue;
                else {
                    isDashAfterComma = false;
                    break;
                }
            }
        }
        if (isDashAfterComma) {
            commaIndex = index;
            break;
        }
    }

    cout << "Comma index: " << commaIndex << endl;
    searchResult = myString.substr(0, commaIndex);
    cout << "String before comma which is before dash: " << searchResult << endl;

    return 0;
}
