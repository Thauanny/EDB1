#include <iostream>


void num_aleatorios(int* lista, int tam_){

    for (int i = 0; i < tam_; ++i){//numeros aleatorios

        lista[i] = rand() % 500;
    }

}
void mostrar_vetor(int* lista_, int tam_){

    for (int i = 0; i < tam_; ++i){
        
        std::cout<<lista_[i]<<" ";
    }

    std::cout<<std::endl;
}

void troca(int* lista, int ii, int jj){

    int var1;
    var1 = lista[jj];
    lista[jj] = lista[ii];
    lista[ii] = var1;
}

void insertion_sort(int* lista, int tam){

    for (int ii = tam-1; ii >= 0; ii--){
        
        for (int jj = ii; lista[jj] > lista[jj+1] && jj < tam-1 ; jj++){

            troca(lista, jj, jj+1);
            
        }
        
        
    }
    
}
   




int main(){

    int tam = 10;
	int lista[tam];

    std::cout<<"\nGerando os numeros... aguarde\n";

	num_aleatorios(lista, tam); //chamada da funcao que gera os numeros randomicos

	mostrar_vetor(lista, tam);

    std::cout<<"\nOrdenando... aguarde\n\n";

    insertion_sort(lista, tam);
    
    mostrar_vetor(lista, tam);


    
    return 0;
}
