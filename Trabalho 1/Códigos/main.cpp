#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>      // std::setfill, std::setw

#include "Metodos.h"
#include "Compara.h"
#include "Isolamento.h"

using namespace std;

int main(){

	//Struct de dados de cada foguete
	typedef struct{
		float raiz_n; //Raiz Newton
		float raiz_b; //Raiz Bisseção
		float raiz_pf; //Raiz Posição Falsa
		int a; //a do Intervalo de Isolamento
		int b; //b do Intervalo de Isolamento
		float erro; //Erro dos foguetes
		int escolha_isolamento = 0;
	}Foguetes;

	int n; //Nº de foguetes
	float r; //Precisão dos foguetes
	float E; //Quantidade de casas decimais
	int k_MAX; //Número máximo de iterações
	double x; //Raiz de cada método
	int pf; //Escolha para truncamento ou arredondamento
	int i; //Iteração de foguetes
	int escolha_mostrar; //Escolhe mostrar os cálculos dos métodos ou não (0 ou 1)
	int escolha_isolamento;
	//inicio 
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"                 Alpha Rocket System ©\n \n \n ";
	cout<<"       The Best System To Monitor Your Rocket\n";
	cout<<"---------------------------------------------------------------------------\n";
	//Recebe do usuário o número de foguetes
	do{
		cout << "Informe o Numero de Foguetes: ";
		cin >> n;
		cout << endl;
	}while(n<=0);

	float a[n]; //Vetor de ajustes a de cada foguete
	n=n+1;//Aumenta o vetor para ser calculado o foguete calibrado
	Foguetes foguetes[n]; //Vetor de structs contendo cada foguete e seus dados
	a[n-1] = 1; // i = última posição do vetor (Foguete Calibrado possui parâmetro a=1)
	//Recebe do usuário o número de iterações máximas
	do{
    	cout << "Informe o Numero de Interacoes: ";
		cin >> k_MAX;
		cout << endl;
	}while(k_MAX<=0);

	//Para cada foguete um parâmetro de ajuste a passado para o vetor a[n]
	for (i = 0; i < n-1; i++){
		cout << "Parametro de Ajuste do foguete " << i+1 << ": ";
		cin >> a[i];
		do{
			cout << "Você deseja inserir um isolamento? (0: Sim 1: Não): ";
			cin >> escolha_isolamento;
		}while(escolha_isolamento!=1 and escolha_isolamento!=0);
		if(escolha_isolamento==0){
			cout << "Digite o A do intervalo [A,B]: ";
			cin >> foguetes[i].a;
			cout << "Digite o B do intervalo [A,B]: ";
			cin >> foguetes[i].b;
			foguetes[i].escolha_isolamento=1;
		}
	}

	//Recebe do usuário a precisão usada em cada cálculo dos métodos
	cout << endl;
	cout << "Informe o parâmetro de erro (precisão) dos foguetes: ";
	cin >> r;
	cout << endl;

	//Recebe do usuário a quantidade de casas usadas no cálculo dos métodos
	cout << "Informe quantas casas decimais de Precisao: ";
	cin >> E;
	cout << endl;
	
	//Recebe a opção de executar os cálculos com truncamento ou arredondamento nas casas decimais
	do{
		cout << "Escolha: 0 - Truncamento; 1 - Arredondamento: ";
		cin >> pf;
		cout << endl;
	}while(pf!=0 and pf!=1);

	//Recebe a opção de executar os cálculos com truncamento ou arredondamento nas casas decimais
	do{
		cout << "Você deseja verificar os passos dos cálculos dos métodos? (0: Sim 1: Não): ";
		cin >> escolha_mostrar;
		cout << endl;
	}while(escolha_mostrar!=0 and escolha_mostrar!=1);

	//Instanciação para utilizar os métodos passando como parâmetros os dados de cada foguete
	Metodos *raiz = new Metodos();
	//Instanciação de um objeto para executar uma função de comparação de erros
	Compara *compare = new Compara();
	//Instanciãção de um objeto para gerar isolamentos de cada foguete
	Isolamento *isolamento = new Isolamento();

	cout << "\033c";
	system("clear");

	cin.ignore(1e10, '\n');	
	//Quadro Resposta com todos os 3 métodos de cada Foguete, o último (i=n-1) é o foguete calibrado com os parâmetros fixos
	for (i = 0; i < n; i++){
		if (i==n-1 and escolha_mostrar==0){
			cout <<"-----------------------------------------------------------------------------"<<endl;
			cout << "Resultado do Foguete " << i+1 << " Calibrado: " << endl;
			cout <<"-----------------------------------------------------------------------------"<<endl;
		}else if(escolha_mostrar==0){
			cout <<"-----------------------------------------------------------------------------"<<endl;
			cout << "Resultado do Foguete " << i+1 << ": " << endl;
			cout <<"-----------------------------------------------------------------------------"<<endl;
		}
		if(i==n-1){
			r = 0.00001;
			foguetes[i].erro=r;
		}

		if(foguetes[i].escolha_isolamento==0){
			//Calcula o A e o B do intervalo baseado no parâmetro a passado (Isolamento)
			foguetes[i].a = isolamento -> calculaA(a[i]);
			foguetes[i].b = isolamento -> calculaB(a[i]);		
		}


		//Se o isolamento não foi calculado é porque o parâmetro a foi um valor muito alto ou negativo e não foi possível achar um intervalo de inteiros subsequentes onde a raiz se encontra

			//Seta os valores para a instanciação de cada cálculo do foguete (intervalo e erro)
			raiz -> setA(foguetes[i].a);
			raiz -> setB(foguetes[i].b);
			raiz -> setErro(r);

			//Calcula o método da Bisseção com os parâmetros passados (Casas decimais, Iterações máximas, Ajuste a, Arredondamento ou Truncamento)
			if(escolha_mostrar==0){cout << "\nBisseção: \n" << endl;}
			x = raiz -> Bissecao(a[i],E,k_MAX,pf,escolha_mostrar);

			//Guarda no vetor de cada foguete (struct) os valores do erro do foguete e a raiz do cálculo da Bisseção
			foguetes[i].erro=r;
			foguetes[i].raiz_b=x;

			//Calcula o método da Posição Falsa com os parâmetros passados (Casas decimais, Iterações máximas, Ajuste a, Arredondamento ou Truncamento)
			if(escolha_mostrar==0){cout << "\nPosição Falsa: \n" << endl;}	
			x = raiz -> PosicaoFalsa(a[i],E,k_MAX,pf,escolha_mostrar);

			//Guarda no vetor de cada foguete (struct) a raiz do cálculo da Posição Falsa
			foguetes[i].raiz_pf=x;

			if(escolha_mostrar==0){cout << "\nNewton Raphson: \n" << endl;}
			//Calcula o método do Newton Raphson com os parâmetros passados (Casas decimais, Iterações máximas, Ajuste a, Arredondamento ou Truncamento)
			x = raiz -> NewtonRaphson(a[i],E,k_MAX,pf,escolha_mostrar);

			//Guarda no vetor de cada foguete (struct) a raiz do cálculo do Newton Rapshon
			foguetes[i].raiz_n=x;
		
			if(i%2!=0 and i>0 and escolha_mostrar==0){
				cin.ignore(1e10, '\n');
				cout << "\033c";
				system("clear");
			}
	}
	//Indica quantas casas será printado os dados finais
	int casas=0;
	do{
		cout << "\nCom quantas casas você deseja verificar os resultados finais?: ";
		cin >> casas;
	}while(casas<=0);

	//Define as casas e mantém o valor passado
	cout.precision(casas);
	cout << defaultfloat;
	cout << scientific;

	cout << "\033c";
	system("clear");

	cin.ignore(1e10, '\n');
	//Quadro geral com todas as informações finais (Intervalo, Parâmetro de Ajuste, Erro, Raízes dos Métodos) de cada foguete
	cout << "\n-----Dados Gerais dos Foguetes-----\n" << endl;
	for(i=0; i<n; i++){	

		int contador_metodos = 0; //Conta quantos métodos possuem raiz <2 para ser printado os casos em que o foguete não explode
		cout << "Dados Foguete " << i+1 << ":\n" << endl;
		if(foguetes[i].raiz_b==0 and foguetes[i].raiz_n==0 and foguetes[i].raiz_pf==0){
			cout << "A função não converge!\n\n";
			continue;
		}
		cout << "Intervalo: [" << foguetes[i].a << "," << foguetes[i].b << "]" << endl;
		cout << "Parâmetro de Ajuste: " << a[i] << endl;
		cout << "Erro: " << foguetes[i].erro << endl;
		cout << "Raizes: " << endl;
		cout << "	Bisseção: " << foguetes[i].raiz_b << endl;
		cout << "	Posição Falsa: " << foguetes[i].raiz_pf << endl;
		cout << "	Newton Raphson: " << foguetes[i].raiz_n << endl;
		cout << "Conclusão: " << endl;
		if(foguetes[i].raiz_b>2 or foguetes[i].raiz_pf>2 or foguetes[i].raiz_n>2){
			cout << "	O deslocamento da extremidade do foguete é dado pela raiz da função f(d), pelos Métodos: ";

			if(foguetes[i].raiz_b>2){
				cout << "Bisseção";
			}else{contador_metodos++;}
			if(foguetes[i].raiz_pf>2){
				cout << " Posição Falsa";
			}else{contador_metodos++;}
			if(foguetes[i].raiz_n>2){
				cout << " Newton Raphson";
			}else{contador_metodos++;}	
			
			cout <<" a raiz calculada é maior que 2cm, logo o foguete irá explodir!" << endl;

			if(contador_metodos>0){
				cout << "	O deslocamento da extremidade do foguete é dado pela raiz da função f(d), pelos Métodos: ";
				if(foguetes[i].raiz_b<=2){
					cout << "Bisseção";
				}
				if(foguetes[i].raiz_pf<=2){
					cout << " Posição Falsa";
				}
				if(foguetes[i].raiz_n<=2){
					cout << " Newton Raphson";
				}
				cout <<" a raiz calculada é menor que 2cm, logo o foguete não irá explodir!" << endl;
			}
		}else{
				cout << "O deslocamento da extremidade do foguete é dado pela raiz da função f(d), por todos os métodos a raiz calculada é menor que 2cm, logo o foguete não irá explodir!" << endl;
		}
		cout << "\n";
		if(i%2!=0){
			cin.ignore(1e10, '\n');
			cout << "\033c";
			system("clear");
			cout << "\n-----Dados Gerais dos Foguetes-----\n" << endl;
		}
		if(i==n-1 and i%2==0){
			cin.ignore(1e10, '\n');
			cout << "\033c";
			system("clear");
		}	
	}
	cout << "\033c";
	system("clear");
	//Quadro comparativo entre os métodos de cada foguete (Erro Absoluto entre os métodos, Erro Absoluto de cada método baseado no cálculo fixo da função sem o método)
	cout << "\n-----Comparativos dos Foguetes-----\n" << endl;
	for(i=0; i<n; i++){

		cout << "Comparativos do Foguete " << i+1 << ":\n" << endl;
		if(foguetes[i].raiz_b==0 and foguetes[i].raiz_n==0 and foguetes[i].raiz_pf==0){
			cout << "A função não converge!\n\n";
			continue;
		}
		cout << "Erro Absoluto (Bisseção x Posição Falsa)" << endl;
		cout << "	Ea: " << fabs(foguetes[i].raiz_b-foguetes[i].raiz_pf) << endl;
		cout << "Erro Absoluto (Bisseção x Newton Rapshon)" << endl;
		cout << "	Ea: " << fabs(foguetes[i].raiz_b-foguetes[i].raiz_n) << endl;
		cout << "Erro Absoluto (Posição Falsa x Newton Raphson)" << endl;
		cout << "	Ea: " << fabs(foguetes[i].raiz_pf-foguetes[i].raiz_n) << endl;
		cout << "Erro Absoluto dos 3 métodos em relação à raiz calculada por este computador diretamente na função (e^a)" << endl;
		cout << "	Erro Absoluto Bisseção: " << compare->erroabs(foguetes[i].raiz_b,a[i]) << endl;
		cout << "	Erro Absoluto Posição Falsa: " << compare->erroabs(foguetes[i].raiz_pf,a[i]) << endl;
		cout << "	Erro Absoluto Newton Rapshon: " << compare->erroabs(foguetes[i].raiz_n,a[i]) << endl;
		cout << "\n";
		if(i%2!=0){
			cin.ignore(1e10, '\n');
			cout << "\033c";
			system("clear");
			cout << "\n-----Comparativos dos Foguetes-----\n" << endl;
		}
		if(i==n-1 and i%2==0){
			cin.ignore(1e10, '\n');
			cout << "\033c";
			system("clear");
		}
	}
	cout << "\033c";
	system("clear");
	return 0;
}
