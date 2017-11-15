/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Euler's Method
 *
 * Input:
 *
 *  1. X0
 *      Initial value of X
 *  2. Y0
 *      Value of Y in initial X
 *  3. H
 *      Step size
 *  4. xFinal
 *      Final value of X for which value of function has to be found
 *
 * Output:
 *
 *  1. Output the value of the function at xFinal
 *
 *
 */

#include <iostream>

using namespace std;

double Function(double X)
{
    return ( 3 * X * X ) + 1;
}

double Euler(double X0, double Y0, double H, double xFinal)
{
    while(X0 != xFinal)
    {
        Y0 = Y0 + H * Function(X0);
        X0 = X0 + H;
    }
    return Y0;
}

int main() {

    double x0, y0, h, Xfinal;
    cout << "Enter the initial X, initial Y, final X and Step Size: ";
    cin >> x0 >> y0 >> Xfinal >> h;

    cout << "[ Y(" << Xfinal << ") = " << Euler(x0, y0, h, Xfinal) << " ]" << endl;

}