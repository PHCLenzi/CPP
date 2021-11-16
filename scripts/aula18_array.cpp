#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int tam = 5;    

    int vetor[tam];

    vetor[0]=10;
    vetor[1]=20;
    vetor[2]=30;
    vetor[3]=40;
    vetor[4]=50;

    //sizeof me retorna a quantidade de bites do elemento. aqui sizeof(vetor) = 5xint. Int usa 4 bites. sizeof(vector)/4 = quantidade de int no vetor
    for(int i=0;i< sizeof(vetor)/4; i++)
        cout << vetor[i] << "\n";

    int vetor2 [5] = {1, 2 , 3 , 4 ,5 };
    for(int i=0;i< tam; i++)
        cout << vetor2[i] << "\n";

    return 0;
}
