#include<iostream>
#include<string>
#include <cmath>
using namespace std;

int main()
{
	//Variáveis
	string binario;
	int binario_int = 0;

	//Input do valor
	cout << "Digite o binário: ";
	getline(cin, binario);

	for (int i = 0; i<binario.length(); i++){
		//Printa o binário escrito
		cout << binario[i];
		//Calcula o valor fazendo 2^i * cada posicao do vetor e somando o resultado
		binario_int += (stoi(to_string(binario[i]))-48)*pow(2,binario.length()-i-1);
		if(i<binario.length()-1){
			cout << "*" << pow(2,binario.length()-i-1) << " + ";
		}
	}

	cout << " = " << binario_int;
	cout << endl;
}