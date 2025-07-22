#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
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
    string playerDesire;

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
    cout<<"What do you hope to find here?"<<endl;
    cin>>playerDesire;player.setDesire(playerDesire);
    size_t i = 0; // Initialize i as needed

    while (i < desHere.size()) {
        if (desHere[i] == playerDesire) {
            std::cout << "Ah, there is much " << playerDesire << " to be found in these lands." << std::endl;
            break;
        } else {
            std::cout << "I think you may be disappointed with what you find here." << std::endl;
            break;
        }
        i++;
    }

    

    return 0;
}
