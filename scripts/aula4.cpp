#include <iostream>

using namespace std;

int main(){
    
    //tipo e nome da variavel
    //tipo e nome = valor

    int vidas=0; // 10, 25 , -5
    char letra='B'; //'b'
    // char letras[20]= ['B' 'G']; //'b'*20
    double decimal = 2.49999; //2.4999999999999999
    float decimal2 = 2.5;//2.5
    bool vivo= true; // true
    string nome = "Bruno"; // "Bruno"

    cout<< vidas << "\n";
    cout<< letra << "\n";
    // cout<< letras << "\n";
    cout<< decimal << "\n";
    cout<< decimal2 << "\n";
    cout<< vivo << "\n";
    cout<< nome << "\n"; 
    // posso imprimir tudo isso a um só cout

    cout<<"Digite o numeros de vidas: ";
    cin>> vidas;
    cout<<"Digite seu nome: ";
    cin>> nome;

    cout<< vidas << "\n" << letra << "\n"<< decimal << "\n"<< decimal2 << "\n"<< vivo << "\n"<< nome << "\n";



    return 0;
}
