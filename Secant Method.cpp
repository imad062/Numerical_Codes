/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Secant Method for Quadratic Equations
 *
 * Input:
 *
 *  1. a, b, c
 *     These are coefficients of the equation
 *     ax^2 + bx + c
 *
 *
 * Output:
 *  1.  The root(s) of the equation
 *  2.  Number of iteration taken to get the root
 *
 */

#include <iostream>
#include <cmath>
#define ERROR_LIMIT .00001

using namespace std;

double a, b, c;
static int iterationCount;

double Function(double X)
{
    return (a * X * X) + (b * X) + c ;
}

double Secant(double X1, double X2)
{
    iterationCount = 0;

    double X0;

    while( 1 )
    {

        iterationCount++;

        X0 = X2 - ( Function(X2) * (X2 -X1) ) / ( Function(X2) - Function(X1) );

        if(abs ((X0 - X2) / X0) < ERROR_LIMIT )
        {
            break;
        }

        //here X2 = (i)th root and X1 = (i-1)th root
        //X0 is (i+1)th root
        X1 = X2;
        X2 = X0;
    }
    return X0;
}

int main() {

    int rootCount = 1;

    cout << "enter a, b, c respectively: ";
    cin >> a >> b >> c;

    //In secant method , no bracketing values are needed
    //so random numbers 0 and 1 are given as starting values
    cout << "[ Root " << rootCount << ": " << Secant(0, 1) << " ]" << endl;
    cout << "Number of iterations: " << iterationCount << endl;
    rootCount++;

}