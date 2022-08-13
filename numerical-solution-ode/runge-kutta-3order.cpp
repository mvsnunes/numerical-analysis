#include<iostream>
#include <math.h>
#include <iomanip>

/* defining ordinary differential equation to be solved */
#define f(x,y) 2-2*y-exp(-4*x)

using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    double x0=0, y0=0, h, a=0, b=0, p=0,xn=0,yn=0, f1=0, f2=0, f3=0, f4=0;
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



    /* RK's Method */
    cout<<"\nk\tx(k)\ty(k)\n";
    cout<<"------------------------------\n";

    for(int i=1; i <= n; i++)
    {
        f1=f(x0,y0);
        f2=f((x0 + (0.5*h)), (y0 + (0.5*h*f1)));
        f3=f((x0 + h), (y0 + (2*h*f2)-h*f1));
        yn=y0+((h/6)*(f1+(4*f2)+f3));
        xn = x0+h;
        cout<<k<<"\t"<< xn <<"\t"<< yn<<"\t"<< endl;
        x0=xn;
        y0=yn;

        k++;

    }




    return 0;
}



