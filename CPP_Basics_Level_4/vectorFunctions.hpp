#ifndef VECTOR_FUNCTIONS_H
#define VECTOR_FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

void addZeroesToList(vector<int> &numbers, int count);
void printAllElementsFromList(const vector<int> &list);
void addListToList(const vector<int> &inputList, vector<int> &outputList);
int getStringOccurrencesInList(vector<string> &list, string text);

#endif