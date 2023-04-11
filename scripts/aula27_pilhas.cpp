#include <iostream>
#include <stack>//para trabalhar compilhas
// pilha, primeiro entra é o ultimo que sai
using namespace std;
// push,pop, size, empty,top
int main(){
    
    stack <string> cartas; //nao precisa falar o parametro

    if(cartas.empty()) cout << "A pilhaesta vazia! \n";
    else cout << "A pilhaesta nao esta vazia!\n";

    cartas.push("rei de copas");//coloca caisa dentro da pilha
    cartas.push("rei de espadas");
    cartas.push("rei de ouro");
    cartas.push("rei de paus");

    cout << "Tamanho da pilha: "<< cartas.size() << endl;
    cout << "Carta do topo: "<< cartas.top() << endl;//retorna quem ta no topo

    cartas.pop();//tira o eleento de cima
    cout << "Tamanho da pilha: "<< cartas.size() << endl;
    cout << "Carta do topo: "<< cartas.top() << endl;

    if(cartas.empty()) cout << "A pilhaesta vazia!\n";
    else cout << "A pilhaesta nao esta vazia!\n";

    while(!cartas.empty()) cartas.pop();

    if(cartas.empty()) cout << "A pilhaesta vazia!\n";
    else cout << "A pilhaesta nao esta vazia!\n";


    return 0;
}