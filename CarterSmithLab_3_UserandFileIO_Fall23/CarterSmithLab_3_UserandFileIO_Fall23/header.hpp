/*
    CIS-162 Lab 3 User and File I/O C++
    Fall of 2023
    Instructor: Busch
    Student: Carter Smith
    Lab Name: Lab 3 User and File I/O
    Description: Write an interactive C++ program that computes and outputs the mean and
    population standard deviation of a set of four integers that are inputted by a file called
    “inMeanStd.dat” and the user (should handle both). Although the individual values are
    integers, the results are floating-point values. Be sure to use proper formatting and
    appropriate comments in your code. Provide appropriate prompts to the user. The
    output should be to the screen for the user inputted values and to a file called
    “outMeanStd.dat”. The programs output should be labeled clearly and formatted
    neatly. You must calculate the mean and standard deviation in separate methods within
    a class.

*/



#ifndef HEADER_HPP
#define HEADER_HPP

#include <cmath>

class Calculator {
public:
    Calculator(); // Constructor
    void calculateMeanAndStdDev(double numbers[4]); // Function to calculate mean and standard deviation
    double getMean() const; // Getter for mean
    double getStdDeviation() const; // Getter for standard deviation
    void reset(); // Reset mean and standard deviation values

private:
    double mean;
    double std_deviation;
};

// Implementation of member functions
Calculator::Calculator() : mean(0), std_deviation(0) {}

void Calculator::calculateMeanAndStdDev(double numbers[4]) {
    double sum = 0;

    // Calculate mean
    for (int i = 0; i < 4; ++i) {
        sum += numbers[i];
    }
    mean = sum / 4;

    // Calculate variance and standard deviation
    sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += pow(numbers[i] - mean, 2);
    }
    double variance = sum / 4;
    std_deviation = sqrt(variance);
}

double Calculator::getMean() const {
    return mean;
}

double Calculator::getStdDeviation() const {
    return std_deviation;
}

void Calculator::reset() {
    mean = 0;
    std_deviation = 0;
}

#endif // HEADER_HPP
