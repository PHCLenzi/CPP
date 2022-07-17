#include <iostream>

using namespace std;

int main(){
    
    int *p;//crio um ponteiro
    int vetor[10];
    p=vetor; //eh igual a -> p=&vetor[0]
    cout << "\n" << p << "\n";
    *(p++);// encremento para a posicao do proximo valor de vetor int (4 Bytes)
    cout << "\n" << p << "\n";
    //atribuir valor a primeira posi do ponteiro
    *(p--);
    *p = 10;
    cout << "\n" << *p << "\n";
    cout << "\n" << vetor[0] << "\n";
    *(p++);// pula para a o endereço da proxima posicao do vetor
    *p = 20;

    cout << "\n" << vetor[1] << "\n";// = 20

    return 0;
}
