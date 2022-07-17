#include <iostream>// funcoes cin cout

using namespace std;

int main(){

    char nome[80];

    cin.get(nome,80);

    cout << nome << " - Tamanho: "<< cin.gcount()<<  endl;
	return 0;

}
