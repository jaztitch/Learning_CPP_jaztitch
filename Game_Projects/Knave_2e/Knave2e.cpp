#include <iostream>
#include <unistd.h>
#include <vector>
#include "dieRoll.cpp"
#include "objectDefinitions.cpp"

using namespace std;

int main() {

srand(time(NULL));
int randomNum = rand() % 3;

    vector<string> maleFirstNames = {"Adam", "Thomas", "James", "William"};
    vector<string> femaleFirstNames = {"Alice", "Sarah", "Tiffany", "Rose"};
    vector<string> nonbinaryFirstNames = {"Rowan", "Avery", "Finley", "Ellis"};

    vector<string> desHere = {"gold", "adventure", "food", "glory", "shelter", "safety"};
    vector<string> genders = {"male", "female", "nonbinary"};
    string positiveReply = "yes";
    string negativeReply = "no";

    string reply;
    string playerDescription;

    cout<<"Please select a gender. Your options are:"<<endl;
    for (string gender:genders)
    {   cout<<gender<<", ";    }cout<<endl;    
    Character player;
    player.setGender();cout<<endl;
    player.setPronouns();
    player.printGender();
    cout<<"What is your name?"<<endl;
    player.setName();cout<<endl;
    cout<<"Welcome, "<<player.name<<" to the land of Teirthos."<<endl;
    cout<<"What is it that you hope to find here?"<<endl;

    return 0;
}
