#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int y=0, z=1;
    for(int x =0;x<=10;x++,y+=2, z+= 2){
        cout << x <<", "<< y << ", "<< z << "\n";
    }


    return 0;
}
