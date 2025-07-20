#include <iostream>
#include <vector>
#include "vectorFunctions.cpp"

using namespace std;

int main(){
//exercise 1
    vector<int> list = {5,5,4};
    cout<<"Size of number list: "<<list.size()<<endl;
    addZeroesToList(list,4);
    cout<<"Size of number list: "<<list.size()<<endl;

//exercise 2
    vector<int> input = {2,3,4};
    vector<int> output = {10,11};
    addListToList(input,output);
    printAllElementsFromList(output);

//exercise 3
    vector<string> cityList={"Paris", "London", "Berlin",
"Paris", "Berlin", "Madrid", "Paris"};
    cout<<"Number of occurrences of 'Paris': "
<<getStringOccurrencesInList(cityList, "Paris")<<endl;

    return 0;
}