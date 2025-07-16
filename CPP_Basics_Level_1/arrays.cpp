#include <iostream>
#include <vector>

int main(){
	
	double temperatureList[4] = { 34.5, 27.8, 26.8, 22.0};
	
	std::cout << temperatureList[1] << std::endl;
	
	temperatureList[3] = 15.4;
	
	std::cout << temperatureList[1] << std::endl;
	
	std::vector<double> temperatures;
	
	return 0;
}
