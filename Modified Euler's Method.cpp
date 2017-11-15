/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Modified Euler's Method
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

double Function(double X, double Y)
{
    return X + Y;
}

double ModifiedEuler(double X0, double Y0, double H, double xFinal)
{
    while(X0 < xFinal)
    {
        X0 = X0 + H;
        double Y1 = H * Function(X0, Y0);
        double newY1 = Y0 + Y1;
        double Y2 = H * Function(X0, newY1);
        double newY0 = Y0 + ( Y1 + Y2 ) / 2;
        
        Y0 = newY0;

    }
    return Y0;
}

int main() {

    double x0, y0, h, Xfinal;
    cout << "Enter the initial X, initial Y, final X and Step Size: ";
    cin >> x0 >> y0 >> Xfinal >> h;

    cout << "[ Y(" << Xfinal << ") = " << ModifiedEuler(x0, y0, h, Xfinal) << " ]" << endl;

}
