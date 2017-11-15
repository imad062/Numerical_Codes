/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Simpson's 1/3 Rule for finding Definite Integral
 *
 * Input:
 *
 *  1. Modify the definite integral in the Integral Function
 *
 *
 * Output:
 *
 *  1. Output the value of the definite integral
 *
 *
 */

#include <iostream>

using namespace std;

double Integral(double X)
{
    return X * X;
}

double SimpsonsOneThird(double lowerLimit, double upperLimit)
{
    double h = (upperLimit - lowerLimit) / 2.00;
    return (h / 3.00) * (Integral(upperLimit) + Integral(lowerLimit) + 4.00 * Integral(upperLimit + lowerLimit));
}

int main() {

    double uLimit, lLimit;

    cout << "enter the lower limit and upper limit respectively: ";
    cin >> lLimit >> uLimit;

    cout << "[ Value of Definite Integral: " << SimpsonsOneThird(lLimit, uLimit) << " ]" << endl;

}
