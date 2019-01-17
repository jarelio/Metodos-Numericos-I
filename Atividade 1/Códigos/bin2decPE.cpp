#include <iostream>
#define NUM_ELEMENTS(X) (sizeof(X) / sizeof(X[0]))

using namespace std;

/*
Ideia: 
a = numero_binario[0=n]
a2 = 2*a + numero_binario[1=n+1]
a3 = 2*a2 + numero_binario[2=n+2]
a4 = 2*a3 + numero_binario[3=n+3]
retorna a4 pois o n+3+1 = n+4 = 4 = numero_elementos
...
*/

int numero_binario[] = {1,0,1,1};
int numero_elementos = NUM_ELEMENTS(numero_binario);

int horner_bin(int a, int n){
	if (n == numero_elementos){
		return a;
	}
	return horner_bin(((2*a) + numero_binario[n]),n+1);
}

int main(){
	int n = 0;
	cout << horner_bin(numero_binario[n], (n+1)) << '\n';
}

