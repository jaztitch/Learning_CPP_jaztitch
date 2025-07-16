#include <iostream>

void sayHello(std::string userName, int userAge){
	std::cout<<"Hello, "<<userName<<". "<<
	"Your age is: "<< userAge<<std::endl;
	}
	
int tripleNumber(int number){
	return number * 3; //Returns the result of variable "number" times 3
}

void printTripleNumber(int number){
	std::cout << tripleNumber(number) << std::endl; //Outputs the result of function "tripleNumber" with variable "number"
}

int main(){
	std::string userName; //Declares the string named "userName"
	sayHello("Chris", 34); //Calls the function "sayHello", passing the variables "userName" and "userAge"
	sayHello("Oliver", 10); //Calls the function "sayHello", passing the variables "userName" and "userAge"
	printTripleNumber(4); //Calls the function "printTripleNumber" and passes the variable "number"
	std::cout << tripleNumber(4) << std::endl; //Prints the result of "tripleNumber" function
	std::cout << 4*3 << std::endl; //Prints the result of 4 times 3
	return 0; //Ends main function
}
