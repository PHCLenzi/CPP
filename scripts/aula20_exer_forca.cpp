
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std ;
default_random_engine seed;

string get_string_palavra_em_branco(char *in);
bool pesquisa_letra(char letra);

int main()
{
    
    int random, vida=5 ;
    int *pont_random;
    pont_random = &random;
    inicio_1:
    system("cls");// comando de sistema para lipar a tela

    
    cout << "Escolha um numero de 1 a 6:\n";
    cin >>  *pont_random;
    if(random>6 || random<1){
        cout << "Deve-se escoler um valor de 1 a 6\n ";
        system("pause");
        goto inicio_1;
    }

    random-=1;

    string banco_chaves [6] = {"papel", "casaco", "cama" , "armario", "computador", "mochila"};

    string palavra_alvo = banco_chaves[random], letras_lixo="";
    cout << "\nDEBUG:: palavra_alvo -> "<<  palavra_alvo;

    char palavra_em_branco[palavra_alvo.length()];

    cout << "\nDEBUG:: sizeof(palavra_em_branco) -> "<<  sizeof(palavra_em_branco);

    for(int i=0;i<sizeof(palavra_em_branco); i++)
        palavra_em_branco[i]= '_';

    cout << "\n DEBUG:: palavra_branco -> "<<  palavra_em_branco;


    inicio_2:

    char letra_escolhida;
    bool acertou;
    // while(vida>0){
    int loop_aux =0;
    while(loop_aux<1){
        //system("cls");


        cout << "\nPalavra chave: "<< palavra_em_branco;
        cout << "\nLetras ja escolhidas: "<< letras_lixo << "Vidas = "<< vida;
        cout << "\ndigite uma letra minisculo: ";
        cin >> letra_escolhida;
        acertou =false;
        for(int i=0;i<palavra_alvo.length();i++){
            if(palavra_alvo[i]==letra_escolhida){
                palavra_em_branco[i]==letra_escolhida;
                acertou = true;
            }
        }
        (acertou)? : vida--;

        loop_aux++;
    }





    return 0 ;
}


// void get_string_palavra_em_branco(char *in){


    // for(int i=0; i< *in.length();i++){
    //     cout << *(in+1);
    // }
//}
