
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std ;
default_random_engine seed;

string get_string_palavra_em_branco(char *in);
bool pesquisa_letra(char letra);

int main()
{
    
    int random, vida=5 ;
    int *pont_random;
    pont_random = &random;
    inicio_1:// goto
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

    string  palavra_em_branco = palavra_alvo;





    for(int i=0;i<(palavra_em_branco.length()); i++)
        palavra_em_branco[i]= '_';



    inicio_2:

    char letra_escolhida;
    bool acertou;
    bool ganhou;
    while(vida>0){
    // int loop_aux =0;// mudar para o de cima
    // while(loop_aux<2){
    // while(loop_aux<2){
        //system("cls");


        cout << "\nPalavra chave: "<< palavra_em_branco;
        cout << "\nLetras lixo ja escolhidas: "<< letras_lixo << " \nVidas = "<< vida;
        cout << "\ndigite uma letra minisculo: ";
        cin >> letra_escolhida;
        acertou =false;
        for(int i=0;i<palavra_alvo.length();i++){
            if(palavra_alvo[i]==letra_escolhida){
                palavra_em_branco[i]=letra_escolhida;
                acertou = true;
                cout << "\nAcertou a letra!";
                
                
            }
        }
     
        if (!acertou){
            letras_lixo+=letra_escolhida;
            letras_lixo+= ", ";
            vida--;
        }
        
        // loop_aux++;
        //ferifica se a palavra foi concluida
        ganhou=true;
        for (int i=0;i<palavra_alvo.length();i++){
            if(palavra_em_branco[i]=='_'){
                ganhou=false;
            }

        }
        if(ganhou){
            break;
        }

    }


    if(!ganhou){
        cout << "\n!!! GAME OVER  !!!";
        cout << "\nA palavra era "<< palavra_alvo;
    }
    else{
        cout << "\n!!! YOU WIN  !!!";

    }

    return 0 ;
}


// void get_string_palavra_em_branco(char *in){


    // for(int i=0; i< *in.length();i++){
    //     cout << *(in+1);
    // }
//}
