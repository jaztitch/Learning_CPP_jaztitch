#include <iostream>
#include <vector>

using namespace std;

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

    vector<int> numbers = {3, 5, 88, 156, -6};

    cout<<maxValue(numbers)<<endl;

    return 0;
}