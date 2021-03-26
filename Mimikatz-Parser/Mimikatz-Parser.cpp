// Mimikatz-Parser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

const std::string getInput(std::string question) {
    std::string answer;
    std::cout << question << std::endl;

    std::getline(std::cin, answer);
    
    return answer;
}

const void output(std::string output) {
    std::cout << output << std::endl;
}

int main(int argc, char* argv[])
{
    std::string response;
    std::ofstream outFile;
    std::fstream input;
    std::string line;
    std::string hash;

    output("Mimikatz Parser version 1.0\n");
    
    if(argc < 2) {
        response = getInput("Enter the file name to parse:");
        input.open(response);
    } else {
        input.open(argv[1]);
    }

    outFile.open("Out.txt");

    if (input.is_open()) {
        output("File opened successfully");
        while (std::getline(input, line)) {
            if (line.rfind("  Hash NTLM:", 0) == 0) {
                output(line);
                hash = line.substr(14);
                outFile << hash + "\n";
            }
        }  // Char 14 pos is start of Hash.
        outFile.close();
        input.close();
        output("All hashes written to file.");
    } else {
        output("Error: Unable to open file");
    }

    response = getInput("Press enter key to end...");
    
    return 0;
}
