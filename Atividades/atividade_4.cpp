#include <iostream>

struct Carro{

	std::string nome;
	unsigned short ano;
	
};


struct CarrosDB{
	int capacidade;
	int quantidade;
	Carro* carro;

	CarrosDB(size_t capacidade):
		capacidade(capacidade), quantidade(0){
			carros = new Carro[capacidade];
		}

	void quanti_carros(){}
	void capaci_max(){}
	void verifca_ano(){}

};

~CarrosDB(){
	delete [] carros;
}


int main(int argc, char const *argv[]){

	carro c;
	c.nome = "fusca"
	c.ano = 1989;

	
	return 0;
}