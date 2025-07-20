#include <iostream>
#include <string>

using namespace std;

class Robot
{
private:
    string name;
    int versionNumber;
    double internalTemperature;
public:
    Robot(string name, int versionNumber)
    :name(name), versionNumber(versionNumber),
    internalTemperature(internalTemperature){

    };

    void sayHi(){
        cout<<"Hello, my name is: "
        <<name
        <<", ready to help!"
        <<endl;
    }

    void initHardware(){
        cout<<"Init hardware."<<endl;
    }
    
    void printInfo(){
        cout<<name<<endl;
        cout<<versionNumber<<endl;
        cout<<internalTemperature<<endl;
    }
};

int main(){

    Robot robot1("Robert", 1);

    return 0;
}