#include <iostream>
#include <vector>
using namespace std;

int count;

int maxValue(vector<int> numbers){
    int max=0;
    for(int num: numbers){
        if(num>max){
            max=num;
        }
    }
    return max;
}

int main(){

    cout<< "how many numbers do you have?"<<endl;
    cin>>count;

    vector<int> numbers;

    for (int i = 0; i < count; i++)
    {
        int input;
        cout<<"Enter number #"<<i+1<<endl;
        cin>>input;
        numbers.push_back(input);

    }
    
    cout << "Maximum value from given numbers: "
    << maxValue(numbers)
    << endl;

    return 0;
}