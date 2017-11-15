/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Trapezoidal Rule for finding definite integral
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

double Trapezoidal(double lowerLimit, double upperLimit)
{
    return ( ( upperLimit - lowerLimit ) / 2.00 ) * ( Integral(lowerLimit) + Integral(upperLimit) );
}

int main() {

    double uLimit, lLimit;

    cout << "enter the lower limit and upper limit respectively: ";
    cin >> lLimit >> uLimit;

    cout << "[ Value of Definite Integral: " << Trapezoidal(lLimit, uLimit) << " ]" << endl;
    
}
