#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>      // std::setfill, std::setw
#include "Metodo.h"
#include "LU.h"
#include "LDP.h"


using namespace std;

void resultado(float* vetor,int n);
void imprimir_vetor(int n, float* vetor, char x);
void imprimir_matriz(int n, float** matriz, char x);


int main(int argc, char const *argv[]){
	cout << "\033c";
	system("clear");
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"                   Alpha Rocket System � 2.0 \n \n \n ";
	cout<<"               The Best System To Monitor Your Rocket\n";
	cout<<"---------------------------------------------------------------------------\n";
	
	cout << "Digite o N da matriz NxN: " << endl;
	int n;
	cin >> n;

	int esc_metodo;
	float x;

	float vetorB[n];
	float vetorB2[n];
	float vetorB3[3] = {16,38,38};
	float vetorB4[3] = {16,38,38};
	float matriz_padrao[3][3] = {{20,7,9},{7,30,8},{9,8,30}};
	
	float** matrizA = (float**) malloc(n * sizeof(float*));
	float** matrizA2 = (float**) malloc(n * sizeof(float*));
	float** matrizA3 = (float**) malloc(3 * sizeof(float*));
	float** matrizA4 = (float**) malloc(3 * sizeof(float*));

    for(int i = 0; i < n; i++){
        matrizA[i] = (float*) malloc(n * sizeof(float));
        matrizA2[i] = (float*) malloc(n * sizeof(float));
    }

    for(int i = 0; i < 3; i++){
		matrizA3[i] = (float*) malloc(3 * sizeof(float));
		matrizA4[i] = (float*) malloc(3 * sizeof(float));
	}

	cout << "Digite o VetorB: " << endl;
	for (int i = 0; i < n; i++){
		cin >> x;
		vetorB[i] = x; 
		vetorB2[i] = x; 	
	}

 	cout << "Digite a MatrizA: " << endl;
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
			matrizA[i][j] = x;	
			matrizA2[i][j] = x;	
			matrizA3[i][j] = matriz_padrao[i][j];
			matrizA4[i][j] = matriz_padrao[i][j];
		}	
	}

	LU *raiz = new LU(n, vetorB, matrizA);
	LDP *raiz2 = new LDP(n, vetorB2, matrizA2);
	LU *raiz3 = new LU(n, vetorB3, matrizA3);
	LDP *raiz4 = new LDP(n, vetorB4, matrizA4);

	cout << "\033c";
	system("clear");
	
		while (esc_metodo != 3){
			cout << "-----------------------------------------------\n";
			cout<< "Quadro Resposta: \n";
			cout<< "------------------------------------------------\n";
			cout << "Escolha:" << endl;
			cout << "0 - LU" << endl;
			cout << "1 - LU modificado" << endl;
			cout << "2 - LU e LDP Calibrado" << endl;
			cout << "3 - Para sair" << endl;
		cin >> esc_metodo;
		cout << endl;
		
		cout << "\033c";
		system("clear");
		if(esc_metodo==0){
			cout << endl;
			cout << "-----------Metodo LU-----------" << endl;
			cout << endl;
			raiz -> LU_piv();
			imprimir_matriz(n, raiz->matrizA, 'A');
			imprimir_vetor(n, raiz->vetorB, 'B');
			imprimir_vetor(n, raiz->vetorY, 'Y');
			imprimir_vetor(n, raiz->vetorX, 'X');
			cin.ignore(1e10, '\n');
			cin.ignore(1e10, '\n');
			system("clear");
			cout << "------------------RESULTADO DO METODO LU - VETORX------------------" << endl;
			resultado(raiz->vetorX, n);
			cin.ignore(1e10, '\n');
			system("clear");
		}
		else if(esc_metodo==1){
			cout << endl;
			cout << "-----------Metodo LU MODIFICADO-----------" << endl;
			cout << endl;
			raiz2 -> LDP_piv();
			imprimir_matriz(n, raiz2->matrizL,'L');
			imprimir_matriz(n, raiz2->matrizD,'D');
		    imprimir_matriz(n, raiz2->matrizP,'P');
			imprimir_matriz(n, raiz2->matrizA, 'A');
			imprimir_vetor(n, raiz2->vetorB, 'B');
			imprimir_vetor(n, raiz2->vetorX, 'X');
			cin.ignore(1e10, '\n');
			cin.ignore(1e10, '\n');
			system("clear");
			cout << "------------------RESULTADO DO METODO LU MODIFICADO - VETORX------------------" << endl;
			resultado(raiz2->vetorX, n);
			cin.ignore(1e10, '\n');
			system("clear");
			
		}
		else if(esc_metodo==2){
			cout << endl;
			cout << "-----------Metodo LU CALIBRADO-----------" << endl;
			cout << endl;
			raiz3 -> LU_piv();
			imprimir_matriz(n, raiz3->matrizA, 'A');
			imprimir_vetor(n, raiz3->vetorB, 'B');
			imprimir_vetor(n, raiz3->vetorY, 'Y');
			imprimir_vetor(n, raiz3->vetorX, 'X');
			cin.ignore(1e10, '\n');
			cin.ignore(1e10, '\n');
			system("clear");
			cout << "------------------RESULTADO DO METODO LU CALIBRADO - VETORX------------------" << endl;
			resultado(raiz3->vetorX, n);
			cin.ignore(1e10, '\n');
			system("clear");
			cout << endl;
			cout << "-----------Metodo LU MODIFICADO CALIBRADO-----------" << endl;
			cout << endl;
			raiz4 -> LDP_piv();
			imprimir_matriz(n, raiz4->matrizL,'L');
			imprimir_matriz(n, raiz4->matrizD,'D');
		    imprimir_matriz(n, raiz4->matrizP,'P');
			imprimir_matriz(n, raiz4->matrizA, 'A');
			imprimir_vetor(n, raiz4->vetorB, 'B');
			imprimir_vetor(n, raiz4->vetorX, 'X');
			cin.ignore(1e10, '\n');
			system("clear");
			cout << "------------------RESULTADO DO METODO LU MODIFICADO CALIBRADO - VETORX------------------" << endl;
			resultado(raiz4->vetorX, n);
			cin.ignore(1e10, '\n');
			system("clear");
		}

	}

	return 0;

}

void imprimir_vetor(int n, float* vetor, char x){
	cout << endl;
	cout << "-----------Vetor " << x <<  "-----------" << endl;
	cout << endl;
	cout << "(";
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout << vetor[i];
		}else{
			cout << vetor[i]<< "," ;
		}
	}
	cout << ")" << endl;
	cout << endl;
}


void imprimir_matriz(int n, float** matriz, char x){
	cout << endl;
	cout << "-----------Matriz " << x <<  "-----------" << endl;
	for (int i=0;i<n;i++){
		cout << endl;
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout << matriz[i][j] << "," ;
			}
			else{
				cout << matriz[i][j] ;
			}		
		}
	}
	cout << endl;
}

void resultado(float* vetor,int n){
	int count = 0;
	for(int i = 0; i<n; i++){
		if(abs(vetor[i])>2){
			count++;
		}
	}
	if(count!=0){
		cout << " \n Nas partes com seus respectivos deslocamentos: \n";
		for(int i = 0; i < n; i++){
			if(abs(vetor[i]) > 2){
				if(i == n-1){
					cout << "\n Parte: " << i+1 << " - Deslocamento: " << vetor[i];
				}else{
				
					cout << " \n Parte: " << i+1 << " - Deslocamento: " << vetor[i] << endl;
				}
			}
		}
		cout << "\n\n ele explode, pois os seus deslocamentos em módulo sao maiores que 2" << endl;
	}else{
		cout << "\nO Foguete não explode, pois os seus deslocamentos em módulo são menores que 2" << endl;
	}

	
}