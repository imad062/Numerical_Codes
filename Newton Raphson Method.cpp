/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Newton Raphson Method for Quadratic Equations
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

double FunctionDerivative(double X)
{
    return ( 2 * a * X ) + b;
}

double NewtonRaphson(double X1, double X2)
{
    iterationCount = 0;

    //initialy there is no prevX0, so to make E > ERROR_LIMIT prevX0 is initialized with a big number
    double X0 = 0, prevX0;

    // we have to set a value for prevX0 initially, this value can be any random value between
    // bracketing ranges X1 and X2
    prevX0 = (X1 + X2) / 2.00;

    while( 1 )
    {
        iterationCount++;

        X0 = prevX0 - ( Function(prevX0) / FunctionDerivative(prevX0) );

        if(abs ((X0 - prevX0) / X0) < ERROR_LIMIT )
        {
            break;
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

    int xmax = ceil ( sqrt( (b / a)*(b / a)  -  (2 * (c / a)) ) );

    //loop starts from the negative bracketing value and runs until xmax-1
    for (int i = -xmax; i < xmax; i++)
    {
        //loop runs until xmax-1 because when i = xmax - 1 , i+1 = xmax
        if( Function(i) * Function(i+1) < 0)
        {
            cout << "[ Root " << rootCount << ": " << NewtonRaphson(i, i+1) << " ]" << endl;
            cout << "Number of iterations: " << iterationCount << endl;
            rootCount++;
        }
    }


}