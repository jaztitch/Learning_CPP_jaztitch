#include <iostream>
#include <vector>

using namespace std;

void addZeroesToList(vector<int> &numbers, int count){
    for (int i = 0; i < count; i++)
    {
        numbers.push_back(0);
    }
    cout<<"Size of number list: "<<numbers.size()<<endl;
    
}

int main(){

    vector<int> list = {5,5,4};
    cout<<"Size of number list: "<<list.size()<<endl;
    addZeroesToList(list,4);
    cout<<"Size of number list: "<<list.size()<<endl;
    return 0;
}