#include <iostream>// funcoes cin, cout, get. Basicamente entrada e saida de dados.

using namespace std;

int main(){

    char nome[80];
    char n,s;

    cin.getline(nome,80); // o getline pega o "/0" final da linha, terminador de string.
    // cin.get(nome,80); // o get simples n pega o "/0" final da linha.
    cout << nome << " - Tamanho: "<< cin.gcount()<<  endl;

    cout << "Agora digite nome e sobrenome separados por 'espace'" << endl;
    
    n = cin.get();// ele pega somente uma letra pois n e s são char.
    cin.ignore(80,' ');

    s = cin.get();
    
    cout << n << " - "<< s << endl;

	return 0;

}
