using namespace std;

class Metodos{
	private:				
		float A; //Inicio do intervalo
        float B; //Final do intervalo
        float E;//Erro Padrao
        float a; //Parâmetro de ajuste
        int e; //Precisao Padrao (Numero de casas decimais)
		float f(float d, float a);							//funcao
		float df(float d, float a);							//derivada
		float p_f(float x, float e,int pf);							//ponto flutuante(truncamento ou arrendodamento)
	public:
		float Bissecao(float a, int e, int k_MAX,int pf, int escolha_mostrar);			//Metodo da Bissecao
		float PosicaoFalsa(float a, int e, int k_MAX,int pf, int escolha_mostrar);		//Metodo da Posicao Falsa
		float NewtonRaphson(float a, int e, int k_MAX,int pf, int escolha_mostrar);		//Metodo do Newton Raphson
		void setErro(float erro); //Seta a variável erro
		void setA(int intervalo1); //Seta a variável A do intervalo
		void setB(int intervalo2); //Seta a variável B do intervalo
};

//Retorna o cálculo da função
float Metodos::f(float d, float a){
	return (a*d - d*log(d));
}
//Retorna a derivada da função
float Metodos::df(float d, float a){
	return (a - log(d) - 1);
}

//Retorna o número x truncado ou arredondado dependendo da escolha feita
float Metodos::p_f(float x, float e, int pf){
	if(pf == 0)
		return trunc(e*x)/e;
	else
		return round(e*x)/e;
}
//Seta o erro que será usado no cálculo dos métodos
void Metodos::setErro(float erro){
	this->E = erro;
}
//Seta o A do intervalo [A,B] que será usado no cálculo dos métodos
void Metodos::setA(int intervalo1){
	this->A = intervalo1;
}
//Seta o B do intervalo [A,B] que será usado no cálculo dos métodos
void Metodos::setB(int intervalo2){
	this->B = intervalo2;
}

//Calcula a raiz pelo método da bisseção para os valores passados (a: parâmetro de ajuste, e: quantidade de casas, k_MAX: número máximo de iterações, pf: escolha (arredondamento ou truncamento))
float Metodos::Bissecao(float a, int e, int k_MAX, int pf, int escolha_mostrar){
	int e_cout = e;
	e = pow(10,e);
	float intervD, d, Fd;
	int k = 0;
    float A1 = p_f((A),e,pf);
    float B1 = p_f((B),e,pf);
	float FA = p_f((f(A1,a)),e,pf);
	float FB = p_f((f(B1,a)),e,pf);
	if(escolha_mostrar==0){
		if (FA*FB > 0){
			cout << endl; cout << "Erro: funcao nao converge" << endl; cout << endl;
		}		
	}
	if (FA*FB > 0){
		return 0;
	}	
	intervD = abs(B1-A1);

	if(escolha_mostrar==0){
	 	if(e_cout%2==0){
			cout << " |" << setfill (' ') << setw (2) << "K" << setfill (' ') << setw (2) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "A" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "FA" << setfill (' ') << setw (floor((e_cout/2)+1)-1) << ' ' << setfill(' ') << setw(5) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "B" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "FB" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "d" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "Fd" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|" << setfill(' ') << setw((e_cout/2)) << ' ' << "intervD" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << "|";
			cout << endl ;
		}else{
			cout << " |" << setfill (' ') << setw (2) << "K" << setfill (' ') << setw (2) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "A" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "FA" << setfill (' ') << setw (floor((e_cout/2)+1)-1) << ' ' << setfill(' ') << setw(5) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "B" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "FB" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "d" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
			cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "Fd" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill(' ') << setw((e_cout/2)+1) << ' ' << "intervD" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' '  << "|";
			cout << endl ;

		}
	}

	do{
		d = p_f(((A1+B1)/2),e,pf);
		Fd = p_f((f(d,a)),e,pf);
		cout<<scientific;
        cout.precision(e_cout);
     	if(escolha_mostrar==0){
      		cout << " | " << k << " | " << A1 << " | " << FA << " | " << B1 << " | " << FB << " | " << d << " | " << Fd << "  | " << intervD << " |" << endl;
      	}
		if (FA*Fd > 0){
			A1 = d;
			FA = Fd;
		}
		else{
			B1 = d;
			FB = Fd;
		}
		intervD = p_f((intervD/2),e,pf);
		k++;
	} while(abs(Fd) > E and intervD > E and k <= k_MAX);
	return d;
}

//Calcula a raiz pelo método da Posição Falsa para os valores passados (a: parâmetro de ajuste, e: quantidade de casas, k_MAX: número máximo de iterações, pf: escolha (arredondamento ou truncamento))
float Metodos::PosicaoFalsa(float a, int e, int k_MAX, int pf, int escolha_mostrar){
	int e_cout = e;
	e = pow(10,e);
	float intervD, d, Fd;
	int k = 0;
    float E2 = E;
	float A1 = p_f((A),e,pf);
	float B1 = p_f((B),e,pf);
    float FA = p_f((f(A,a)),e,pf);
    float FB = p_f((f(B,a)),e,pf);

    if(escolha_mostrar==0){
    	if(FA*FB > 0 ){
			cout << endl; cout << "Erro: funcao nao converge" << endl; cout << endl;
   		}
    }
    if(FA*FB > 0 ){
		return 0;    
	}
    intervD = abs(B1-A);

    if(intervD < E or abs(FA) < E2){
        d = A1;
    }

    else if(abs(FB) < E2){
        d = B1;
    }

    else{
    	if(escolha_mostrar == 0){
			if(e_cout%2==0){
				cout << " |" << setfill (' ') << setw (2) << "K" << setfill (' ') << setw (2) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "A" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "FA" << setfill (' ') << setw (floor((e_cout/2)+1)-1) << ' ' << setfill(' ') << setw(5) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "B" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "FB" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)) << "d" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "Fd" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|" << setfill(' ') << setw((e_cout/2)) << ' ' << "intervD" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << "|";
				cout << endl ;
			}else{
				cout << " |" << setfill (' ') << setw (2) << "K" << setfill (' ') << setw (2) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "A" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "FA" << setfill (' ') << setw (floor((e_cout/2)+1)-1) << ' ' << setfill(' ') << setw(5) << "|" << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "B" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "FB" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+1) << "d" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|";
				cout << setfill (' ') << setw (3) << ' ' << setfill(' ') << setw((e_cout/2)+2) << "Fd" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' ' << setfill(' ') << setw(5) << "|"  << setfill(' ') << setw((e_cout/2)+1) << ' ' << "intervD" << setfill (' ') << setw (floor((e_cout/2)+1)) << ' '  << "|";
				cout << endl ;
			}
		}
	    do{  
	        d = p_f(((((A1*FB)-(B1*FA))/(FB-FA))),e,pf); 
	        Fd = p_f((f(d,a)),e,pf);
	        if(escolha_mostrar ==0){
	        	cout<<scientific;
	      	 	cout.precision(e_cout);
	       		cout << " | " << k << " | " << A1 << " | " << FA << " | " << B1 << " | " << FB << " | " << d << " | " << Fd << "  | " << intervD << " |" << endl;
	        }
			 if(FA*Fd>0){
	            A1 = d;
	            FA = Fd;
	        }else{
	            B1 = d;
	            FB = Fd;
	        }
	        intervD = p_f((abs(B1-A1)),e,pf);
	        if(intervD <= E){
	            d = A1;
	        }
	        k++; 
	    } while(intervD > E and k_MAX >= k and abs(Fd) >= E2);
    }
	return d;
}
//Calcula a raiz pelo método do Newton Raphson para os valores passados (a: parâmetro de ajuste, e: quantidade de casas, k_MAX: número máximo de iterações, pf: escolha (arredondamento ou truncamento))
float Metodos::NewtonRaphson(float a, int e, int k_MAX, int pf, int escolha_mostrar){
	int e_cout = e;
	e = pow(10,e);
	float intervD, d;
    int k = 0;
    float E2 = E;
    float X0 = p_f(((A+B)/2),e,pf);
    float FX0 = p_f((f(X0,a)),e,pf);
    float DX0 = p_f(df(X0,a),e,pf);

    if(escolha_mostrar==0){
  		if(f(A,a)*(f(B,a)) > 0 ){
			cout << endl; cout << "Erro: funcao nao converge" << endl;
    	}	
    }
    if(f(A,a)*(f(B,a)) > 0 ){
    	return 0;
    }
    else if(abs(FX0) < E){
        d = X0;           
    }

    else{
    	if(escolha_mostrar==0){
    		cout << "| k |  x  | f(x) | \n";
    	}
        float X1,FX1;
    	X1 = p_f((A+B)/2,e,pf);
        do{
      		X0 = X1;
      		FX0 = p_f((f(X0,a)),e,pf);
    		DX0 = p_f((df(X0,a)),e,pf);
            X1 = p_f((X0-(FX0/DX0)),e,pf);
            FX1 = p_f((f(X1,a)),e,pf);
            if(escolha_mostrar==0){
            	cout<<scientific;
            	cout.precision(e_cout);
            	cout << "| " << k << " | " << X0 << " | " << FX0 << " | \n";
        	}
            intervD = abs(X1-X0);
            k++;
              
        } while(abs(FX0) > E and intervD > E2 and k <= k_MAX);
          
        d = X0;
    }
   	return d;
}
