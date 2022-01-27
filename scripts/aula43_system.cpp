#include <iostream>
#include <cstdlib>// usado para acessar comandos do sistema
#include <stdlib.h>

using namespace std;

int main(){
    system("cls");// Comando do sistema que limpa o terminal.
    system("dir");// mostra o que tem no diretório
    //system("color ?");// exibe as funções de color do system
    system("color 06");// muda a cor da fonte e de fundo do sistema
    system("pause");// pausa o código até o usuário entrar com alguma tecla
    
    return 0;
}