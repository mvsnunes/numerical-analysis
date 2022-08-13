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
    int n=0, k=1;
    double x0=0, y0=0, h, a=0, b=0, p=0,xn=0,yn=0,f0=0, f1=0, f2=0, f3=0, f4=0;


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

double x[n+1],y[n+1];



    /* ABM's Method */ 
    cout<<"\nk\tx(k)\ty(k)\n";
    cout<<"------------------------------\n";

    for(int i=1; i<=3; i++)
    {
        x[i]=x0;
        y[i]=y0;
        f1=f(x0,y0);
        f2=f((x0 + (0.5*h)), (y0 + (0.5*h*f1)));
        f3=f((x0 + (0.5*h)), (y0 + (0.5*h*f2)));
        f4=f((x0 +h), (y0 + (h*f3)));
        yn=y0+((h/6)*(f1+(2*f2)+(2*f3)+f4));
        xn = x0+h;
        cout<<k<<"\t"<< xn <<"\t"<< yn<<"\t"<< endl;
        x0=xn;
        y0=yn;


        k++;
    }

f0=f(x[0],y[0]);
f1=f(x[1],y[1]);
f2=f(x[2],y[2]);
f3=f(x[3],y[3]);

for(int i=4; i <=n; i++)
    {
        x0=xn;
        y0=yn;
        p=y0+h*(-9*f0+37*f1 -59*f2+55*f3)/24;
        xn = x0+h;
        f4=f(xn,p);
        yn=y0+(h*(f1-(5*f2)+(19*f3)+(9*f4))/24);
        cout<<k<<"\t"<< xn <<"\t"<< yn<<"\t"<< endl;
        f0=f1;
        f1=f2;
        f2=f3;
        f3=f(xn,yn);

        k++;
    }

    return 0;
}



