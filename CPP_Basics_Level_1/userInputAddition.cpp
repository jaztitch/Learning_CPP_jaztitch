#include <iostream>

int main(){
	
	int num1;
	int num2;
	
	std::cout << "Can you please provide a number: ";
	std::cin >> num1;
	std::cout << "Okay, now provide a number to add to the previous number: ";
	std::cin >> num2;
	std::cout << "The sum of " << num1 << " and " << num2 << " is: " << num1 + num2 << std::endl;
	
	return 0;
}
