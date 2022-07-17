# include <iostream>
# include <list>

using namespace std;

int main(){
    // list<int> aula(5,50) //primeiro numero é a quantidade e ooutro é eh...
    list<int> aula;
    int tam=10;
    list<int>::iterator it;
    for(int i=0; i<tam; i++) {
        aula.push_front(i);
    }
    it=aula.begin();
    advance(it,5);

    aula.insert(it,555);
    cout<<"Tamanho da lista: "<<aula.size()<<endl;
    tam=aula.size();

    aula.sort();
    advance(it,(aula.size()-1));

      for(int i=0; i<tam; i++) {
        cout << aula.front()<< endl;
        aula.pop_front();
    }
    aula.erase(it);

    for(int i=0; i<tam; i++) {
        cout << aula.front()<< endl;
        aula.pop_front();
    }
    
    return 0;
}