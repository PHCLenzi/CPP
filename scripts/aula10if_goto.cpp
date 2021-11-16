#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    float n1 ,n2 ,res;
    char opc;

    inicio: //dois pontos para indicar que é um label
    // comandos do dos
    system("cls");// comando de sistema para lipar a tela

    cout << "Digite o valor da nota 1: ";
    cin >> n1;
    
    cout << "Digite o valor da nota 2: ";
    cin >> n2;

    res = (n1+n2)/2;

    if( res >= 60){
        cout << "\n Anulo aprovado \n";
    }else if(res>= 40){
         cout << "\n Anulo esta de recuperacao \n";
    }else{
        cout << "\n Anulo reprovado \n";
    }

    char resp;
    cout << "\nDeve-se adicionar outra nota? s ou n ? ";
    cin >> resp;

    if (resp == 's' or resp == 'S'){
        goto inicio;
    }

    return 0;
}
