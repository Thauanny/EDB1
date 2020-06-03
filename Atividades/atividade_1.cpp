#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){

	int aux, tam;

	tam = atoi(argv[1]); //conversao do char argv[1] para inteiro

	size_t* lista = new size_t[tam]; //alocao dinamica do vetor no tamanho passado via argumento

	for (size_t i = 0; i < tam; ++i){//numeros aleatorios

		lista[i] = rand() % 100;
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

	for (size_t i = 0; i < tam; ++i){ //impressao do vetor ja ordenado
		std:: cout << lista[i];
		std:: cout << " ";
	}

	return 0;
}