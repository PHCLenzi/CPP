# include <iostream>
# include <string>

class Printable{
    public: 
        virtual std::string GetClassName() = 0;
};


class Entity: public Printable{
public:
    // colocando o virtual na frente da funcao da classe pai, ele vai sugerir que caso essa funcao seja chamada por uma classe entety(ou filha dela) que seja prucurado se nao tem outra funcao tbm com esse nome nas filhas?
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }

};


class Player : public Entity {
    private:
        std::string m_name;
    public:
        Player(const std::string& name)
            : m_name(name){}

        std::string GetName() { return m_name; }     
        std::string GetClassName() override { return "Player"; }

};


void print_name(Entity* entity){
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
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

    std::cout << "print_name results: " << std::endl;
    Print(e);
    Print(p);

    // std::cin.get();
}
