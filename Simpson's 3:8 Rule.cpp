/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Simpson's 3/8 Rule for finding Definite Integral
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
    return ( X * X * X ) + 1;
}

double SimpsonsThreeEighth(double lowerLimit, double upperLimit)
{
    double h = (upperLimit - lowerLimit) / 3.00;
    double X1 = lowerLimit + h;
    double X2 = lowerLimit + 2.00 * h;
    return ((3.00 * h) / 8.00) * (Integral(upperLimit) + Integral(lowerLimit) + 3.00 * Integral(X1) + 3.00 * Integral(X2) );
}

int main() {

    double uLimit, lLimit;

    cout << "enter the lower limit and upper limit respectively: ";
    cin >> lLimit >> uLimit;

    cout << "[ Value of Definite Integral: " << SimpsonsThreeEighth(lLimit, uLimit) << " ]" << endl;

}
