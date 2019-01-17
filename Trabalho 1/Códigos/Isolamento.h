using namespace std;

class Isolamento {
	public:
		int calculaA(float a); //Calcula o A do intervalo [A,B] baseado no parâmetro de ajuste a
		int calculaB(float a); //Calcula o B do intervalo [A,B] baseado no parâmetro de ajuste a
	private:
		//Struct que salva o valor a,b do intervalo
		struct intervalo{
			int a;
			int b;
		};
		typedef struct intervalo Intervalo;
		float calculaFuncao(float a); //Calcula o isolamento baseado no parâmetro a e retorna os valores de [A,B] do intervalo
		Intervalo calculaIsolamento(float a, Intervalo intervalo1); //Calcula o isolamento baseado no parâmetro a e retorna os valores de [A,B] do intervalo
		Intervalo calculaIsolamentoMain(float a); //Main que recebe o valor de A e verifica se o intervalo foi calculado ou não
};

//Calcula o A do intervalo [A,B] baseado no parâmetro de ajuste a
int Isolamento::calculaA (float a){
	Intervalo intervaloA;
	intervaloA = calculaIsolamentoMain(a);
	return intervaloA.a;
}

//Calcula o B do intervalo [A,B] baseado no parâmetro de ajuste a
int Isolamento::calculaB (float a){
	Intervalo intervaloA;
	intervaloA = calculaIsolamentoMain(a);
	return intervaloA.b;
}

//Calcula o valor da função aplicado em a para encontrar a sua raiz
float Isolamento::calculaFuncao(float a){
	return pow(M_E,a);
}

//Calcula o isolamento baseado no parâmetro a e retorna os valores de [A,B] do intervalo
Isolamento::Intervalo Isolamento::calculaIsolamento(float a,Isolamento::Intervalo intervalo1){
	intervalo1.a = floor(calculaFuncao(a));
	intervalo1.b = (intervalo1.a+1);
	return intervalo1;
}

//Main que recebe o valor de A e verifica se o intervalo foi ou (pode ser) calculado ou não e retorna os valores [A,B]
Isolamento::Intervalo Isolamento::calculaIsolamentoMain(float a){
	Intervalo intervalo1;
	intervalo1.a = 0;
	intervalo1.b = 0;
	intervalo1 = calculaIsolamento(a,intervalo1);
	return intervalo1;
}