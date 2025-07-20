#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<double> temperatures = {12.3, -4.5, 15.0, 11.7, -0.4};

    /*for(int i = 0; i<temperatures.size(); i++){
        double temp = temperatures.at(i);
        cout<<temp<<endl;
        if(temp<0.0){
            cout<<"It's Freezing!"<<endl;
        }
    }*/

    for(double temp:temperatures){
        cout<<temp<<endl;
    }

    return 0;
}