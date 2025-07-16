#include <iostream>
#include <vector>
#include <numeric>

int main(){
	
	std::vector<double> numbers = {2.5, 5.3, 8.0, 2.2};
	
	float total = std::accumulate(numbers.begin(), numbers.end(), 0.0) / 4;
	
	std::cout << total << std::endl;
	
	
	return 0;
}
