#include <iostream>

using namespace std;

int main(){

    int userAge = 20;

    if (userAge >= 18){
        cout << "You are legally an adult." << endl;
    }
    else {
        cout<<"You're not legally an adult, yet."<<endl;
    }

    return 0;
}