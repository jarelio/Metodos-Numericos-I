#include <iostream>
#include <cmath>

using namespace std;

//função = x - x ln(x) (é possível a alteração do código para receber e calcular a função)
float epsilon1 = 0.00001; //(b-a)<epsilon precisao requerida
int iteracoesMAX = 10, k = 1; //Número máximo de iterações k que o algoritmo vai executar
float x = 0, x0 = 2.5, x1 = 0; //raizes
float Fx0 = (x0 - (x0 * log(x0))), Fx1 = 0; //funcao em x0
float psix = x0/log(x0); //funcao psi em x0

int main(){
	
	if(abs(Fx0) < epsilon1){
		x = x0;
	}else{
		cout << "| k |" << "      x1     |" << "     x0     |" << "    x1-x0    |" << "     F(x1)   |" << "\n";
	
		do{
			psix = x0/log(x0);
			x1 = psix;
			Fx1 = (x1 - (x1 * log(x1)));
			cout << fixed;
			cout.precision(6);
			cout << "| " << k << " |   " << x1 << "  |  "<< x0 << "  |  " << x1-x0 << "  |  " << Fx1  << "  | " << "\n" ;	

			if((abs(Fx1) < epsilon1) or abs(x1-x0) < epsilon1 or k >= iteracoesMAX){
				x = x1;
				break;
			}
			x0 = x1;

			k++; //Iteração +1

		}while( abs(Fx1) >= epsilon1 and iteracoesMAX>=k ); //Continua no loop até que o valor médio do intervalo fique menor que a precisão ou o número de iterações exceda 
	}

	cout << "\n Raiz: " << x << "\n"; //Retorna a RAIZ
	
	return 0;
}
