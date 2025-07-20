#include <iostream>

int main(){
	
	std::string userName;
	int userAge;
	
	std::cout << "Hello, what is your name? ";
	std::cin >> userName;
	std::cout << "That's great, " << userName << ", what's your age? ";
	std::cin >> userAge;
	std::cout << "Okay, " << userName << ", I see you're " << userAge << std::endl;
	
	return 0;
}
