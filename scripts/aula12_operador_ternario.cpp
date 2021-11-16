#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
     
     //(esepres) ? valor 1 : valor 2;

     int n1, n2, nota;
     string res;

     cout << "Digite a nota 1: ";
     cin >> n1;

     cout << "Digite a nota 2: ";
     cin >> n2;
     nota = n1 + n2;

     // pode ser assim -> (nota>= 60) ? res = "Aprovado" : res = "Reprovado";
     res = (nota >= 60)? "Aprovado" : "Reprovado";
     cout << "\nO aluno esta " << res;

     int n3 , x =0;
     cout << "\nDigite um valor para n3: ";
     cin >> n3;
     (n3 >= 10) ? x++ : x--;

     cout << "\no valor de x eh : " << x;
    return 0;
}
