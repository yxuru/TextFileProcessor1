#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() 
    {
    // opens text file and decalres stream & line
    std::ifstream infile;
    infile.open("input.txt");
    std::string line;

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


            std::cout << "Signature: " << left_eq << " Info: " << right_eq << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR! NO MATCHING FILE NAME FOUND!";
    }

    infile.close();
    return 0;
    }

    
    

