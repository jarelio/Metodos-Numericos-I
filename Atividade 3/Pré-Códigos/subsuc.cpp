#include <iostream>
using namespace std;

float vetorB[4] = {4,1,48,6};
float matrizA[4][4] = {{2,0,0,0},{3,5,0,0},{1,-6,8,0},{-1,4,-3,9}};
float vetorX[4];
float soma;
float* calcVetSuc(int n, float* vetorB, float matrizA[][4]);

float* vetorXcalc;

int main(){
	vetorXcalc = calcVetSuc(4, vetorB, matrizA);
	for(int i=0; i<4; i++){
		cout << vetorXcalc[i] << endl;
	}
	return 0;
}


float* calcVetSuc(int n, float* vetorB, float matrizA[][4]){
	vetorX[0] = vetorB[0]/matrizA[0][0];
	for (int i = 1; i<n; i++){
		soma = 0;
		for(int j = 0; j<=i-1; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorB[i]-soma)/(matrizA[i][i]);
	}
	return vetorX;
}