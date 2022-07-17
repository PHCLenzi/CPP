#include <iostream>
# include <cstdlib>//cstdlib é a versao mais recente de cstdlib, funcao que converte variaveis, calloc malloc, free, realloc
# include <ctime>//srand(timr(NULL));

using namespace std;

int main(){

    double num;
    char numero[80];

    cin >> numero;

    //num = atof(numero);//converte
    num = strtod(numero, NULL);
    //cout << num << endl;

    srand(time(NULL));
    for (int i=0;i<10; i++){
        cout << rand()%100 << endl;

    }
    cout << "\n" << "Realocacao dinamica " <<  "\n" <<  "\n" << endl;

    int tam=10,num1;
    int *vector;

    //vector = (int*)calloc(tam,sizeof(int));
    vector = (int*)malloc(sizeof(int));//nao preciso falar o tamanho
     for (int i=0;i<tam; i++){
        vector[i] = rand()%100;
        cout << rand()%100 << endl;

    }
    free(vector); //libera a memoria

	return 0;

}
