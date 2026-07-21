#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "clean.h"
#include "findAll.h"

 

int main() 
    {
    // opens text file and decalres stream & line
    std::ifstream infile;
    infile.open("input.txt");
    std::string line;

    std::unordered_map<std::string, std::string> data;

    if (infile.is_open()) 
    {
        while (std::getline(infile, line))  // iterate through each line of file
        {
            size_t equal_pos = line.find('=');
            if (equal_pos == std::string::npos) // go next line if no =
                continue;      

            std::stringstream ss( line );   // set up stream for line and variables for both sides
            std::string left_eq;
            std::string right_eq;

            std::getline(ss, left_eq, '=');
            std::getline(ss, right_eq);
            left_eq = trim(left_eq);
            right_eq = trim(right_eq);

            data[left_eq] = right_eq;

        }
    }
    else
    {
        std::cout << "ERROR! NO MATCHING FILE NAME FOUND!";
    }

    std::cout << data["PLAYER_NAME"];
    std::cout << data["PLAYER_GREETING"];

    
    findAll(data);
    

    infile.close();
    return 0;
    }

    
    

