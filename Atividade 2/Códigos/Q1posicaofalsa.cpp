#include <iostream>
#include <cmath>

using namespace std;

float a = 0, b = 1; //Valores para calcular a função
float epsilon1 = 0.0001, epsilon2 = 0.0001; //(b-a)<epsilon precisao requerida
int iteracoesMAX = 10, k = 0; //Número máximo de iterações k que o algoritmo vai executar
float intervX  = 0; //Intervalo em que a raiz esta
float Fa = -((pow(2.7182,a))/2)+2*cos(a), Fb = -((pow(2.7182,b))/2)+2*cos(b); //Valor da funcao em a e b
float x = 0, Fx = 0; //Raiz e funcao na raiz

int main(){
	//Método dos sinais
	if(Fa*Fb>0){
		cout << "Erro! A funcao nao muda de sinal entre a e b";
		return Fa*Fb;
	}	
	intervX = abs(b-a);
	if(abs(intervX)<epsilon1){
		x = a; //escolha(a,b)
	}else if(abs(Fa)<epsilon2){
		x = a;
	}else if(abs(Fb)<epsilon2){
		x = b;
	}else{
	cout << "| k |" << "     a     |" << "    Fa    |" << "    b     |" << "    Fb    |" << "    x   |" << "    Fx   |"; 
	cout << "  intervX |" << "\n";
	do{
		x = (((a*Fb)-(b*Fa))/(Fb-Fa)); //Calcula o X pegando o ponto médio do intervalo [a;b] 
		Fx = -((pow(2.7182,x))/2)+2*cos(x); //Calcula o valor da funcao nesse ponto X
		cout << fixed;
		cout.precision(4);
		cout << "| " << k << " |   " << a << "  |  "<< Fa << "  |  " << b << "  | " << Fb  << "  | " << x  << " | ";
		if(Fx>0){
			cout << "+";
		}
		cout << Fx << " |  " << intervX << "  |"<< "\n";
		//Método dos sinais para definir quem vai diminuir (a ou b) no intervalo [a;b]
		if(Fa*Fx>0){
			a = x;
			Fa = Fx;
		}else{
			b = x;
			Fb = Fx;
		}
		//escolhe o intervalo entre os pontos a e b
		intervX = abs(b-a);
		if(intervX<=epsilon1){
			x = a; //escolha(a,b)
		}
		k++; //Iteração +1
	}while(intervX>epsilon1 and iteracoesMAX>=k and abs(Fx)>=epsilon2); //Continua no loop até que 
	}
	cout << "\n Raiz: " << x << "\n"; //Retorna a RAIZ
	return 0;
}
