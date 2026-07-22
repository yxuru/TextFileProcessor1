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

            data[left_eq] = right_eq;                                       // Somewhere in here have a duplicate key detector!       

        }
        std::cout << "Successfully processed the text file.\n";

        // Loaded ____ entries in ___ ms!

    }
    else
    {
        std::cout << "ERROR! NO MATCHING FILE NAME FOUND!";
        infile.close();
        return 0;
    }

    
    

    while (true)
    {
        int desiredFunction;

        std::cout << "What would you like to do?\n1. Find all items in a key\n2. Quit Program\n";   // Have a key prefix searcher and/or a partial match search
        std::cin >> desiredFunction;                                                                // export results into a txt file , allow edits to save here
                                                                                                    // Allow you to change loaded file? maybe not because need function to rerun file parse...
        if (desiredFunction == 1)
        {
            findAll(data);
        }
        else if (desiredFunction == 2)
            break;
        else
        {
            std::cout << "ERROR! COULD NOT FIND MATCHING RESPONSE, PLEASE TRY AGAIN!\n";
            continue;
        }
    }

    infile.close();
    return 0;
    }

    
    

