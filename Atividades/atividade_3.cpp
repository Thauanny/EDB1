#include <iostream>
#include <cstdlib>



int main(int argc, char *argv[]){

	int tam, t, tem, ntem, aux;

	tam = t = tem = ntem = 0;


	tam = atoi(argv[1]); //conversao do char argv[1] para inteiro
	t = atoi(argv[2]);

	size_t* lista = new size_t[tam]; //alocao dinamica do vetor no tamanho passado via argumento

	for (size_t i = 0; i < tam; ++i){//numeros aleatorios

		lista[i] = rand() % 500;
	}

	for (size_t i = 0; i < tam; ++i){//print lista

		std::cout<<lista[i]<< " - ";
	}


	
	for (size_t i = 0; i < tam - 1; i++){ //laco de ordenacao
		for (size_t j = i+1; j < tam; j++){
			
			if( lista[i] > lista[j]){

				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}



	//busca binaria

	int inicio = 0;
	int final = tam;
	int meio = (inicio + final)/2;

	while(inicio <= final){
		
		if(lista[meio] == t){

			std::cout<<meio;
		}
	}
   

	for (size_t i = 0; i < tam; ++i){//printar vetor

		std::cout<<"numero array: ";
		std::cout<<lista[i]<<std::endl;
		std::cout<<"numero t: ";
		std::cout<<t<<std::endl;

		if(lista[i] == t){

			tem = 1;

		}else{

			ntem = 0;
		}
	}

	std::cout<<std::endl;	

	std::cout<<"Resultado: ";

	if(tem == 1){//printar resultados

		std::cout<<tem;

	}else if(ntem == 0){

		std::cout<<ntem;
	}

	std::cout<<std::endl;


	return 0;
}