# include <iostream>
# include <cstdlib>
# include <vector>

using namespace std;
/*
Aula biblioteca <cstdlib>
fonte: https://www.youtube.com/watch?v=jjiBDTSB8-s&list=PLx4x_zx8csUjczg1qPHavU1vw1IkBcm40&index=76&ab_channel=CFBCursos

func <aritmetica> abs(){retorna o valor absoluto} div_t(){retorna resultado divisao},size_t()
contstante: RAND_MAX
*/

int main(){
    int n =-10;
    int numerador = 10 ,denomminador = 3;

    div_t resultado;

    cout << abs(n) << endl;

    resultado = div(numerador,denomminador);// pega  info de uma divisao: quociente e resto.

    cout<< numerador << " dividido por " << denomminador  << " = "<< resultado.quot << ", e tem resto = " << resultado.rem <<  endl;

    vector<int> num = { 9,6,3,4,5,6,7,0};
    size_t tam = num.size();
    cout << tam << endl;



    return 0;
}