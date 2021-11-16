#include <iostream>

using namespace std;

void somarErrado(float var, float valor);// prototipar a funcao
void somar(float *var, float valor);
void iniVetor(float *v);
void funcExtraPont(int *MyV);



int main(){
    
    float num=0;
    float vetor[5];
    int MyV[5];
    somarErrado(num,15);// ele retorna 0, pois a fução não altera os valores no indereço, ela só copia o valor
    
    
    cout << num << "\n";
    somar(&num,15);
    cout << num << "\n";

    iniVetor(vetor);// qd eu tenho um vetor eu não preciso especificar o endereço. n presisa ser (&vetor)
    
    
    cout << "vetor = ";
    for(int i=0; i<5 ; i++){
        cout << vetor[i] << "\n";
    }

    funcExtraPont(MyV);
    cout << "MyV = ";
    for(int i=0; i<5 ; i++){
        cout << vetor[i] << "\n";
    }

    return 0;
}
void somarErrado(float var, float valor){
    var += valor;
}
void somar(float *var, float valor){
    *var += valor;
}
void iniVetor(float *v){
     v[0]=0;// como v é umvetor, eu não preciso passar info de ponteiro. n precisa ser *v[0]
     v[1]=1;
     v[2]=2;
     v[3]=3;
     v[4]=4;
}
void funcExtraPont(int *MyV){
    MyV[0] = 1;
    int *p;
    p=&(*MyV);
    cout << "*p = "<< *p << "\n";
}
