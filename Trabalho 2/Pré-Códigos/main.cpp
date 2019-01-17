#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>      // std::setfill, std::setw
#include "Metodos.h"
using namespace std;

int main(){
	
	cout << "Digite o N da matriz NxN: " << endl;
	int n;
	cin >> n;
	float matrizA[n][n];
	float vetorB[n];
	float x;
	cout << "Digite o VetorB: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vetorB[i] = x; 
	}

	Metodos *raiz = new Metodos();
	raiz -> LU_piv(matrizA,n, vetorB);


	return 0;
}