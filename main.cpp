#include <iostream>
#include "matriz.h"

using namespace std;


int main(){
    //funções de exemplo de como utilizar o programa

    int m1,n1,v1;
    cout << "Digite o numero de linhas, o numero de colunas e o valor inicial dos elementos da matriz, separando cada input com enter" << endl;
    cin >> m1 >> n1 >> v1;
    Matriz teste1(m1,n1,v1);
    cout << endl;
    cout << teste1 << endl;
    cout << "o mesmo para outra matriz" << endl;
    int m2,n2,v2;
    cin >> m2 >> n2 >> v2;
    Matriz teste2(m2,n2,v2);
    cout << teste2 << endl;
    cout << endl;
    teste1 += teste2;
    cout << "A soma das matrizes é" << teste1 << endl;
    
    // teste1(1,1) = 1.5;
    // teste1(1,2) = 2;
    int a,b;
    b = teste1.getRows();
    a = teste1.getCols();
    // cout << teste1 << endl;

    Matriz teste(teste1);//construtor de cópia
    teste.unit();

    // teste1 =~ teste1;
    cout << " matriz identidade: " << teste << endl;

    ////////////

    cout << "end" << endl;
}
