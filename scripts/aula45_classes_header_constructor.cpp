#include <iostream>
#include <stdlib.h>
#include "aula45_aviao.h"

using namespace std;


int main(){

    Aviao *av1=new Aviao(1);
    Aviao *av2=new Aviao(3);
    Aviao *av3=new Aviao(2);

    av1->imprimir();// chama o metodo da classe Aviao, do obejto av1
    av2->imprimir();
    av3->imprimir();
    
    return 0;
}