
#include <iostream>

using namespace std;


bool busca_sequencial_crescente(int * lista, int tam, int x){
    
    if(tam <= 0) return false;
    if (*lista == x) return true;

    return busca_sequencial_crescente(lista+1, tam-1, x); 

    /*
    * lista+1 vai para o proximo endereço na memoria, 
    * tam-1 diminui o espaço de busca do vetor, 
    * x numero que quero achar
    */

}



bool busca_sequencial_decrescente(int * lista, int tam, int x){
    
    if(tam == 0) return false;
    if (lista[tam-1] == x) return true;
    return busca_sequencial_decrescente(lista, tam-1, x); 

    /*
    * Quando entra pega o tamanho maximo do vetor se for tamanho 7, 
    * entao tem 6 ([0][1][2][3][4][5][6]) -> lista[tam-1]  que é o [6].
    * Na recursiva vai para o tam-1 (6), mas como foi mostrado antes, 
    * vai para lista[tam-1] que é o [5].
    */
}

void mostrar_vetor(int * lista, int tam){//mostrar vetor

	for (int i = 0; i < tam; ++i){
		
		cout<<lista[i]<<" ";
	}

	cout<<endl;
}


void num_aleatorios(int * lista, int  tam){

	for (int i = 0; i < tam; ++i){//numeros aleatorios

		lista[i] = rand() % 500;
	}

}

int main(){
    int tam = 7;
    int lista[tam];

    num_aleatorios(lista, tam);
    mostrar_vetor(lista, tam); 
    cout << "Busca Sequencial crescente procura o 478: " << busca_sequencial_crescente(lista, 7, 478) << endl;
    cout << "Busca Sequencial decrescente procura o 0: " << busca_sequencial_decrescente(lista, 7, 1) << endl;

    return 0;
}
