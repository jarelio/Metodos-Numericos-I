#include <iostream>
#include <cmath>
using namespace std;

float lupivtotal(int n, float matrizA[][3], float* vetorB);
float subst_sucessivas_mod(int n, float matrizA[][3], float* blin);
float substituicoes_retroativas(int n, float matrizA[][3], float vetorY);
float escolhe_pivo(float matrizA[][3], int k, int n);
void permuta(int* p, float matrizA[][3], int k, int r, int n);

int main(){

	float vetorB[3] = {9,3,-2};
	float matrizA[3][3] = {{3,-4,1},{1,2,2},{4,0,-3}};
	int n = 3;

	float vetorXfinal = lupivtotal(n, matrizA, vetorB);

	for(int i = 0; i<n; i++){
		cout << vetorXfinal[i] << endl;
	}

}

float lupivtotal(int n, float matrizA[][3], float* vetorB){

	float pvr; //pvr[0] = pv pvr[1] = r
	int p[3];
	float pv;
	int r;
	float m;

	//Inicialização do vetor de permutação
	for(int i = 0; i<n; i++){
		p[i] = i;
	}

	for(int k = 0; k<n-1; k++){

		pvr = escolhe_pivo(matrizA,k,n);
		pv = pvr[0];
		r = (int) pvr[1];

		if(pv == 0){
			cout << "Matriz é singular!";
			return 0;
		}

		if(r!=k){
			permuta(p, matrizA, k, r,n);
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

	float blin[3];

	//Aplica permutações em B
	for(int i = 0; i<n; i++){
		r = p[i];
		blin[i] = vetorB[r];
	}

	float vetorY;
	float vetorX;

	vetorY = subst_sucessivas_mod(n, matrizA, blin);
	vetorX = substituicoes_retroativas(n, matrizA, vetorY);

	return vetorX;
}

float subst_sucessivas_mod(int n, float matrizA[][3], float* blin){
	float vetorXaux[n];
	float soma;

	for(int i = 0; i<n; i++){
		soma = 0;
		for(int j = 0; j<i-1; j++){
			soma = soma + matrizA[i][j]*vetorXaux[j];
		}
		vetorXaux[i] = blin[i] - soma;
	}

	return *vetorXaux;	
}

float substituicoes_retroativas(int n, float matrizA[][3], float vetorY){
	float soma;
	float vetorX[n];

	vetorX[n-1] = vetorY[n-1]/matrizA[n-1][n-1];

	for (int i = (n-1); i>=0; i--){
		soma = 0;
		for(int j = i+1; j<=n; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorY[i]-soma)/(matrizA[i][i]);
	}

	return *vetorX;
}

float escolhe_pivo(float matrizA[][3], int k, int n){
	float pvr[2];

	pvr[0] = abs(matrizA[k][k]);
	pvr[1] = k;

	for(int i=k+1; i<n; i++){
		if(abs(matrizA[i][k]) > pvr[0]){
			pvr[0] = abs(matrizA[i][k]);
			pvr[1] = i;
		}
	}

	return *pvr;
}

void permuta(int* p, float matrizA[][3], int k, int r, int n){
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