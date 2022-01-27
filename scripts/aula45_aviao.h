#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
// crio um header para criar uma classe toda aqui e usar em outro código
// esse arquivo .h não é compilado, só é envocar por um arquivo compilado
class Aviao{

// separa o que for publico do que for privado
public:
    int vel=0;
    int velMax;// não defino ainda, dependendo do tipo do avião a velMax vai ser diferente
    std::string tipo;
    // quero um metodo construtor (Aviao) que baseado na variável "strig tipo" o valor de velMax vai mudar
    // vou prototipar esse metodo Aviao, mas eu construo o metodo fora da classe
    Aviao(int tp);// tp =tipo, eu verifico o tipo do aviao e configuro as outra variaveis
    void imprimir(); 
private:
};
// criando o metodo construtor Aviao() para a classe aviao, quando eu crio um objeto automaticamente o construtor é chamado
 Aviao::Aviao(int tp){
    // tipo 1 =jato, 
    if(tp==1){
        velMax=800;// aqui não precisa o this, pois é o construtos
        tipo="Jato";// aqui não precisa o this, pois é o construtos
    }else if(tp == 2){// tipo 2 = monomotor
        this->velMax=350;
        this->tipo="Monomotor";
    }else if(tp == 3){// tipo 3 = planador
        this->velMax=180;
        this->tipo="Planador";
    }
}

void Aviao::imprimir(){
    std::cout << "Tip=    " << tipo << std::endl;
    std::cout << "velMax= " << velMax << std::endl;
    std::cout << "vel=    " << vel << std::endl;
    std::cout << "--------" <<  std::endl;

}
#endif