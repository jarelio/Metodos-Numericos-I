#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Metodo{

	protected:

		int r = 0;
		float m = 0;
		float pv=0;
		float soma = 0;
		int* p;
		float* blin;
	
	public:
		
		int n;
		float* vetorX;
		float* vetorB;
		float** matrizA;

		Metodo(int set_n, float* set_vetorB, float** set_matrizA){
			this->n = set_n;
			vetorB = set_vetorB;
			matrizA = set_matrizA;

			vetorX = (float*) malloc(n * sizeof(float*));
			blin = (float*) malloc(n * sizeof(float*));
			p = (int*) malloc(n * sizeof(int*));
				
		}

		void escolhe_pivo(int k);
		void permuta(int k);


};


void Metodo::escolhe_pivo(int k){

	pv = abs(matrizA[k][k]);
	r = k;

	for(int i=k+1; i<n; i++){
		if(abs(matrizA[i][k]) > pv){
			pv = abs(matrizA[i][k]);
			r = i;
		}
	}

}

void Metodo::permuta(int k){
	float aux;

	aux = p[k];
	p[k] = p[r];
	p[r] = aux;
	for(int j = 0; j<n; j++){
		aux = matrizA[k][j];
		matrizA[k][j] = matrizA[r][j];
		matrizA[r][j] = aux;
	}
}