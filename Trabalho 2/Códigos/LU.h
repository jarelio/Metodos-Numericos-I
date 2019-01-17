#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

class LU : public Metodo{
	
	private:
		void subst_sucessivas_mod();
		void substituicoes_retroativas();
		
	public:
		float* vetorY;

		LU(int n,float* vetorB, float** matrizA) : Metodo(n, vetorB, matrizA){

			vetorY = (float*) malloc(n * sizeof(float*));

		}
		
		float LU_piv();	

};

float LU::LU_piv(){

	//Inicialização do vetor de permutação
	for(int i = 0; i<n; i++){
		p[i] = i;
	}

	for(int k = 0; k<n-1; k++){

		escolhe_pivo(k);
		if(pv == 0){
			cout << "Matriz nao singular!";
			return 0;
		}
		if(r!=k){
			permuta(k);
		}

		//Guarda fatores m na matriz A
		for(int i = k+1; i<n; i++){
			m = matrizA[i][k]/matrizA[k][k];
			matrizA[i][k] = m;

			for(int j = k+1; j<n; j++){
				matrizA[i][j] = matrizA[i][j] - (m*matrizA[k][j]);
			}

		}

	}


	//Aplica permutações em B
	for(int i = 0; i<n; i++){
		r = p[i];
		blin[i] = vetorB[r];
	}

	subst_sucessivas_mod();
	substituicoes_retroativas();
	
}


void LU::subst_sucessivas_mod(){
	vetorY[0] = blin[0]/matrizA[0][0];
	for(int i = 0; i<n; i++){
		soma = 0;
		for(int j = 0; j<i; j++){
			soma = soma + matrizA[i][j]*vetorY[j];
		}
		vetorY[i] = blin[i] - soma;
	}
}

void LU::substituicoes_retroativas(){
	vetorX[n-1]= vetorY[n-1]/matrizA[n-1][n-1];
	for (int i = (n-1); i>=0; i--){
		soma = 0;
		for(int j = i+1; j<n; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorY[i]-soma)/(matrizA[i][i]);
	}
}