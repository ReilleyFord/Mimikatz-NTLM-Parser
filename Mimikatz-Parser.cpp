/*
  Mimikatz-Parser
  Ver. 1.0.0
  Developed by Reilley Ford.

  Code and executable is offered for free as-is. All code is open source.
  Examination and validation should be performed by the user.
  The code should be reviewed and understood.
  Use at your own caution.

  Compiled on Windows 10 x64
  Using GCC version 9.2.0.
  C++ 17 Standard
*/

#include <string>
#include <iostream>
#include <fstream>

std::string getInput(std::string question) {
    std::string answer;
    std::cout << question << std::endl;

    std::getline(std::cin, answer);

    return answer;
}

void output(std::string output) {
    std::cout << output << std::endl;
}

int main(int argc, char* argv[])
{
    // Variables.
    std::string version = "1.0.0", outFile = "Output.txt", searchKey = "  Hash NTLM:";
    std::string response, line, hash;
    std::ofstream oStream; // ofstream - Open write-only. R/W not necessary.
    std::ifstream iStream;   // ifstream - Open Read-only not R/W.

    // Info
    output("\nMimikatz Parser version " + version + "\n - Created by S/Cst. Reilley Ford\n - Compiled with GCC version 9.2.0 in C++17\n\nThis program is provided as-is. Use at your own risk\n");

    if(argc < 2) {
        response = getInput("Enter the file path to log file:");
        iStream.open(response);
    } else iStream.open(argv[1]);

    if (iStream.is_open()) {
        oStream.open(outFile);
        output("File opened successfully\n");
        while (std::getline(iStream, line)) {
            if (line.rfind(searchKey, 0) == 0) {
                hash = line.substr(14); // Char[14] is start of Hash.
                output("\t" + hash);
                oStream << hash << std::endl;
            }
        }
        oStream.close();
        iStream.close();
        output("\nSuccess! All hashes written to " + outFile);
    } else output("Error: Unable to open file.");

    response = getInput("Press enter key to end...");

    return 0;
}
