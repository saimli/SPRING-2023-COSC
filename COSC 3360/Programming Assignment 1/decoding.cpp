#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void initFile(string filename){
    char character[100];
    int frequency[100];
    int i = 0;
    string line;
    ifstream infile(filename);
    while (getline(infile, line))
    {
        character[i] = line[0];
        frequency[i] = stoi(line.substr(2));
        i++;
    }
    
}
int main() {
string filename="input.txt";
initFile(filename);

    return 0;
}
// 011011011101100101