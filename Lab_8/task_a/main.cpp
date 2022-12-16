#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool startsWith(string line, string substr){
    return line.rfind(substr, 0) == 0;
}

string trimReplicaSentence(string line){
    int sentenceStartIndex = 0;
    char currChar;
    for(int index = 0; index < line.length(); index++){
        currChar = line[index];
        if(currChar == ' ' || currChar == '-'){
            continue;
        }
        else {
            sentenceStartIndex = index;
            break;
        }
    }
    
    return line.substr(sentenceStartIndex);
}

int main()
{
    ifstream replicasFile;
    replicasFile.open("replicas.txt");
    string fileLine;
    string sentence;
    while(getline(replicasFile, fileLine)){
        if(startsWith(fileLine, "-")){
            sentence = trimReplicaSentence(fileLine);
            cout << sentence << endl;
        }
    }

    replicasFile.close();

    return 0;
}