#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Car{
    string model;
    string producer;
    int year;
    string engineType;
    int mileage;
    int price;

    string toString(){
        string carInfo = model + ", " 
        + producer + '\n' 
        + to_string(year) + " year, " 
        + engineType + " engine type, " 
        + to_string(mileage) + "m, " + '\n'
        + to_string(price) + "$"+ '\n';

        return carInfo;
    }
};

Car makeCarFromVector(vector<string> lineValues){
    Car car;
    if(lineValues.size() < 6) return car;
    car.model = lineValues[0];
    car.producer = lineValues[1];
    car.year = stoi(lineValues[2]);
    car.engineType = lineValues[3];
    car.mileage = stoi(lineValues[4]);
    car.price = stoi(lineValues[5]);

    return car;
}

Car makeCarFromLine(string line){
    stringstream ss(line);
    vector<string> lineValues;
    string substr;
    while(ss.good()){
        substr = "";
        getline(ss, substr, ',');
        lineValues.push_back(substr);
    }

    return makeCarFromVector(lineValues);
}

vector<Car> readCarsFile(ifstream& file){
    string line;
    vector<Car> cars;
    while(getline(file, line)){
        Car car = makeCarFromLine(line);
        cars.push_back(car);
    }

    return cars;
}

vector<Car> readCarsFileByName(string fileName){
    ifstream file(fileName);
    vector<Car> cars = readCarsFile(file);

    file.close();
    return cars;
}

void outputCarsToFileName(string srcName, string destName, int maxMileage, int maxPrice){
    vector<Car> cars = readCarsFileByName(srcName);
    ofstream file;
    file.open(destName);
    for(auto car : cars){
        if(car.mileage <= maxMileage && car.price <= maxPrice)
            file << car.toString() << '\n';
    }

    file.close();
}

int main()
{
    // vector<Car> cars = readCarsFileByName("cars.kocheva");
    // for(auto car : cars){
    //     cout << car.toString() << endl;
    // }
    int R;
    cout << "Enter max mileage(R): ";
    cin >> R;

    int C;
    cout << "Enter max price(C): ";
    cin >> C;
    outputCarsToFileName("cars.kocheva", "cars.rc", R, C);

    return 0;
}