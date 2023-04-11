# include <iostream>
# include <list>
using namespace std;
// aula sobre list, metodos >> insert(), eraser(), clear(), empty(), merge(), 

int main ( ){
    list<int> aula;
    
    list<int> test;
    test.push_front(81);
    test.push_front(81);
    test.push_front(81);
    test.push_front(81);
    
    
    int tam;
    list<int>:: iterator it;

    tam = 10;

    for (int i = 0; i<tam; i++) {
        cout << "Valor atual do i eh: " << i << endl;
        aula.push_front(i);
    }

    it=aula.begin();
    advance(it,3);
    aula.insert(it,0);

    aula.erase(--it);


    aula.merge(test);

    for(int d = 0; d<tam; d++) {
        cout << aula.front()<< endl;
        aula.pop_front();
    }







return 0;
}