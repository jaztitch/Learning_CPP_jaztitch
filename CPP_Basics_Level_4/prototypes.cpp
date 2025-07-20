#include <iostream>

using namespace std;

int tripleNumber(int number);

void printTripleNumber(int number);

int main(){
    printTripleNumber(4);

    return 0;
}

int tripleNumber(int number){
    return number * 3;
}

void printTripleNumber(int number){
    cout << tripleNumber(number)<<endl;
}
