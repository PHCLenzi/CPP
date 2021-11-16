//variables globais e locais
// operation com variables
#include <iostream>
using namespace std;

int n1,n2;//global variables

int main(){
    //operators mathematics : + - / * % () 
    int n3,n4;// local variables
    int res1,res2,res3;

    n1 =11;
    n2=3;
    n3=5;
    n4=2;

    res1 = n1+n2+n3*n4;
    res2 = n1/n2;
    res3 = n1%n2;//resto de divisao

    cout << "Valor de res1 eh: "<<res1<<endl;
    cout << "Valor de res2 eh: "<<res2<<endl;
    cout << "Valor de res3 eh: "<<res3<<endl;

    return 0;
} 