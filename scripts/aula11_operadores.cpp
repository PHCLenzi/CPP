#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int num1 = 8;
    int num2 = 8;

    if(num1> 4 && num1 <7){
         cout << "\n\n  valor ceieto";
    }

    if(num2> 4 || num2 <7){
         cout << "\n\n  valor ceieto";
    }

    bool teste =true;
    if(!teste){
         cout << "\n\n  valor ceieto";
    }

    return 0;
}
