# include <iostream>
using namespace std;
int main() {
    string veiculo = "Carro";
    string *pv;//armazena o endereço da variavel

    pv =& veiculo;//pv recebe o endereço da variavel veiculo na RAM

    cout << pv ; // imprime o endereço da variavel atribuida ao ponteiro pv
    cout << veiculo << "\n" << &veiculo << "\n"<< pv ;
    
    *pv = "Moto"; // no endereço apontado por pv, adicione o valor "Moto"
    cout << *pv  << "\n" << veiculo ; ; // imprime o que esta no endereço da variavel atribuida ao ponteiro pv

    return 0;
}