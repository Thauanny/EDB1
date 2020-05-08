#include <iostream>

/*
	Busca Binaria iterativa.
	Tamanho do vetor e item desejado a ser localizado passar por linha de comando.
	Estudo para a materia EDB1 - UFRN
	Thauanny Kyssy Ramos Pereira

*/

//gera numeros "aleatorios" até 500

void num_aleatorios(size_t* lista, size_t tam_){

	for (size_t i = 0; i < tam_; ++i){//numeros aleatorios

		lista[i] = rand() % 500;
	}

}

//funcao ordenacao
void ordenacao(size_t tam_, size_t* lista, size_t aux){

	for (size_t i = 0; i < tam_ - 1; ++i){
		for (size_t j = i+1; j < tam_; ++j){
			
			if (lista[i] > lista[j]){
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}
}

//mostra o vetor para visualizar melhor o exemplo 

void mostrar_vetor(size_t* lista_, size_t tam_){

	for (size_t i = 0; i < tam_; ++i){
		
		std::cout<<lista_[i]<<" ";
	}

	std::cout<<std::endl;
}


//busca iterativa

void busca_binaria_iterativa(size_t* lista, size_t tam, size_t item){

	size_t begin = 0, end = tam - 1, item_enco = 0;

	while (begin <= end){ //condição de parada 

		int i = ((begin + end) / 2); //calcula o meio da lista 

		if (lista[i] == item){ //item achado

			printf("Valor encontrado na posicao %d \n", i);
			item_enco = 1;
			break;

		}else if(lista[i] < item ){ //item esta a direita

			begin = i + 1;
			item_enco = 0;


		}else if(lista[i] > item ) { //item esta a esquerda

			end = i - 1;
			item_enco = 0;

		}
	}

	if (item_enco == 0){

		printf("Seu numero nao foi encontrado na lista\n");
	}

}

int main(int argc, char const *argv[]){

	size_t tam = 0, aux = 0, item = 0;

	tam = atoi(argv[1]); // pega o numero da linha de comando e converte para int
	item = atoi(argv[2]); //pega o numero da linha de comando e converte para int

 	size_t* lista = new size_t[tam]; //vetor alocado dinamicamente 

	std::cout<<"\nGerando os numeros... aguarde\n";

	num_aleatorios(lista, tam); //chamada da funcao que gera os numeros randomicos

	std::cout<<"\nOrdenando... aguarde\n\n";

	ordenacao(tam, lista, aux); //chamada da funcao de ordenacao

	mostrar_vetor(lista, tam);

	std::cout<<"\nBuscando... aguarde\n\n";
	busca_binaria_iterativa(lista, tam, item);//chamada da funcao que faz a busca binaria iterativa

	std::cout<<"\nConcluido";
	

	delete[] lista; //limpar a memoria
	
	return 0;
}