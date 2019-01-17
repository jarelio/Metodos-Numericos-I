#include <iostream>
#include <cmath>
using namespace std;

float vetorB[3] = {16,38,38};
float matrizA[3][3] = {{20,7,9},{7,30,8},{9,8,30}};

float vetorX[3];
float vetorY[3];
int p[3];
float pv=0;
int r = 0;
float blin[3];

int n = 3;
float m = 0;
float soma = 0;

void escolhe_pivo(int k);
void permuta(int k);
void subst_sucessivas_mod();
void substituicoes_retroativas();

int main(){


	//Inicialização do vetor de permutação
	for(int i = 0; i<n; i++){
		p[i] = i;
	}

	for(int k = 0; k<n-1; k++){

		escolhe_pivo(k);
		if(pv == 0){
			cout << "Matriz é singular!";
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
	cout << "-----------Vetor B -----------";
	cout << endl;

	cout << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << vetorB[i];
		}else{
			cout << vetorB[i]<< "," ;
		}
	}
	cout << ")";
	cout << endl;
	
	cout << "-----------Vetor Y -----------";
	cout << endl;

	cout << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << vetorY[i];
		}else{
			cout << vetorY[i]<< "," ;
		}
	}
	cout << ")";
	cout << endl;

	cout << "-----------Vetor X -----------";
	cout << endl << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << vetorX[i];
		}else{
			cout << vetorX[i]<< "," ;
		}
	}
	cout << ")";
	cout << endl;

}

void subst_sucessivas_mod(){
	vetorY[0] = blin[0]/matrizA[0][0];
	for(int i = 0; i<n; i++){
		soma = 0;
		for(int j = 0; j<i; j++){
			soma = soma + matrizA[i][j]*vetorY[j];
		}
		vetorY[i] = blin[i] - soma;
	}
}

void substituicoes_retroativas(){
	vetorX[n-1]= vetorY[n-1]/matrizA[n-1][n-1];
	for (int i = (n-1); i>=0; i--){
		soma = 0;
		for(int j = i+1; j<n; j++){
			soma = soma + (matrizA[i][j] * vetorX[j]);
		}
		vetorX[i] = (vetorY[i]-soma)/(matrizA[i][i]);
	}
}

void escolhe_pivo(int k){

	pv = abs(matrizA[k][k]);
	r = k;

	for(int i=k+1; i<n; i++){
		if(abs(matrizA[i][k]) > pv){
			pv = abs(matrizA[i][k]);
			r = i;
		}
	}

}

void permuta(int k){
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