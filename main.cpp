#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class Decision {

    public:
        Decision();

        void Start(); //each function represents a dialouge option. The user will run start then each program will have a call that leads to the next branch in the dialogue tree

    private:
        vector<string> lines;
        int userInput;

        void GetUserInput();
        void GetLines();
        void DisplayLine(int line);

        void Waterfall(); //All the decisions you can make in the game
        void WaterfallRun();
        void Fish();
        void Eagle();
        void EagleKill();
        void EagleTalk();
        void GiveFish();
        void HideFish();
        void NewFish();
        void KeepFish();
        void KeepFish2();
        void GiveFish2();

};

void Decision::Start() { 
    DisplayLine(0);
    for (int i = 0; i < 5; ++i) cout << endl;
    Waterfall();
}

void Decision::Waterfall() {
    DisplayLine(1);
    GetUserInput();
    if (userInput == 1) {
        WaterfallRun();
    } else {
        Fish();
    }
}

void Decision::WaterfallRun() { //ENDING 1
    DisplayLine(2);
    cout << "game over" << endl;
}

void Decision::Fish() {
    DisplayLine(3);
    Eagle();
}

void Decision::Eagle() {
    DisplayLine(4);
    GetUserInput();
    if (userInput == 1) {
        EagleTalk();
    } else {
        EagleKill();
    }
}

void Decision::EagleTalk() { 
    DisplayLine(6);
    GetUserInput();
    if (userInput == 1) {
        GiveFish();
    } else {
        HideFish();
    }
}

void Decision::EagleKill() { //ENDING 2
    DisplayLine(5);
    cout << "game over" << endl;
}

void Decision::GiveFish() { //ENDING 3
    DisplayLine(7);
    cout << "game over" << endl;
}

void Decision::HideFish() {
    DisplayLine(8);
    GetUserInput();
    if (userInput == 1) {
        NewFish();
    } else {
        KeepFish();
    }
}

void Decision::NewFish() { //ENDING 4
    DisplayLine(9);
    cout << "game over" << endl;
}

void Decision::KeepFish() {
    DisplayLine(10);
    GetUserInput();
    if (userInput == 1) {
        KeepFish2();
    } else {
        GiveFish2();
    }
}

void Decision::KeepFish2() { //ENDING 5
    DisplayLine(11);
    cout << "game over" << endl;
}

void Decision::GiveFish2() { //ENDING 6
    DisplayLine(12);
    cout << "game over" << endl;
}

Decision::Decision() { //initializer loads the vector and tests to make sure it read the file properly
    GetLines();
    if (lines.size() == 0) {
        cout << "file error" << endl;
        exit(1);
    }
}


void Decision::GetUserInput() { //gets user input and makes sure it is a valid selection
    cout << "-";
    cin >> userInput;
    while (userInput != 1 && userInput != 2) {
        cout << "Invalid selection, try again: ";
        cin >> userInput;
    }
    for (int i = 0; i < 5; ++i) cout << endl;
}

void Decision::GetLines() { //loads each line of the file "lines.txt" to an element in a vector that can be referenced to display text on screen
    ifstream inFS;
    string fileLine;

    inFS.open("lines.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file lines.txt." << endl;
      return;
   }

    getline(inFS, fileLine);
    while (!inFS.fail()) {
        lines.push_back(fileLine);
        getline(inFS, fileLine);
    }
}

void Decision::DisplayLine(int line) { //displays the text at index line in lines
    string temp = lines.at(line);
    cout << temp << endl;
}


int main() {
    Decision play;
    int temp;

    cout << "--The Forest of Doom--" << endl;
    cout << "This is a Choose Your Own Adventure game where you decide where the story goes!" << endl;
    cout << "When at a crossroads the two options will be displayed as (1) option #1 and (2) option #2. Then you type either 1 or 2 depending on which path you wish to take." << endl;
    cout << "Enter the number '1' to begin" << endl;
    cout << "-";
    cin >> temp;

    for (int i = 0; i < 5; ++i) cout << endl;
    play.Start();

}