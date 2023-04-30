# include <iostream>
# include <cstdlib>

using namespace std;
/*
Aula biblioteca <cstdlib>
Parei t = 9:00
fonte: https://www.youtube.com/watch?v=XLlC2AVQeEA&list=PLx4x_zx8csUjczg1qPHavU1vw1IkBcm40&index=75&ab_channel=CFBCursos

func <controle de abiente> abort() e exit(), atexit(), quick_exit(), at_quick_exit(),< _EXIT()
func <variavel de ambiente> getenv(), system()
func <pesquisa e ordenacao de listas> =qsort(){Colocar umm array, vetor em ordem}, bsearch(){pesquisa um elemento em um array ou vetor}
*/

void fim(){
    cout << "CFB Cursos"<< endl;
}

int comparacao(const void* a, const void* b ){
    return (*(int*)a - *(int*)b);
    // 0-> a = b 
    // >0-> a > b 
    // <0-> a < b 
}


int main(){

    // atexit(fim);// função que define chamada de uma outra funcão ao terminar o script. no final do programa é executado o func "fim" 
    for(int i=0;i<10;i++){
        if(i<5){
            cout << i << endl;
        }else{
            // exit(EXIT_SUCCESS);// termina a operação
            cout << i << endl;  
        }
    
    }
    const char* p;
    p = getenv("PATH");// pega a variável PATH do ambiente
    cout << p << endl;


    // system("cls");// comando sistema para limpar a tela

    int vetor [] = {16,1,8,2,3,4,5,6,7,8};
    int pesq = 16;
    int *pos;

    qsort(vetor,10, sizeof(int),comparacao);// isado para botar o vetor ou array em ordem

    for (int i = 0; i <10 ; i++){
        cout << vetor[i] << endl;
    }

    pos = (int*)bsearch(&pesq,vetor,10,sizeof(int),comparacao);  //pesquisa um elemento

    cout << "Elemento " << pesq << " esta na posicao " << *pos << endl;
    
    return 0;
}