#include <iostream>

using namespace std;

int main(){

    enum armas{fuzil=100,revolver=8, rifle=30 ,escopeta=15};

    armas armaSel1,armaSel2,armaSel3;

    armaSel1 = rifle;
    armaSel2 = escopeta;
    armaSel3 = revolver;

    cout << armaSel1 << endl;
    cout << armaSel2 << endl;
    cout << armaSel3 << endl;
    return 0;
}