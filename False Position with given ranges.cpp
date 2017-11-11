/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: False Position method for Quadratic Equations with given range
 *
 * Input:
 *
 *  1. a, b, c
 *     These are coefficients of the equation
 *     ax^2 + bx + c
 *  2. x1, x2
 *     These are the given ranges who bracket a root
 *
 * Output:
 *  1. The root(s) of the equation
 *  2. Number of iterations taken to find the root
 
 */

#include <iostream>
#include <cmath>
#define ERROR_LIMIT .00001

using namespace std;

double a, b, c;
int iterationCount;

double Function(double X)
{
    return (a * X * X) + (b * X) + c ;
}

double FalsePosition(double X1, double X2)
{
    iterationCount = 0;

    //initialy there is no prevX0, so to make E > ERROR_LIMIT prevX0 is initialized with a big number
    double X0 = 0, prevX0 = 9999999;

    while( 1 )
    {
        iterationCount++;
        
        X0 = X1 - ( Function(X1) * ( (X2 - X1) / ( Function(X2) - Function(X1) ) ) );

        if(abs ((X0 - prevX0) / X0) < ERROR_LIMIT )
        {
            break;
        }

        if( Function(X0) * Function(X1) < 0)
        {
            X2 = X0;
        }
        else
        {
            X1 = X0;
        }

        prevX0 = X0;
    }
    return X0;
}

int main() {

    int rootCount = 1;
    double x1, x2;

    cout << "enter a, b, c respectively: ";
    cin >> a >> b >> c;
    cout << "enter the ranges: ";
    cin >> x1 >> x2;

    cout << "[ Root is: " << FalsePosition(x1, x2) <<" ]" << endl;
    cout << "Number of Iterations: " << iterationCount << endl;

}
