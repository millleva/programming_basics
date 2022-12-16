#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

//DATA STRUCTURES

enum Position{
    GOALKEEPER = 1,
    DEFENDER,
    SEMIDEFENDER,
    OFFENDER
};

struct Footballer{
    string surname;
    string name;
    int age;
    string team;

    Position position;

    int height;
    int weight;
    int gamesAmount;
    int goals;

    string positionToString(){
        switch(position){
            case Position::GOALKEEPER : return "goalkeeper";
            case Position::DEFENDER : return "defender";
            case Position::SEMIDEFENDER : return "semidefender";
            case Position::OFFENDER : return "offender";
            default: return "unknown";
        }
    }

    string goalsToString(){
        switch(position){
            case Position::GOALKEEPER : return "Missed goals: " + to_string(goals);
            default: return "Scored goals: " + to_string(goals);
        }
    }

    void printInfo(){
        cout << "Full name: " << surname << ' ' << name << endl;
        cout << "Team: " << team << ", Position: " << positionToString() << endl;
        cout << "Characteristics: " << endl;
        cout << "age: " << age << " years, height: " << height << "cm, weight: " << weight << "kg" << endl;
        cout << "Amount of games: " << gamesAmount << ", " << goalsToString() << endl;
        cout << endl;
    }

    string fullNameTeam(){
        return name + ' ' + surname + ", " + team;
    }

    bool isGoalkeeper(){
        return position == Position::GOALKEEPER;
    }
};

//DATA STRUCTURES


vector<Footballer> createDefaultFootballers(){
    Footballer f1 = {"Ronaldo", "Christiano", 37, "Portugal", Position::OFFENDER, 170, 70, 10, 20};
    Footballer f2 = {"Lewandowski", "Robert", 23, "Poland", Position::GOALKEEPER, 200, 100, 15, 4};
    Footballer f3 = {"Neuer", "Emmanuel", 40, "Portugal", Position::GOALKEEPER, 195, 85, 5, 6};
    Footballer f4 = {"Robben", "Arjen", 39, "Netherlands", Position::DEFENDER, 180, 75, 12, 7};

    vector<Footballer> footballers {f1, f2, f3, f4};
    return footballers;
}



void printMap(map<string, int> m){
    cout << '{' << endl;
    for(auto para: m){
        cout << para.first << ':' << para.second << endl;
    }
    cout << '}' << endl;
}

void printSet(set<string> s){
    for(auto el : s){
        cout << el << ' ';
    }
    cout << endl;
}



//TASKS

void printMeanHeightWeight(vector<Footballer> footballers){
    set<string> teams;
    map<string, int> teamToFbCount;
    map<string, int> teamToTotalHeight;
    map<string, int> teamToTotalWeight;

    string teamName;
    for(auto fb : footballers){
        teamName = fb.team;
        teams.insert(teamName);
        teamToFbCount[teamName] = 0;
        teamToTotalHeight[teamName] = 0;
        teamToTotalWeight[teamName] = 0;
    }

    for(auto fb : footballers){
        teamName = fb.team;
        teamToFbCount[teamName] += 1;
        teamToTotalHeight[teamName] += fb.height;
        teamToTotalWeight[teamName] += fb.weight;
    }

    double meanHeight, meanWeight;
    for(auto team: teams){
        meanHeight = (teamToTotalHeight[team]*1.0) / (teamToFbCount[team]*1.0);
        meanWeight = (teamToTotalWeight[team]*1.0) / (teamToFbCount[team]*1.0);
        cout << team << ": " << endl;
        cout << "Mean height: " << meanHeight << ", Mean weight: " << meanWeight << endl;
        cout << endl;
    }  
}

void printBestGoalkeeper(vector<Footballer> footballers){
    int minGoalsAmount = INT_MAX;
    int currGoalsAmount;
    int playsAmount;
    int neededIndex;
    Footballer currFB;
    for(int index = 0; index < footballers.size(); index++){
        currFB = footballers[index];
        currGoalsAmount = currFB.goals;
        playsAmount = currFB.gamesAmount;
        if(currFB.isGoalkeeper() && currGoalsAmount < minGoalsAmount && playsAmount >= 2){ 
            minGoalsAmount = currGoalsAmount;
            neededIndex = index;
        }
    }
    cout << "The best goalkeeper: " << endl; 
    footballers[neededIndex].printInfo();
}

void printBestScorers(vector<Footballer> footballers, double givenNumber){
    double currScore;
    double bestScore = 0;
    Footballer fb;
    int bestIndex = 0;
    bool isThereBestNumberScorer = false;
    bool isTitlePrinted = false;
    for(int index = 0; index < footballers.size(); index++){
        fb = footballers[index];
        currScore = (fb.goals*1.0) / (fb.gamesAmount*1.0);
        if(!fb.isGoalkeeper()){
            if(currScore > givenNumber){
                isThereBestNumberScorer = true;
                if(!isTitlePrinted){
                    isTitlePrinted = true;
                    cout << "The best scorers are: " << endl;
                }
                fb.printInfo();
            }
            if(currScore > bestScore){
                bestScore = currScore;
                bestIndex = index;
            } 
        }       
    }

    if(!isThereBestNumberScorer){
        cout << "There are no such footballers, the best scorer is: " << endl;
        footballers[bestIndex].printInfo();
    }
}

//TASKS


//CLI CRUD

void printMenu(){
    cout << "MENU" << endl;
    cout << "1. Print one footballer by index" << endl;
    cout << "2. Print all footballers info" << endl;
    cout << "3. Print index to a footballer" << endl;
    cout << "4. Edit one footballer" << endl;
    cout << "5. Add one footballer" << endl;
    cout << "6. Print mean height and weight of footballers" << endl;
    cout << "7. Print the best goalkeeper" << endl;
    cout << "8. Print the best scorers by given number" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

//"2. Print all footballers info"
void printGivenFootballers(vector<Footballer> footballers){
    for(auto fb : footballers){
        fb.printInfo();
    }
}

//"3. Print index to a footballer"
void printIndexAndFootballer(vector<Footballer> footballers){
    for(int index = 0; index < footballers.size(); index++){
        cout << index << " - " << footballers[index].fullNameTeam() << endl;
    }
}


int getIndexFromUser(int size){
    bool gotValid = false;
    int givenIndex;
    while(!gotValid){
        cout << "Enter an index: ";
        cin >> givenIndex;
        if(givenIndex >= 0 && givenIndex < size){
            gotValid = true;
        }
    } 
    return givenIndex;
}

int getNumberFromUser(string msg){
    int number;
    cout << msg;
    cin >> number;

    return number;
}


//"4. Edit one footballer"
vector<Footballer> editOneFootballer(vector<Footballer> footballers){
    int index = getIndexFromUser(footballers.size());
    int goalsAmount = getNumberFromUser("Enter a number of goals: ");
    int gamesAmount = getNumberFromUser("Enter a number of games: ");
    footballers[index].goals = goalsAmount;
    footballers[index].gamesAmount = gamesAmount;

    return footballers;
}


//"1. Print one footballer by index"
void printFootballerByIndex(vector<Footballer> footballers){
    int index = getIndexFromUser(footballers.size());
    footballers[index].printInfo();
}


//"5. Add one footballer"
vector<Footballer> addFootballer(vector<Footballer> footballers){
    string surname;
    string name;
    int age;
    string team; 
    int positionNum;
    Position position;
    int height;
    int weight;
    int gamesAmount;
    int goals;

    cout << "Surname: ";
    cin >> surname;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Team: ";
    cin >> team;
    cout << "Position (1 - GOALKEEPER, 2 - DEFENDER, 3 - SEMIDEFENDER, 4 - OFFENDER): ";
    cin >> positionNum;
    switch (positionNum)
    {
    case 1 :
        position = Position::GOALKEEPER;
        break;
    case 2 :
        position = Position::DEFENDER;
        break;
    case 3 :
        position = Position::SEMIDEFENDER;
        break;
    case 4 :
        position = Position::OFFENDER;
        break;
    default:
        position = Position::OFFENDER;
        break;
    }

    cout << "Height: ";
    cin >> height;
    cout << "Weight: ";
    cin >> weight;
    cout << "Games: ";
    cin >> gamesAmount;
    cout << "Goals: ";
    cin >> goals;

    Footballer footballer = {surname, name, age, team, position, height, weight, gamesAmount, goals};
    footballers.push_back(footballer);

    return footballers;
}


//"8. Print the best scorers by given number"
void printBestScorersWithInput(vector<Footballer> footballers){
    int num = getNumberFromUser("Enter a number: ");
    printBestScorers(footballers, num);
}

void cliApp(){
    bool isRunning = true;
    int chosenOption = 0;
    vector<Footballer> footballers = createDefaultFootballers();
    while(isRunning){
        printMenu();
        cin >> chosenOption;
        switch (chosenOption){
            case 1 : 
                printFootballerByIndex(footballers);
                break;
            case 2 : 
                printGivenFootballers(footballers);
                break;
            case 3 : 
                printIndexAndFootballer(footballers);
                break;
            case 4 : 
                footballers = editOneFootballer(footballers);
                break;
            case 5 : 
                footballers = addFootballer(footballers);
                break;
            case 6 : 
                printMeanHeightWeight(footballers);
                break;
            case 7 : 
                printBestGoalkeeper(footballers);
                break;
            case 8 : 
                printBestScorersWithInput(footballers);
                break;
            case 0 : 
                isRunning = false;
                break;
            default : continue;
        }
    }
}

//CLI CRUD


int main()
{
    cliApp();

    return 0;
}