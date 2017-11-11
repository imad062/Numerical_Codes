/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: False Position method for Quadratic Equations without given range
 *
 * Input:
 *
 *  1. a, b, c
 *     These are coefficients of the equation
 *     ax^2 + bx + c
 *
 * Output:
 *  1. The root(s) of the equation
 *  2. Number of Iterations taken to find the root
 *
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
    cout << "enter a, b, c respectively: ";
    cin >> a >> b >> c;

    //finding the initial value that will bracket the root(s)
    int xmax = ceil ( sqrt( (b / a)*(b / a)  -  (2 * (c / a)) ) );

    //loop starts from the negative bracketing value and runs until xmax-1
    for (int i = -xmax; i < xmax; i++)
    {
        //loop runs until xmax-1 because when i = xmax - 1 , i+1 = xmax
        if( Function(i) * Function(i+1) < 0)
        {
            cout << "[ Root " << rootCount << ": " << FalsePosition(i, i+1) <<" ]" <<endl;
            cout << "Number of iterations: " << iterationCount << endl;
            rootCount++;
        }
    }


}
