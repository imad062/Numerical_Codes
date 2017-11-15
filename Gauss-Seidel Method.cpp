/*
 * Author: <nooruddinimad@gmail.com>
 *
 * Title: Gauss-Seidel Method for Quadratic Equations
 *
 * Input:
 *
 *  1. N
 *      Number of equations/variables
 *  2. a1, a2, a3.....an
 *      These are the co-efficients of each equation
 *  3. b
 *      this is the right side of the equation when the equation is in the form
 *      a1x1 + a2x2 + a3x3 + .... + anxn = b
 *      Here, x1, x2, x3, x4 .... are the roots/variables
 *
 * Output:
 *  1. The root(s) of the equation
 *
 */

#include <iostream>
#include <cmath>
#define ERROR_LIMIT .00001

using namespace std;
double coefficients[100][100];

bool ErrorCheck(int nOfRoots, double * roots, double *prevRoots)
{
    for(int i = 0; i < nOfRoots; i++)
    {
        if( abs( (roots[i] - prevRoots[i]) / roots[i] ) > ERROR_LIMIT )
        {
            return false;
        }
    }
    return true;
}

void Jacobi(int nOfRoots, double *Roots, double *PrevRoots)
{
    while(1)
    {
        for(int i = 0; i < nOfRoots; i++)
        {
            double sum = 0;
            for(int j = 0; j < nOfRoots; j++)
            {
                if(i == j) continue;
                else
                {
                    sum = sum + Roots[j] * coefficients[i][j];
                }
            }
            Roots[i] = (coefficients[i][nOfRoots] - sum) / coefficients[i][i];
        }
        if( ErrorCheck(nOfRoots, Roots, PrevRoots) )
        {
            return;
        }
        else
        {
            for(int i = 0; i < nOfRoots; i++)
            {
                PrevRoots[i] = Roots[i];
            }
        }
    }
}

int main()
{
    int numOfRoots;

    cout << "Enter the number of Equations/Variables: ";
    cin >> numOfRoots;

    double roots[numOfRoots + 1];
    double prevRoots[numOfRoots + 1];


    cout << "Enter the co-efficients of each equations and at last enter the right side of the =(equal) sign: ";

    for(int i = 0; i < numOfRoots; i++)
    {
        for (int j = 0; j <= numOfRoots; j++)
        {
            roots[i] = 0;
            prevRoots[i] = 999999999;
            cin >> coefficients[i][j];
        }
    }

    Jacobi(numOfRoots, roots, prevRoots);

    for (int i = 0; i < numOfRoots; i++)
    {
        cout << roots[i] << " ";
    }

    cout << endl;
}