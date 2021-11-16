#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    system("cls");// comando de sistema para lipar a tela

    //  switch (expressao){
    //     case const1:
    //         comando;
    //         break;
    //     case const1:
    //         comando;
    //         break;
    //     default:
    //         comando;
    int val;

    inicio :

    cout << "\nSelecione uma cor de 1 a 3\n";
    cout << "verde = 1 ; Azul = 2 e Amarelo = 3\n";

    cin >> val;

    cout << "Cor escolhida foi ";

    switch(val){
        case 1:
            cout << "Verde";
            break;
        case 2:
            cout << "Azul";
            break;
        case 3:
            cout << "Amarelo";
            break;
        default:
            system("cls");// comando de sistema para lipar a tela
            cout << "\n Valor selecionado errado, sua mula!!";
            goto inicio;
    }
        inicio2:
        cout << "\nSelecione uma cor de 1 a 6\n";
        cout << "verde = 1,2,3 ; Azul = 4,5,6\n";

        cin >> val;

        cout << "Cor escolhida foi ";

        switch(val){
            case 1:
            case 2:
            case 3:
                cout << "Verde";
                break;
            case 4:
            case 5:
            case 6:
                cout << "Azul";
                break;
            default:
                system("cls");// comando de sistema para lipar a tela
                cout << "\n Valor selecionado errado, sua mula!!";
                goto inicio2;
        }
    
     
    return 0;
}
