#include <iostream>
#include <fstream>
#include "header.hpp"

using namespace std;

int main() {
    double userInput[4];
    double fileInput[4];
    Calculator userCalculator;
    Calculator fileCalculator;

    // Read user input and calculate mean and standard deviation
    cout << "Enter 4 numbers for user input:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> userInput[i];
    }
    userCalculator.calculateMeanAndStdDev(userInput);

    // Read numbers from input file
    ifstream inputFile("InMeanStd.dat");
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    for (int i = 0; i < 4; ++i) {
        if (!(inputFile >> fileInput[i])) {
            cerr << "Error: Invalid input format in input file." << endl;
            return 1;
        }
    }
    inputFile.close();

    // Calculate mean and standard deviation for file input
    fileCalculator.calculateMeanAndStdDev(fileInput);

    // Display results for user input on the screen
    cout << "User Input Mean: " << userCalculator.getMean() << ", Standard Deviation: " << userCalculator.getStdDeviation() << endl;

    // Open output file and save results from file input
    ofstream outputFile("OutMeanStd.dat");
    if (!outputFile) {
        cerr << "Error: Cannot open output file." << endl;
        return 1;
    }

    outputFile << "Standard Deviation (File Input): " << fileCalculator.getStdDeviation() << endl;
    outputFile << "Mean (File Input): " << fileCalculator.getMean() << endl;

    outputFile.close();

    cout << "Standard deviation for file input saved in OutMeanStd.dat." << endl;

    return 0;
}
