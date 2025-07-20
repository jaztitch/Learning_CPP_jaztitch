#include <iostream>
#include "vectorFunctions.hpp"

void addZeroesToList(vector<int> &numbers, int count){
for (int i = 0; i < count; i++){numbers.push_back(0);}}

void printAllElementsFromList(const vector<int> &list){
for(int number: list){cout << number << endl;}}

void addListToList(const vector<int> &inputList, vector<int> &outputList){
for (int number: inputList){outputList.push_back(number);}}

int getStringOccurrencesInList(vector<string> &list, string text)
{int occurrences = 0;for (string s: list){if(s == text){occurrences++;}}
return occurrences;}