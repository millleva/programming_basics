#include <iostream>
#include <vector>

using namespace std;

struct Student{
    string surname;
    string name;
    string patronim;
    string group;
    
    struct Address{
        string city;
        string street;
        int homeNum;
        int flatNum;
    } address;

    struct Grades{
        int subj1, subj2, subj3;
    } grades;

    void printStudent(){
        cout << "Full name: " << surname << ' ' << name << ' ' << patronim << endl;
        cout << "Group: " << group << endl;
        cout << "Address: " << address.city << ", " << address.street << ", " << address.homeNum << "/" << address.flatNum << endl;
        cout << "Grades: " << grades.subj1 << ", " << grades.subj2 << ", " << grades.subj3 << endl;
        cout << endl;
    }

    int totalGrade(){
        return grades.subj1 + grades.subj2 + grades.subj3;
    }

    string fullAddress(){
        return address.city + ", " + address.street + ", " + to_string(address.homeNum) + '/' + to_string(address.flatNum);
    }
};

void printStudentsFromCity(vector<Student> studs, string city){
    for(auto st : studs){
        if(st.address.city == city) st.printStudent();
    }
}

string getFullAddressOfTheWorstStudent(vector<Student> studs){
    Student stud;
    int worstStudIndex = 0;
    int minGrade = studs[0].totalGrade();
    int studGrade;
    for(int index = 0; index < studs.size(); index++){
        stud = studs[index];
        studGrade = stud.totalGrade();
        if(studGrade < minGrade){
            minGrade = studGrade;
            worstStudIndex = index;
        }
    }
    return studs[worstStudIndex].fullAddress();
}

int main()
{
    Student s1 = {"Smith", "Petya", "Ivanovich", "KNT-132",
                  {"Kyiv", "Doroshenko", 3, 33},
                  {3, 2, 1}};

    Student s2 = {"Belyi", "Anatoliy", "Albertovich", "T-812",
                  {"Dnepr", "Charivna", 6, 66},
                  {5, 5, 5}};

    Student s3 = {"Karpenko", "Artur", "Antonovich", "A-222",
                  {"Kyiv", "Pravdy", 7, 77},
                  {1, 1, 1}};

    vector<Student> students{s1, s2, s3};

    string givenCity;
    cout << "Enter a city: ";
    cin >> givenCity;

    cout << "Students from this city: " << endl;
    cout << endl; 
    printStudentsFromCity(students, givenCity);
    cout << endl;

    cout << "Address of the worst student: " << getFullAddressOfTheWorstStudent(students) << endl;

    return 0;
}