#include <iostream>


void num_aleatorios(size_t* lista, size_t tam_){

    for (size_t i = 0; i < tam_; ++i){//numeros aleatorios

        lista[i] = rand() % 500;
    }

}
void mostrar_vetor(size_t* lista_, size_t tam_){

    for (size_t i = 0; i < tam_; ++i){
        
        std::cout<<lista_[i]<<" ";
    }

    std::cout<<std::endl;
}

void troca(size_t* lista, size_t ii, size_t jj){
    size_t var1;
    var1 = lista[ii];
    lista[ii] = lista[jj];
    lista[jj] = var1;
}

void bubble_sort(size_t* lista, size_t tam){
    bool conflito = false;
    do{
        for (size_t ii = 0; ii < tam-1; ii++){

            if (lista[ii] > lista[ii+1]){
                
                troca(lista, ii, ii+1);
                conflito = true;
                mostrar_vetor(lista, tam);
                std::cout <<"";
                std::cout << conflito;
                
            }
            
        }
                     
    }
    while(conflito != true);
}





int main(){

    size_t tam = 10;
	size_t lista[tam];

    std::cout<<"\nGerando os numeros... aguarde\n";

	num_aleatorios(lista, tam); //chamada da funcao que gera os numeros randomicos

	mostrar_vetor(lista, tam);

    std::cout<<"\nOrdenando... aguarde\n\n";

    bubble_sort(lista, tam);
    
    mostrar_vetor(lista, tam);


    
    return 0;
}
