#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum WordState{
    IN = 1,
    OUT,
};

vector<string> getWordsFromFile(ifstream& file){
    vector<string> words;
    WordState state = WordState::OUT;
    char ch;
    string word = "";
    while(file.get(ch)){
        if(ch == '\n'){
            if(word.length() > 1){
                words.push_back(word);
            }
            words.push_back("\n");
            state = WordState::OUT;
            word = "";
            continue;
        } 
        if(state == WordState::OUT && ch != ' '){
            state = WordState::IN;
            word += ch;
        }
        else if(state == WordState::IN){
            if(ch == ' '){
                if(word.length() > 1){
                    words.push_back(word);
                } 
                word = "";
                state = WordState::OUT;
                
            }
            else word += ch;
        }
    }

    return words;
} 

void printVector(vector<string> vec){
    for(auto el : vec){
        cout << el << ' ';
    }
}

vector<string> getWordsFromFileName(string fileName){
    ifstream file;
    file.open(fileName);
    vector<string> words = getWordsFromFile(file);
    file.close();

    return words;
}

void outputWordsToFileName(vector<string> words, string fileName){
    ofstream file;
    file.open(fileName);

    for(auto word : words){
        file << word;
        if(word != "\n") file << ' ';
    } 

    file.close();
}

void fixSpacesWordsInFile(string fileName){
    vector<string> words = getWordsFromFileName(fileName);
    outputWordsToFileName(words, fileName);
}

int main()
{
    fixSpacesWordsInFile("broken.txt");

    return 0;
}