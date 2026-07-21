#include "findAll.h"


void findAll(const std::unordered_map<std::string, std::string>& data)
{

	std::string desiredKey;
	std::cout << "What key do you need?";
	std::cin >> desiredKey;

	std::vector<std::string> allItems;

	for (const auto& [str, value] : data) {
		allItems.push_back(value);
	}

	for (const auto& value : allItems) {
		std::cout << value << std::endl;
	}
	
}