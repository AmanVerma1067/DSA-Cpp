#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        inputFile.close(); // Close input file if output file cannot be opened
        return 1;
    }

    int number;
    while (inputFile >> number) {
        // Double the integer value and write it to the output file
        outputFile << number * 2 << " ";
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
