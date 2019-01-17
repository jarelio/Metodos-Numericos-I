#include <iostream>
#include <cmath>
	
using namespace std;

//Entradas
float epsilon1 = 0.0001, epsilon2 = 0.0001; //(b-a)<epsilon precisao requerida
int iteracoesMAX = 10, k = 0; //Número máximo de iterações k que o algoritmo vai executar
int qntd_coef = 3;
float coef[4];
float x = 0.5, deltax = 0, b, c;

int main(){
	coef[0] = 3;
	coef[1] = -9;
	coef[2] = 0; 
	coef[3] = 1;
	deltax = x;
	cout << "| k |" << "      p(x)     |" << "     p'(x)    |" << "    x     |" << "    f(x)    |" << "\n"; 
	do{
		cout.precision(4);
		cout << fixed;
		cout << "| " << k << " |    ";
		if(b>=0){
			cout << "+";
		}
		cout << b << "    |    ";
		if(c>=0){
			cout << "+";
		}
		cout << c << "   |  " << x << "  |   " ;
		b = coef[3];
		c = b;
		for (int i = (qntd_coef-1); i>0; i--){
			b = coef[i] + b*x;
			c = b + c*x;
		}
		b = coef[0] + b*x;
		if(b>=0){
			cout << "+";
		}
		cout << b << "  |" <<endl;
		deltax = b/c;
		x = x - deltax;
		k++; //Iteração +1
	}while(abs(b)>=epsilon1 and iteracoesMAX>=k and abs(deltax)>=epsilon2); //Continua no loop até que o valor médio do intervalo fique menor que a precisão ou o número de iterações exceda 
	cout << "\n Raiz: " << x << "\n"; //Retorna a RAIZ
	return 0;
}
