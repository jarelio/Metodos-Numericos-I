#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

float calcula_norma(int n, float* x, float* v);
void gauss_seidel(int n, float A[][3], float* b, float precisao, int iterMax);

int main(){

	int n = 3;
	float A[3][3] = {{10,2,2},{1,10,2},{2,-7,-10}};
	float b[3] = {28,7,-17};
	float precisao = 0.5;
	int iterMax = 2;
	cout.precision(3);
	gauss_seidel(n,A,b,precisao,iterMax);

	return 0;	
}

void gauss_seidel(int n, float A[][3], float* b, float precisao, int iterMax){
	
	float r;
	float k = 0;
	float soma = 0;
	float x[3];
	float v[3];
	float norma;

	for(int i = 0; i<n; i++){
		
		r = 1/A[i][i];

		for(int j = 0; j<n; j++){
			if(i!=j){
				A[i][j] = A[i][j] * r;
			}
		}


		if(i==1){
			x[i] = ((b[i]-(A[i][i]*A[i][i-1]*x[i-1]))* r);
		}else if(i==2){
			x[i] = (b[i]-(A[i][i]*A[i][i-2]*x[i-2])-(A[i][i]*A[i][i-1]*x[i-1]))* r;
		}else{
			x[i] = b[i]* r;
		}

		b[i] = b[i] * r;
	}

	cout << "K: " << k+1 << " - x = (" << x[0] << ", " << x[1] << ", " << x[2] << ") - Norma: 1" << endl;

	for (int i = 0; i <n; i++){
		v[i] = x[i];
	}

	do{
		k = k+1;

		for(int i = 0; i<n; i++){
			soma = 0;
			for(int j = 0; j<n; j++){

				if (i!=j){
					soma = soma + A[i][j]*v[j];
				}

			}
			v[i] = b[i] - soma;
		}

		norma = calcula_norma(n, x, v);
		cout << "K: " << k+1 << " - x = (" << x[0] << ", " << x[1] << ", " << x[2] << ") - Norma: " << norma << endl;
	}while(norma>precisao and k<iterMax);

}

float calcula_norma(int n, float* x, float* v){
	float norma = 0;
	float normaNum = 0;
	float normaDen = 0;
	float t = 0;

	for(int i = 0; i<n; i++){
		
		t = abs(v[i]-x[i]);

		if(t > normaNum){
			normaNum = t;
		}

		if(abs(v[i]) > normaDen){
			normaDen = abs(v[i]);
		}

		x[i] = v[i];
	}

	norma = normaNum/normaDen;

	return norma;
}