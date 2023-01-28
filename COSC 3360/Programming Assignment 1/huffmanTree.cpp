// Write the implementation of the member functions of the huffmanTree class here.

#include <iostream>
#include <fstream>
#include <string>
#include "huffmanTree.h"
using namespace std;

int main()
{
//std::ifstream input; 
//input.open("input.txt");

//string mystring;
/*
if ( input.is_open() ){ 
char mychar;
while(input){
mychar = input.get();
cout << mychar; 
}}
cout<<endl;*/
/*
if ( input.is_open() ){ 
while(input){
getline(input,mystring);
cout << mystring<<endl; 
}}
//cout<<endl<<mystring[0];
if ( input.is_open() ){ 
while(input){
while(getline(input,mystring)){
    char ar[];
    if ( !mystring.empty() ) std::cout << mystring[0];
    ar = mystring[0];
        std::cout << '\n';
}}}*/


      // Open the input file
    ifstream inputFile("input2.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Create arrays to store the letters and frequencies
    const int MAX_ITEMS = 100; // maximum number of items in the input file
    char letters[MAX_ITEMS];
    int frequencies[MAX_ITEMS];

    // Read the input file and store the letters and frequencies in the arrays
    int index = 0;
    char letter;
    int frequency;
    while (inputFile >> letter >> frequency) {
        letters[index] = letter;
        frequencies[index] = frequency;
        index++;
    }

    // Close the input file
    inputFile.close();

    // Print the letters and frequencies
    for (int i = 0; i < index; i++) {
        cout << letters[i] << ": " << frequencies[i] << endl;
    }




cout<<endl<<endl;/*
char arr[] = { 'C', 'A', 'D', 'B'};
    int freq[] = { 3,3,2,1 };
    //int ascii[]=arr[];

    // for(int i =0; i<sizeof(arr);i++){
    //     int ascii[i] = {int(arr[i])};
    //     cout<<ascii[i]<<"-"<<arr[i]<<" ";
    // }
//cout<<ascii[1];

    int ascii[] = {67, 65, 68, 66};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size1 = 4;
    HuffmanCodes(arr, freq, size,ascii);*/

    char arr[] = { 'A', 'C', 'B', 'D' };
	int freq[] = { 3,3,1,2 };

	int size = sizeof(letters) / sizeof(letter);


	HuffmanCodes(letters, frequencies, index);
    cout<<endl<<index;

return 0;
}

