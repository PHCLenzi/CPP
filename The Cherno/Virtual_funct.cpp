# include <iostream>
# include <string>

class Entity{

public:
    // colocando o virtual na frente da funcao da classe pai, ele vai sugerir que caso essa funcao seja chamada por uma classe entety(ou filha dela) que seja prucurado se nao tem outra funcao tbm com esse nome nas filhas?
    //teste 1 :
    // std::string GetName() { return "Entity"; }
    //teste 2 :
    virtual std::string GetName() { return "Entity"; }

};

class Player : public Entity {
    private:
        std::string m_name;
    public:
        Player(const std::string& name)
            : m_name(name){}

        std::string GetName() { return m_name; }     
};

void print_name(Entity* entity){
    std::cout << entity->GetName() << std::endl;
}

int main(){

    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;
    print_name(e);

    Player* p = new Player("Cherno");   
    std::cout << p->GetName() << std::endl;
    print_name(p);

    Entity* entity = p;   
    std::cout << entity->GetName() << std::endl;
    print_name(entity);

    std::cin.get();
}
