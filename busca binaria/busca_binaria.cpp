#include <iostream>

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

//busca recursiva

bool busca_binaria_recursiva(size_t* lista, size_t tam, size_t item){

	if(tam == 0){
		printf("Seu numero nao foi encontrado na lista\n");
		return false;
	}
	int ii = tam/2;
	if(lista[ii] == item){
		printf("Valor encontrado na posicao %d \n", ii);
		
		return true;
	}
	if (lista[ii] > item){
		printf("Valor na 1 parte do vetor %d ", tam/2);
		return busca_binaria_recursiva(lista,  tam/2, item);
		
	}
	if (lista[ii] < item){
		printf("Valor na 2 parte do vetor %d ", tam/2);
		return busca_binaria_recursiva(lista + ii + 1,  tam/2, item);
		
	}
	return false;
	
}

//busca iterativa

bool busca_binaria_iterativa(size_t* lista, size_t tam, size_t item){

	size_t begin = 0, end = tam - 1, item_enco = 0;

	while (begin <= end){ //condição de parada 

		int ii = ((begin + end) / 2); //calcula o meio da lista 

		if (lista[ii] == item){ //item achado

			printf("Valor encontrado na posicao %d \n", ii);
			item_enco = 1;
			return true;
			break;
			

		}else if(lista[ii] < item ){ //item esta a direita

			begin = ii + 1;
			item_enco = 0;


		}else if(lista[ii] > item ) { //item esta a esquerda

			end = ii - 1;
			item_enco = 0;

		}
	}

	if (item_enco == 0){

		printf("Seu numero nao foi encontrado na lista\n");
		return false;
	}

	return false;

}

int main(int argc, char const *argv[]){

	size_t tam = 10, aux = 0, item = 358;
	size_t lista[tam];

	std::cout<<"\nGerando os numeros... aguarde\n";

	num_aleatorios(lista, tam); //chamada da funcao que gera os numeros randomicos

	std::cout<<"\nOrdenando... aguarde\n\n";

	ordenacao(tam, lista, aux); //chamada da funcao de ordenacao

	mostrar_vetor(lista, tam);

	std::cout<<"\nBuscando... aguarde\n\n";
	busca_binaria_recursiva(lista, tam, item);//chamada da funcao que faz a busca binaria iterativa

	std::cout<<"\nConcluido";
	
	return 0;
}