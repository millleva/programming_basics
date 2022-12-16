#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<double> getNumbersFromFile(ifstream& file){
    vector<double> numbers;
    double num = 0.0;
    while(file >> num){
        numbers.push_back(num);
    }

    return numbers;
}

vector<double> getNumbersFromFileName(string fileName){
    ifstream file;
    file.open(fileName);
    vector<double> numbers = getNumbersFromFile(file);
    
    file.close(); 
    return numbers;
}

void printVector(vector<double> numbers){
    for(auto num : numbers){
        cout << num << ' ';
    }
}

void swapNumbers(vector<double>& numbers){
    int numbersSize = numbers.size();
    int vectorSize;
    if(numbersSize % 2 != 0) vectorSize = numbersSize-1;
    else vectorSize = numbersSize;
    for(int index = 0; index < vectorSize; index+=2){
        swap(numbers[index], numbers[index+1]);
    }
    
}

void outputNumberstoFileName(vector<double> numbers, string fileName){
    ofstream file;
    file.open(fileName);
    for(auto num : numbers){
        file << num;
        file << ' ';
    } 

    file.close();
}

void swapNumbersInFileName(string fileName){
    vector<double> numbers = getNumbersFromFileName(fileName);
    swapNumbers(numbers);
    outputNumberstoFileName(numbers, fileName);
}

int main()
{
    swapNumbersInFileName("numbers.txt");

    return 0;
}