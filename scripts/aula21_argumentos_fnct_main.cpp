// programa vai receber paramentros do programa via prompt
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
// o  int argc fala a quantidade de parametros passados e o char *argv vai armaenar eles
// por padra o primeiro argumento é o nome do programa
int main(int argc, char *argv[]){

    cout << argv[0] << " <- aqui\n\n";//o primeiro é sempre o nome com o path
    cout << argv[1] << " <- aqui\n\n";//o segundo é o primeiro passado
    cout << argc << " <- aqui\n\n";// imprime a quantidade de parametros passados

    if(argc>1){
        if (!strcmp(argv[1],"sol")) cout << "vou ao clube \n";
        else cout <<"fico em casa!";
    }

    system("pause");
    return 0;
}