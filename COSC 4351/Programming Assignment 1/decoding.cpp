#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
        string message = "";


ifstream inputFile("code.txt");
 int code, index;
    while (inputFile >> code) {
        // Read in the rest of the numbers on the line (the indexes)
        while (inputFile >> index) {
            // Insert the code at the specified index in the message
            message.insert(index, 1, (char)code);
        }
    }

    return 0;
}
// 011011011101100101