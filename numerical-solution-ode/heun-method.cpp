#include<iostream>
#include <math.h>
#include <iomanip>

/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
#define f(x,y) 2-2*y-exp(-4*x)

using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    double x0=0, y0=0, h, a=0, b=0, p=0,xn=0,yn=0;
    int n=0, k=1;

    cout<<"Initial conditions: "<< endl;
    cout<<"x0 = ";
    cin>> x0;
    cout<<"y0 = ";
    cin >> y0;
    cout<<"Lower limit of interval: ";
    cin>> a;
    cout<<"Upper limit of interval: ";
    cin>> b;
    cout<<"Step size: ";
    cin>> h;

    n=(b-a)/h;



    /* Heun's Method */
    cout<<"\nk\tx(k)\ty(k)\n";
    cout<<"------------------------------\n";

    for(int i=1; i <= n; i++)
    {
        xn = x0+h;
        p=y0+h*(f(x0, y0));
        yn = y0 + (0.5*h) * ((f(x0, y0))+f(xn,p ));
        cout<<k<<"\t"<< xn <<"\t"<< yn<<"\t"<< endl;
        x0=xn;
        y0=yn;

        k++;

    }




    return 0;
}



