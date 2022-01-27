#include <iostream>
#include <stdlib.h>

using namespace std;

//crio uma classe chamada Aviao. Declaro uma classe com elementos publicos e privados
class Aviao{

// separa o que for publico do que for privado
public:
    int vel=0;
    int velMax;// não defino ainda, dependendo do tipo do avião a velMax vai ser diferente
    string tipo;
    // quero um metodo (ini) que baseado na variável "strig tipo" o valor de velMax vai mudar
    // vou prototipar esse metodo ini, mas eu construo o metodo fora da classe
    void ini(int tp);// tp =tipo, eu verifico o tipo do aviao e configuro as outra variaveis
private:
};
// criando o metodo ini() para a classe aviao
void Aviao::ini(int tp){
    // tipo 1 =jato, 
    if(tp==1){
        // devo usar o this->velMax que significa a propriedade velMax do objeto Aviao
        this->velMax=800;
        this->tipo="Jato";
    }else if(tp == 2){// tipo 2 = monomotor
        this->velMax=350;
        this->tipo="Monomotor";
    }else if(tp == 3){// tipo 3 = planador
        this->velMax=180;
        this->tipo="Planador";
    }
}
//objetos são instacias das classes

int main(){
   
    Aviao *av1=new Aviao();// por regra temos criar um objeto como se fosse um ponteiro (*)
    //inicio um objeto do tipo jato. instancio um novo objeto da classe aviao
    av1->ini(1);// chamo uma propriedade da classe usando a seta (->)
    // imprimo a propriedade velMax do objeto av1
    cout << "\nav1->velMax = " << av1->velMax;// chamo uma propriedade da classe usando a seta (->)
    // crio mais um objeto
    Aviao *av2=new Aviao();
    av2->ini(2);// como n tem construtor, tenho que chamar um metodo inicializador
    cout << "\nav2->velMax = " << av2->velMax;
    
    return 0;
}