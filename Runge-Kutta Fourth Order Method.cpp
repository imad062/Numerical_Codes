/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Fourth Order Runge-Kutta Method 
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
    return X * X + Y * Y;
}

double RungeKuttaFourthOrder(double X0, double Y0, double H, double xFinal)
{
    while(X0 != xFinal)
    {
        double m1 = Function( X0, Y0 );
        double m2 = Function( X0 + H / 2.00 , Y0 + (m1 * H) / 2.00 );
        double m3 = Function( X0 + H / 2.00 , Y0 + (m2 * H) / 2.00 );
        double m4 = Function( X0 + H, Y0 + (m3 * H) );

        Y0 = Y0 + ( (m1 + 2 * m2 + 2 * m3 + m4) / 6.00 ) * H;
        X0 = X0 + H;
    }
    return Y0;
}

int main() {

    double x0, y0, h, Xfinal;
    cout << "Enter the initial X, initial Y, final X and Step Size: ";
    cin >> x0 >> y0 >> Xfinal >> h;

    cout << "[ Y(" << Xfinal << ") = " << RungeKuttaFourthOrder(x0, y0, h, Xfinal) << " ]" << endl;

}