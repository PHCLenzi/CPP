#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int  matrice[3][4];//linhas e conulas, rows column 
    matrice[0][0]=0;
    cout << "\nThe sizeof(matrice) = "<< sizeof(matrice) << "\n";

    cout << "\nThe sizeof(matrice[0]) = "<< sizeof(matrice[0]) << "\n";

    cout << "\nmatrice = "<< matrice[0] << "\n";


    matrice[0][0]=0;
    matrice[0][1]=0;
    matrice[0][2]=0;
    matrice[0][3]=0;
    matrice[1][0]=0;
    matrice[1][1]=0;
    matrice[1][2]=0;
    matrice[1][3]=0;
    matrice[2][0]=0;
    matrice[2][1]=0;
    matrice[2][2]=0;
    matrice[2][3]=0;


    for(int r =0; r<3;r++){
        for(int c=0;c<4;c++){
            matrice[r][c] = 10*(r+1)+(c+1);
        }
    }

     for(int r =0; r<3;r++){
        for(int c=0;c<4;c++){
            cout << matrice[r][c] << ", ";
        }
        cout << "\n";
    }

    // for(int j=0;j<sizeof(matrice[0])/4;j++){
    //     for (int i =0;i<sizeof(matrice)/(4*(sizeof(matrice[j])/4));i++){
    //         // cout << "\n The sizeof(matrice)/(4*(sizeof(matrice[i])/4)) = " << sizeof(matrice)/(4*(sizeof(matrice[i])/4)) << ", ";
            
    //         matrice[j][i]=(10*(j+1)+(i+1));
    //         cout << matrice[j][i] << ", ";
    //     }
    //     cout << "\n";

    // }
    cout << &matrice << "\n";
   return 0;
}
