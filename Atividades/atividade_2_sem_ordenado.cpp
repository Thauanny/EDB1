#include <iostream>
#include <cstdlib>


//inicio funcao para gerar os numeros randomicos

void gerar_numeros_randomicos(size_t* lista_, size_t tam_){
	for (size_t i = 0; i < tam_; ++i){
		
		lista_[i] = rand() % 500;
	}
}

//fim da funcao pra gerar numeros das funcoes 

//inicio funcao para mostrar os valores dentro do vetor lista

void mostrar_vetor(size_t* lista_, size_t tam_){

	for (size_t i = 0; i < tam_; ++i){
		
		std::cout<<lista_[i]<<" ";
	}

	std::cout<<std::endl;
}

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

	size_t tam, soma, aux;
	short tem, ntem; 
	

	tam = soma = aux = 0;
	tem = ntem = 0;


	tam = atoi(argv[1]); //conversao do char argv[1] para size_t, para ver o tamanho do vetor, via linha de comando
	soma = atoi(argv[2]);//conversao do char argv[2] para size_t, para poder comparar se existe a soma que de esse numero, via linha de comando

	size_t* lista = new size_t[tam]; //alocao dinamica do vetor no tamanho passado via argumento

	gerar_numeros_randomicos(lista, tam); //chamada da funcao que gera os numeros randomicos

	mostrar_vetor(lista, tam);//chamada da funcao para mostrar vetor	

	verificar_soma(lista, tam, soma, &tem, &ntem);// chamada da funcao para veriricar a soma

	mostrar_resultado(&tem, &ntem);//mostrar os resultados

	delete[] lista; //limpar a memoria


	
	return 0;
}