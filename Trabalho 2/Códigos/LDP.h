#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

class LDP : public Metodo{

    private:
        float** matrizU;

	public:
        float** matrizL;
        float** matrizD;
        float** matrizP;

		LDP(int n,float* vetorB, float** matrizA) : Metodo(n, vetorB, matrizA){

		}
		
		float LDP_piv();

};


float LDP::LDP_piv(){
	
	float** matrizU1 = (float**) malloc(n * sizeof(float*));
	float** matrizL1 = (float**) malloc(n * sizeof(float*));
	float** matrizD1 = (float**) malloc(n * sizeof(float*));
	float** matrizP1 = (float**) malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++){
    	matrizU1[i] = (float*) malloc(n * sizeof(float));
        matrizL1[i] = (float*) malloc(n * sizeof(float));
    	matrizD1[i] = (float*) malloc(n * sizeof(float));
        matrizP1[i] = (float*) malloc(n * sizeof(float));
    }
    
	//Inicialização do vetor de permutacao
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

	//Calcula matriz U
	int t = 0;
	for (int i = 0; i<n; i++){
		for(t; t<n; t++){
			matrizU1[i][t] = matrizA[i][t]; 
		}
		t = i+1;
	}

	//Calcula matriz L.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                matrizL1[i][j] = 1;
            }
            else
            {
                if(i>j)
                {
                    matrizL1[i][j] = matrizA[i][j];
                }else{
                	matrizL1[i][j] = 0;
                }
            }

        }
    }

	//Calcula matriz D
	for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j){
                matrizD1[i][j] = matrizU1[i][j];
                cout << matrizD1[i][j] << endl;
            }
            else{
                matrizD1[i][j] = 0;
        }
        }
    }

	//Calcula matriz P
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                matrizP1[i][j] = (matrizU1[i][j])/(matrizU1[i][i]);
                cout << matrizP1[i][j] << endl;
        }
    }
		
	//LDP
		
    float vetorS[n];
    float vetorY[n];

    //Calculando L*s = b.
    for(int i=0; i<n; i++){

        soma = 0;
        if (i!=0){
            for(int j=0; j<i; j++){
               soma = soma + (matrizL1[i][j] * vetorS[j]);
            }
        }
        vetorS[i] = vetorB[i] - soma;
    }
    
    //Calculando D*y = s.
    for(int i=0; i<n; i++)
        vetorY[i] = vetorS[i] / matrizD1[i][i];

    //Calculando P*x = y.
    for(int i=n-1; i>=0; i--){
        soma = 0;
        if (i != n-1){
            for(int j=n-1; j>=i; j--){
                soma = soma + (matrizP1[i][j] * vetorX[j]);
            }
        }
        vetorX[i] = vetorY[i] - soma;
    }

    matrizU = matrizU1;
    matrizL = matrizL1;
    matrizD = matrizD1;
    matrizP = matrizP1;

}