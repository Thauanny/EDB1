#include <iostream>
#include <cstdlib>
#include <chrono>

//inicio funcao para gerar os numeros randomicos

void gerar_numeros_randomicos(size_t* lista_, size_t tam_){
	for (size_t i = 0; i < tam_; ++i){
		
		lista_[i] = rand() % 500;
	}
}

//fim da funcao pra gerar numeros das funcoes 

//inicio da funcao de ordenacao do vetor lista, que contem os numeros randomicos

void ordenacao_da_lista(size_t* lista_, size_t tam_, size_t aux_){

	for (size_t i = 0; i < tam_ - 1; ++i){
		for (size_t j = i+1; j < tam_; ++j){
			
			if (lista_[i]>lista_[j]){
				
				aux_ = lista_[i];
				lista_[i] = lista_[j];
				lista_[j] = aux_;
			}
		}		
	}
}

//fim da funcao de ordenacao do vetor lista, que contem os numeros randomicos

//inicio funcao para mostrar os valores dentro do vetor lista

/*void mostrar_vetor(size_t* lista_, size_t tam_){

	for (size_t i = 0; i < tam_; ++i){
		
		std::cout<<lista_[i]<<" ";
	}

	std::cout<<std::endl;
}
*/

//fim funcao para mostrar os valores dentro do vetor lista

//inicio verificacao se existe dois numeros somados dentro do vetor se e igual a numero soma
void verificar_soma(size_t* lista_, size_t tam_, size_t soma_, short* tem_, short* ntem_){

	for (size_t i = 0, j = tam_-1; i < tam_ && j>=0; ){

		if (lista_[i] + lista_[j] > soma_){

			j--;
			*ntem_ = 0;

		}else if(lista_[i] + lista_[j] < soma_){

			i++;
			*ntem_ = 0;

		}else if(lista_[i] + lista_[j] == soma_){

			*tem_ = 1;
			break;
		}
	}

	std::cout<<std::endl;
}

//fim verificacao se existe dois numeros somados dentro do vetor se e igual a numero soma

//inicio mostrar os resutados

void mostrar_resultado(short* tem_, short* ntem_){

	std::cout<<"Resultado: ";

	if(*tem_ == 1){

		std::cout<<*tem_;

	}else if(*ntem_ == 0){

		std::cout<<*ntem_;
	}

	std::cout<<std::endl;

}

//fim mostrar os resutados

int main(int argc, char *argv[]){

	auto start = std::chrono::steady_clock::now();//comeco do primeiro temporizador 

	size_t tam, soma, aux;
	short tem, ntem; 
	

	tam = soma = aux = 0;
	tem = ntem = 0;


	tam = atoi(argv[1]); //conversao do char argv[1] para size_t, para ver o tamanho do vetor, via linha de comando
	soma = atoi(argv[2]);//conversao do char argv[2] para size_t, para poder comparar se existe a soma que de esse numero, via linha de comando

	size_t* lista = new size_t[tam]; //alocao dinamica do vetor no tamanho passado via argumento

	std::cout<<"\nGerando os numeros... aguarde\n";

	gerar_numeros_randomicos(lista, tam); //chamada da funcao que gera os numeros randomicos

	auto end = std::chrono::steady_clock::now();//fim do primeiro temporizador 
	std::chrono::duration<double> tempo_final_1 = end - start;//armezena o tempo de execusao antes de ordenacao

	std::cout<<"\nOrdenando... aguarde\n";

	ordenacao_da_lista(lista, tam, aux); //chamada da funcao de ordenacao

	auto start1 = std::chrono::steady_clock::now();//comeco do segundo temporizador 

	//mostrar_vetor(lista, tam);//chamada da funcao para mostrar vetor	

	std::cout<<"\nVerificando se existe a soma... aguarde\n";

	verificar_soma(lista, tam, soma, &tem, &ntem);// chamada da funcao para veriricar a soma

	mostrar_resultado(&tem, &ntem);//mostrar os resultados

	delete[] lista; //limpar a memoria

	auto end1 = std::chrono::steady_clock::now();//final do segundo temporizador 
	std::chrono::duration<double> tempo_final_2 = end1 - start1;//armezena o tempo de execusaodepois depois ordenacao
	std::cout<<"Tempo final: "<<tempo_final_2.count() + tempo_final_1.count()<< "s\n";//mostra o resultado do tempo de execusao sem o tempo de ordenacao

	return 0;
}