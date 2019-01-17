#include <iostream>
#include <cmath>

using namespace std;

float a = 0, b = 1; //Valores para calcular a fun��o
float epsilon = 0.0001; //(b-a)<epsilon precisao requerida
int iteracoesMAX = 10, k = 0; //N�mero m�ximo de itera��es k que o algoritmo vai executar
float intervX  = 0; //Intervalo em que a raiz esta
float Fa = -((pow(2.7182,a))/2)+2*cos(a), Fb = -((pow(2.7182,b))/2)+2*cos(b); //Valor da funcao em a e b
float x = 0, Fx = 0; //Raiz e funcao na raiz

int main(){
	//M�todo dos sinais
	if(Fa*Fb>0){
		cout << "Erro! A funcao nao muda de sinal entre a e b";
		return Fa*Fb;
	}	
	intervX = abs(b-a);
	cout << "| k |" << "     a     |" << "    Fa    |" << "    b     |" << "    Fb    |" << "    x   |" << "    Fx   |"; 
	cout << "  intervX |" << "\n";
	do{
		x = (a+b)/2; //Calcula o X pegando o ponto m�dio do intervalo [a;b] 
		Fx = -((pow(2.7182,x))/2)+2*cos(x); //Calcula o valor da funcao nesse ponto X
		cout << fixed;
		cout.precision(4);
		cout << "| " << k << " |   " << a << "  |  "<< Fa << "  |  " << b << "  | " << Fb  << "  | " << x  << " | ";
		if(Fx>0){
			cout << "+";
		}
		cout << Fx << " |  " << intervX << "  |"<< "\n";
		//M�todo dos sinais para definir quem vai diminuir (a ou b) no intervalo [a;b]
		if(Fa*Fx>0){
			a = x;
			Fa = Fx;
		}else{
			b = x;
			Fb = Fx;
		}
		//Diminui o intervalo pela metade e continua no intervalo [a;b] j� que um desses valores diminuiu para metade
		intervX = intervX/2;
		k++; //Itera��o +1
	}while(intervX>epsilon and iteracoesMAX>=k); //Continua no loop at� que o valor m�dio do intervalo fique menor que a precis�o ou o n�mero de itera��es exceda 
	cout << "\n Raiz: " << x << "\n"; //Retorna a RAIZ
	return 0;
}
