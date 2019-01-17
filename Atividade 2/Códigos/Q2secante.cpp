using namespace std;
#include <math.h>
#include <iostream>
//entradas
float fun (float);
int main(){
    float x0,x1,x2=0,fx2,e1,e2,raiz=0;
  fx2=0;
    int max=10,k=0;
    x0=0.5;
    x1=1.0;
    e1=0.0001;
    e2=0.0001;
  bool verif=true;
    float fx0=fun(x0);
    float fx1=fun(x1);
    if(fabs(fx0)<e1){
        raiz=x0;
    }
    if(fabs(fx1)<e1 or fabs(x1-x0)<e2){
        raiz=x1;
    }
    cout << " | k |   x2     |  fx2   "<< "\n" ;
   
    while(verif==true){
    x2=((x0*fun(x1))-(x1*fun(x0)))/(fun(x1)-fun(x0));
        fx2=fun(x2); 
        cout << " | " << k << " | " << x2 << " | " << fx2  << "\n";
    if(fabs(fx2)< e1 or fabs(x2-x1)< e2 or k>= max){
      verif=false;
    }
        raiz=x2;
    x0=x1;
        x1=x2;
        k++;
  } 
    cout << raiz << "\n";
}
float fun(float num){
    return -((pow(2.7182,num))/2)+2*cos(num);
}
