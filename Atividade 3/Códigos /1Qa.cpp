#include <iostream>
#include <cmath>
using namespace std;

float vetorB[3] = {16,38,38};
float matrizA[3][3] = {{20,7,9},{7,30,8},{9,8,30}};
float vetorX[3];
float soma;

float* calcVetRet(int n, float* vetorB, float matrizA[][3]);
float* calcVetGauss(int n, float* vetorB, float matrizA[][3]);

float* vetorXcalc;
float* vetorXcalcGauss;

float m;


int main(){
	vetorXcalcGauss = calcVetGauss(3, vetorB, matrizA);
	cout << "------Vetor X-------" << endl;
	for(int i=0; i<3; i++){
		cout << vetorXcalcGauss[i] << endl;
	}
	return 0;
}


float* calcVetGauss(int n, float* vetorB, float matrizA[][3]){
	for (int k=0; k<n; k++){
		for(int i=k+1; i<n; i++){
			m = -matrizA[i][k]/matrizA[k][k];
			matrizA[i][k] = 0;
			for(int j=k+1; j<n; j++){
				matrizA[i][j]= matrizA[i][j] + m*matrizA[k][j];
			}
			vetorB[i]=vetorB[i]+(m*vetorB[k]);
		}
	}
	cout << "----Matriz A | Vetor B ----" << endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << matrizA[i][j] << " ";
		}
		cout << vetorB[i] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "---------Determinante----------" << endl;
	cout << matrizA[0][0]<< " * " << matrizA[1][1]<<  " * "<< matrizA[2][2] << "= ";
	cout << matrizA[0][0]*matrizA[1][1]*matrizA[2][2] << endl;
	cout << endl;
	vetorXcalc = calcVetRet(4, vetorB, matrizA);
	return vetorXcalc;
}

float* calcVetRet(int n, float* vetorB, float matrizA[][3]){
	vetorX[n-1] = vetorB[n-1]/matrizA[n-1][n-1];
	for (int i = (n-1); i>=0; i--){
		soma = 0;
		for(int j = i+1; j<n; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorB[i]-soma)/(matrizA[i][i]);
	}
	return vetorX;
}