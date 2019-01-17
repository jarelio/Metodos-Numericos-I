using namespace std;
 
class Compara {
	public:
		float erroabs(float r,float a);
};

//Função que cálcula o Erro Absoluto das raízes calculadas pelos Métodos pela raiz calculada por este computador diretamente na função (e^a)
float Compara::erroabs (float r ,float a){
	float f = pow(M_E,a);
	float ea=abs(r-f);
	return ea;
}
