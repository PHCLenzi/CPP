#include <iostream>

using namespace std;

int main(){
    
    string veiculo="carro";
    string *pv;// tem que ser do mesmo tipo da varíável que vou manipular
    cout << veiculo << "\n";
    pv = &veiculo; //ponteiro recebe indereço da vaiável veiculo
    cout << "pv = "<< pv << "\n";
    cout << "&veiculo = "<< &veiculo << "\n";
    cout << "*pv = "<< *pv << "\n";

    *pv="Moto";
    cout << "veiculo = "<< veiculo << "\n";


    return 0;
}
