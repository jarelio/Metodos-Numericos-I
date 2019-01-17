#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main (){

	int n=3;
	double matrizA[3][3] = {{20,7,9},{7,30,8},{9,8,30}};
	double matrizI[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
	double vetorB[3]={16,38,38};
	float vetorX[n];

	for (int k=0; k<n; k++){

		for (int j=k+1; j<n; j++){
			matrizA[k][j] = matrizA[k][j]/matrizA[k][k];
		}

		for (int j=0; j<n; j++){
			matrizI[k][j] = matrizI[k][j]/matrizA[k][k];
		}

		vetorB[k] = vetorB[k]/matrizA[k][k];

		for (int i=0; i<n; i++){

			if(i!=k){

				for(int j=k+1; j<n; j++){
					matrizA[i][j] = matrizA[i][j] - (matrizA[i][k]*matrizA[k][j]);
				}
				for(int j=0; j<n; j++){
					matrizI[i][j] = matrizI[i][j] - (matrizA[i][k]*matrizI[k][j]);
				}
				vetorB[i] = vetorB[i] - (matrizA[i][k]*vetorB[k]);
				matrizA[i][k]=0;
			}
		}

	}
	for(int i = 0; i<n; i++){
			vetorX[i]=vetorB[i];
	}

	//-------------------------PRINTS------------------------------//

	cout << "-----------Matriz A-----------";

	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matrizA[i][j] << "," ;
			}else{
				cout << matrizA[i][j] ;
			}		
		}
	}

	cout << endl;
	cout << "-----------Determinante----------" << endl;
	cout << matrizA[0][0]*matrizA[1][1]*matrizA[2][2] << endl;

	cout << "-----------Matriz Inversa-----------";

	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matrizI[i][j] << "," ;
			}else{
				cout << matrizI[i][j] ;
			}		
		}
	}

	cout << endl;

	cout << "-----------Vetor B -----------";
	cout << endl;

	cout << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << vetorB[i];
		}else{
			cout << vetorB[i] << "," ;
		}
	}
	cout << ")";
	cout << endl;

	cout << "-----------Vetor X -----------";
	cout << endl << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << round(vetorX[i]);
		}else{
			cout << round(vetorX[i]) << "," ;
		}
	}
	cout << ")";
	cout << endl;
}