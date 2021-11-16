#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int n;
    n=0;

    while(n<9){
        cout << n <<"\n";
        n++;
        // cin >> n;
    }
    n=0;
    while(n++<9){
        cout << "\nTeste";
        if(n > 8)
            break;
    }
 
    cout <<"Rotina terminou";

    return 0;
}
