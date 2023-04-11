# include <iostream>

using namespace std;

// uma struct tem variáveis internas
struct Carro{
    string nome;
    string cor;
    int pot;
    int velMax;

};

int main(){
    Carro car1;
    car1.nome = "Tornado";
    car1.cor = "Verde";
    car1.pot = 100;
    car1.velMax = 100;

    cout << car1.nome << endl;
    cout << car1.cor << endl;
    cout << car1.pot << endl;
    cout << car1.velMax << endl;

    return 0;
}