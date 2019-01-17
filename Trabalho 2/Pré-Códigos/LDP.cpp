#include <iostream>
#include <cmath>
using namespace std;

float escolhe_pivo(float matrizAT[][3], int k, float escolha);
void permuta(int k);
float* LDP(float matrizL[][3], float matrizD[][3], float matrizP[][3], float* vetorBT);

float soma = 0;
float matrizA[3][3] = {{20,7,9},{7,30,8},{9,8,30}};
int n = 3;
int r = 0;
int p[3];
float vetorXT[3];

int main(){

	float vetorB[3] = {16,38,38};
	float* vetorX;
	float pv = 1;
	float blin[3];


	float m = 0;

	float matrizU[3][3];
	float matrizL[3][3];
	float matrizD[3][3];
	float matrizP[3][3];

	//Inicialização do vetor de permutação
	for(int i = 0; i<n; i++){
		p[i] = i;
	}

	for(int k = 0; k<n-1; k++){

		pv = escolhe_pivo(matrizA, k, pv);
		r = escolhe_pivo(matrizA, k, r);
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
			matrizU[i][t] = matrizA[i][t]; 
		}
		t = i+1;
	}
	matrizU[1][0] = 0;
	matrizU[2][0] = 0;
	matrizU[2][1] = 0;

	//Calcula matriz L.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                matrizL[i][j] = 1;
            }
            else
            {
                if(i>j)
                {
                    matrizL[i][j] = matrizA[i][j];
                }else{
                	matrizL[i][j] = 0;
                }
            }

        }
    }

	cout << "-----------Matriz L-----------";

	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matrizL[i][j] << "," ;
			}else{
				cout << matrizL[i][j] ;
			}		
		}
	}

	cout << endl;

	//Calcula matriz D
	for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j)
                matrizD[i][j] = matrizU[i][j];
            else
                matrizD[i][j] = 0;
        }
    }

    cout << "-----------Matriz D-----------";

	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matrizD[i][j] << "," ;
			}else{
				cout << matrizD[i][j] ;
			}		
		}
	}

	cout << endl;

	//Calcula matriz P
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
//            if (i<=j)
                matrizP[i][j] = (matrizU[i][j])/(matrizU[i][i]);
        }
    }

    cout << "-----------Matriz P-----------";

	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matrizP[i][j] << "," ;
			}else{
				cout << matrizP[i][j] ;
			}		
		}
	}

	cout << endl;

    vetorX = LDP(matrizL,matrizD, matrizP,vetorB);


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

float escolhe_pivo(float matrizAT[][3], int k, float escolha){
	float pv = abs(matrizAT[k][k]);
	int r = k;

	for(int i=k+1; i<n; i++){
		if(abs(matrizAT[i][k]) > pv){
			pv = abs(matrizAT[i][k]);
			r = i;
		}
	}

	if(escolha==1){
		return pv;
	}else{
		return r;
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

float* LDP(float matrizL[][3], float matrizD[][3], float matrizP[][3], float* vetorBT){
    int i, j;
    float somaE;
    float vetorS[3];
    float vetorY[3];

    //Calculando L*s = b.
    for(i=0; i<n; i++){

        somaE = 0;
        if (i!=0){
            for(j=0; j<i; j++){
               somaE = somaE + (matrizL[i][j] * vetorS[j]);
            }
        }
        vetorS[i] = vetorBT[i] - somaE;
    }

    //Calculando D*y = s.
    for(i=0; i<n; i++)
        vetorY[i] = vetorS[i] / matrizD[i][i];

    //Calculando P*x = y.
    for(i=n-1; i>=0; i--){
        somaE = 0;
        if (i != n-1){
            for(j=n-1; j>=i; j--){
                somaE = somaE + (matrizP[i][j] * vetorXT[j]);
            }
        }
        vetorXT[i] = vetorY[i] - somaE;
    }

    return vetorXT;

}