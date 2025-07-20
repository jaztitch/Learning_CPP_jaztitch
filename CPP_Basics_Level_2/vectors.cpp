#include <iostream>
#include <vector>

int main(){

	std::vector<double> temperatures = { 34.5, 27.8, 26.8 };
	std::cout << temperatures.at(0) << std::endl;
	temperatures.at(1) = 30.7;
	std::cout << temperatures.at(1) << std::endl;
	temperatures.push_back(17.4);
	std::cout << temperatures.size() << std::endl;
	
	return 0;
}
