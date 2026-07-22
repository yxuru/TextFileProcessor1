#include "findAll.h"


void findAll(const std::unordered_map<std::string, std::string>& data)
{
	std::cout << "List of keys:\n";
	for (const auto& [key, value] : data) {
		std::cout << key << "\n";
	}

	std::string desiredKey;
	std::cout << "What key do you need?\n"; 
	std::cin >> desiredKey;

	auto item = data.find(desiredKey);

	if (item != data.end()) {
		std::cout << item->second << std::endl;
	}
	else {
		std::cout << "Key not found!" << std::endl;
	}
	
	

}

// Currently the desired key is not functioning and it is simply giving every part of the map when I only want it to print the part of map assigned to that key