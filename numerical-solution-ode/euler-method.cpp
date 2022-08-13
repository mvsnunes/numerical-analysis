#include<iostream>
#include <math.h>
#include <iomanip>

/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
#define f(x,y) -0.2*x*y+2

using namespace std;

int main()
{
cout << fixed << setprecision(5);
 float x0, y0, xn, h, yn, slope, a, b;
 int n, k=1;

 cout<<"Digite as condicoes iniciais"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Digite o limite inferior do intervalo: ";
 cin>> a;
 cout<<"Digite o limite superior do intervalo: ";
 cin>> b;
 cout<<"Digite o passo de integracao: ";
 cin>> h;

 n=(b-a)/h;



 /* Euler's Method */
 cout<<"\nk\tx(k)\ty(k)\n";
 cout<<"------------------------------\n";

 for(int i=1; i <= n; i++)
 {
  yn = y0 + h * (f(x0, y0));
  x0 = x0+h;
  y0 = yn;
  cout<<k<<"\t"<< x0<<"\t"<< y0<< endl;
  k++;

 }


 return 0;
}



