#include <iostream>
# include <cstdlib>//cstdlib � a versao mais recente de cstdlib, funcao que converte variaveis, calloc malloc, free, realloc
# include <ctime>//srand(timr(NULL));


/* 
Aula - biblioteca <cstdlib>
fonte: https://www.youtube.com/watch?v=m740X3wtX10&list=PLx4x_zx8csUjczg1qPHavU1vw1IkBcm40&index=74&ab_channel=CFBCursos

func: <de conversão>: atof, strtod, srand
func: <num aleatórios>: rand.
func: <gerenciamento dinamico de momeria>: calloc, malloc, free, realloc.



*/

using namespace std;

int main(){

    double num;
    char numero[80];


    cin >> numero;

    //num = atof(numero);//converte de char para float ou double
    num = strtod(numero, NULL);// string to double 
    //cout << num << endl;

    srand(time(NULL)); // define a semente de números aletorios
    for (int i=0;i<10; i++){
        cout << rand()%100 << endl; // gera aleatorio de 0 a 100

    }

    cout << "\n" << "Realocacao dinamica " <<  "\n" <<  "\n" << endl;

    int tam=10,num1;
    int *vector;// crio o ponteiro de inicio de um vetor, bom para alocacao dinamica
    // int vetor[10];// crio um vetor determinando o tamanho dele.

    //vector = (int*)calloc(tam,sizeof(int));// depois define o tamanho do vetor 
    vector = (int*)malloc(sizeof(int));//nao preciso falar o tamanho

     for (int i=0;i<tam; i++){
        vector[i] = rand()%100;
        cout << rand()%100 << endl;

    }
    free(vector); //libera a memoria

	return 0;

}
