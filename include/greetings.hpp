#include <vector>
#include <iostream>
#include <string>

void greet(std::vector<std::string> const& team) {
	for (auto const& member : team) {
		std::cout << "Hello " << member << "!\n";
	}
}