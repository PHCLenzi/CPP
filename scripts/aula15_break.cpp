#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int count;

    count = 0;

    while(count++<999){
        cout << count << "\n";
        if(count>500){
            break;
        }
    }
    cout << "Terminou";

    return 0;
}
