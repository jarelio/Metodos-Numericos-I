#include <iostream>
using namespace std;

float vetorB[4] = {1,-2,28,8};
float matrizA[4][4] = {{5,-2,6,1},{0,3,7,-4},{0,0,4,5},{0,0,0,2}};
float vetorX[4];
float soma;
float* calcVetRet(int n, float* vetorB, float matrizA[][4]);

float* vetorXcalc;

int main(){
	vetorXcalc = calcVetRet(4, vetorB, matrizA);
	for(int i=0; i<4; i++){
		cout << vetorXcalc[i] << endl;
	}
	return 0;
}


float* calcVetRet(int n, float* vetorB, float matrizA[][4]){
	vetorX[n-1] = vetorB[n-1]/matrizA[n-1][n-1];
	for (int i = (n-1); i>=0; i--){
		soma = 0;
		for(int j = i+1; j<=n; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorB[i]-soma)/(matrizA[i][i]);
	}
	return vetorX;
}