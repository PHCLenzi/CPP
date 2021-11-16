#include <iostream>

using namespace std;

int main(){
    
   int *p;
   int vetor[10];

    p=vetor; // p vai receber o primeiro endereço de memória do meu vetor. É igual afazer p=&vetor[0]
    cout << "\n" << p <<"\n";
    p=&vetor[0];
    cout << "\n" << p <<"\n";

    p=&vetor[1];
    cout << "\n" << p <<"\n";// vai imprimir um indereço 4 bytes depois
    *(p+=1);// incrementa mais 4 bites, pois se trata de um int.
    cout << "\n" << p <<"\n";// vai imprimir um indereço 4 bytes depois

    *(p-=2);// sobe dois indereços de  de memória
    *p=10; //= > vetor[0] = 10
    cout << "\n" << vetor[0] <<"\n";

    *(p+1)=20;
    cout << "\n" << vetor[1] <<"\n";



    return 0;
}
