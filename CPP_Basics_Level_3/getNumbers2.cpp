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

    vector<int> numbers;

    bool questions=true;
    while (questions)
    {
        int input;
        cout<<"Enter a number, enter 0 to stop: ";
        cin>>input;
        if (input==0){questions==false;}
        else{numbers.push_back(input);}
    }

    for (int nums:numbers)
    {cout<<nums<<endl;}

    cout << "Maximum value from given numbers: "
    << maxValue(numbers)
    << endl;

    return 0;
}
