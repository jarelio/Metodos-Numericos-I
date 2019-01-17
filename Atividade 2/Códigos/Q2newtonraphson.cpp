#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>
int main (){
	//entradas X0 ,E1,E2,max
	int k=0;
	int max=2;
	double raiz;
	double x0,E1,E2;
	x0=2.5;
	E1=0.00001;
	E2=0.00001;
	double fx0= x0 - x0*log(x0);
	double dx0= -log(x0);
	double x1 = x0, fx1;

	if(fabs(fx0)<E1){
		raiz=x0;
	}else{
		cout << "| k |     x    |    f(x)   | \n";
		do{
			x0 = x1;
      		fx0= x0 - x0*log(x0);
      		dx0= -log(x0);
			x1=x0-(fx0/dx0);
			fx1=x1 - x1*log(x1);
      		cout<<fixed;
      		cout.precision(6);
      		cout << "| " << k << " | " << x0 << " | " << fx0 << " | \n";
			k++;
			
		}while(fabs(fx1)>E1 and fabs(x1-x0)>E2 and k<=max );
		raiz=x1;
	}
	cout <<	"\nRaiz: " << raiz << endl;
}