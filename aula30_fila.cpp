#include <iostream>
#include <queue>

using namespace std;
//fila primeiroa que entra é o primeiro que sai
// empty,size,front,back,push,pop
int main(){

    queue <string> cartas; //nao precisa falar o parametro

    if(cartas.empty()) cout << "A fila esta vazia! \n";
    else cout << "A fila esta nao esta vazia!\n";

    cartas.push("rei de copas");//coloca caisa dentro na fila
    cartas.push("rei de espadas");
    cartas.push("rei de ouro");
    cartas.push("rei de paus");

    cout << "Tamanho da fila: "<< cartas.size() << endl;
    cout << "Carta do topo: "<< cartas.front() << endl;//retorna quem ta no topo

    cartas.pop();//tira o elemento da frente
    cout << "Tamanho da fila: "<< cartas.size() << endl;
    cout << "Carta do topo: "<< cartas.front() << endl;

    if(cartas.empty()) cout << "A fila esta vazia!\n";
    else cout << "A fila esta nao esta vazia!\n";

    while(!cartas.empty()) cartas.pop();

    if(cartas.empty()) cout << "A fila esta vazia!\n";
    else cout << "A fila esta nao esta vazia!\n";

    cout <<" O ultimo elemento da fila eh o : " << cartas.back() << "\n";

    return 0;
}