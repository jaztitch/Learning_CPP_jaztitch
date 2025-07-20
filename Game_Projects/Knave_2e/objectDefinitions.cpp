#ifndef OBJECT_DEFINITIONS_H
#define OBJECT_DEFINITIONS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Character
    {
    private:
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int level;
    int experience;
    int Occupation1;
    int Occupation2;
    int experienceValue;

    public:
    string name;
    string gender;
    int primaryAttribute;
    int secondaryAttribute;
    vector<string> pronouns;
    void setName(){cin>>name;}
    void setGender(){cin>>gender;}
    void printGender(){cout<<"Your chosen gender is: "<<gender<<endl;}
    void setPronouns(){
        if(gender=="male"){
            pronouns={"He", "Him", "His"};
        }
        else if(gender=="female"){
            pronouns={"She", "Her", "Hers"};
        }
        else if (gender=="nonbinary"){
            pronouns={"They", "Them", "Theirs"};
        }
        
    };
    };

#endif