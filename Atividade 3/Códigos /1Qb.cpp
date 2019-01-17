#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main (){

    float m=1;
    int n=3;
    float troca=0;
    float matrizA[3][3] = {{20,7,9},{7,30,8},{9,8,30}};
    float vetorB[3]={16,38,38};
    float pivo=0;
    int l_pivo=0;

    for(int k=0;k<n;k++){
    	pivo=matrizA[k][k];
    	l_pivo=k;	
        for(int i=k+1;i<n;i++){  

            if(matrizA[i][k]>pivo){
              pivo=matrizA[i][k];
              l_pivo=i;   
            }
 
        }
 
        if (pivo == 0){
            cout << "A matriz A é singular.";
            return 0;
        }

        if(l_pivo != k){

            for(int j=0;j<n;j++){

                troca=matrizA[k][j];
                matrizA[k][j]=matrizA[l_pivo][j];
                matrizA[l_pivo][j]=troca;
            }

            troca=vetorB[k];
            vetorB[k]=vetorB[l_pivo];
            vetorB[l_pivo]=troca;
            
        }

        for(int i=k+1;i<n;i++){

            m=matrizA[i][k]/matrizA[k][k];
            matrizA[i][k]=0;

            for(int j=k+1;j<n;j++){
                matrizA[i][j]=matrizA[i][j]-(m*matrizA[k][j]);
            }

            vetorB[i]=vetorB[i]-(m*vetorB[k]);
           
        }
 
    }

	float vetorX[n];
    float soma=0;

    vetorX[0]=0;
    vetorX[n-1]=vetorB[n-1]/matrizA[n-1][n-1];

	for(int i=n-1;i>=0;i--){
		soma=0;

		for(int j=i+1;j<n;j++){
			soma=soma+matrizA[i][j]*vetorX[j];
		}

		vetorX[i]=(vetorB[i]-soma)/matrizA[i][i];	
	}

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
			cout << round(vetorB[i]);
		}else{
			cout << round(vetorB[i]) << "," ;
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