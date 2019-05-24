#include <iostream>

using namespace std;

class Matriz
{

    private:

       int linhas, colunas;
       double **ponteiro;

        Matriz &preencher_matriz(const double &valor);

    public:

        // construtores
        Matriz(int x = 0, int y = 0, const double &valor = 0);
        Matriz(const Matriz &mat);

        //funções membro
        unsigned int const getRows()const{ return linhas;}
        unsigned int const getCols()const{ return colunas;}
        Matriz &zeros(){preencher_matriz(0);};
        Matriz &ones(){preencher_matriz(1);};
        Matriz unit();

        //sobrecargas no operadores
        friend ostream& operator<< (ostream &out, const Matriz &mat);
        friend istream& operator>> (istream &in, Matriz &mat);
        double & operator()(int linha, int coluna){ return ponteiro[linha-1][coluna-1];}
        Matriz operator+(const Matriz mat);
        Matriz operator-(const Matriz mat);
        Matriz operator*(const Matriz mat);
        Matriz & operator+=(const Matriz mat){return(*this = *this + mat);};
        Matriz & operator-=(const Matriz mat){return(*this = *this - mat);};
        Matriz & operator*=(const Matriz mat){return(*this = *this * mat);};
        Matriz & operator*=(double const n);
        Matriz & operator~();
        bool operator==(const Matriz mat);
        bool operator!=(const Matriz mat){return(!(*this == mat));};


        //destrutor
        ~Matriz();
};


Matriz::Matriz(int x, int y, const double &valor)//construtor padrão
{
    linhas = x;
    colunas = y;
    ponteiro = new double *[linhas];
    for(int i = 0; i < linhas; i++){ponteiro[i] = new double [colunas];}
    preencher_matriz(valor);
}

Matriz::Matriz(const Matriz &mat)//construtor de cópia
{
    linhas = mat.linhas;
    colunas = mat.colunas;
    ponteiro = new double *[linhas];
    for(int i = 0; i < linhas; i++){ponteiro[i] = new double [colunas];}
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            ponteiro[i][j] = mat.ponteiro[i][j];
        }
    }
}

ostream& operator<<(ostream &out, const Matriz &mat) // exibir matriz na tela
{   
    out<< endl;
    for (int i=0; i<mat.linhas; i++){
        for(int j=0; j<mat.colunas; j++) { out << mat.ponteiro[i][j] << "      ";}
        out << endl;
    }
    return out;
}

istream& operator>>(istream &in, Matriz &mat) // sobrecarga de operador para preencher a matriz digitando os elementos
{
    int linhas, colunas;
    cout << "Digite o numero de linhas da matriz" << endl;
    cin >> linhas;
    cout << "Digite o numero de colunas da matriz" << endl;
    cin >> colunas;
    Matriz aux(linhas, colunas);
    for (int i=0; i<linhas; i++){
        cout << "Digite os valores da linha " << i+1 << " , digitando enter entre cada elemento" << endl << endl;
        for(int j=0; j<colunas; j++) {
            cin>>aux.ponteiro[i][j];
        }
        cout << endl;
    }
    // return in;
    mat = aux;
}

Matriz Matriz::operator+(Matriz mat)
{
    if ( linhas==mat.linhas and colunas==mat.colunas){
        Matriz aux(linhas,colunas);
        for(int i = 0; i < linhas; i++) {
            for(int j = 0; j < colunas; j++) {
                aux.ponteiro[i][j] = ponteiro[i][j] + mat.ponteiro[i][j];
            }
        }
        return aux;
    }
    else{
        cout << "As matrizes precisam ter o mesmo formato para ser somadas" << endl;
        return *this;
    }
}

Matriz Matriz::operator-(Matriz mat)
{
    if ( linhas==mat.linhas and colunas== mat.colunas){
        Matriz aux(linhas,colunas);
        for(int i = 0; i < linhas; i++) {
            for(int j = 0; j < colunas; j++) {
                aux.ponteiro[i][j] = ponteiro[i][j] - mat.ponteiro[i][j];
            }
        }
        return aux;
    }
    else{
        cout << "As matrizes precisam ter o mesmo formato para ser somadas" << endl;
        return *this;
    }
}

Matriz Matriz::operator*(Matriz mat)
{
    if (colunas != mat.linhas){ cout << "o numero de colunas da primeira matriz deve coincidir com o numero de linhas da segunda";}
    else {
        Matriz aux(linhas,mat.colunas);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < mat.colunas; j++) {
                for (int k = 0; k < mat.linhas; k++) {
                    aux.ponteiro[i][j] += ponteiro[i][k] * mat.ponteiro[k][j];
                }
            }
        }
        return aux;
    }
}

Matriz &Matriz::operator*=(double n) // multiplicação por escalar
{
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            ponteiro[i][j] = (ponteiro[i][j] * n);
        }
    }
}

Matriz &Matriz::operator~() // matriz transposta
{
    Matriz aux(colunas, linhas);
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            aux.ponteiro[i][j] = ponteiro[j][i];
        }
    }
    *this = aux;
}

bool Matriz::operator==(Matriz mat)
{
    bool resposta = true;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if (ponteiro[i][j] !=  mat.ponteiro[i][j]){resposta = false;}
        }
    }
    return resposta;
}

Matriz& Matriz::preencher_matriz(const double &valor)
{
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++) ponteiro[i][j] = valor;
    }
}

Matriz Matriz::unit() // matriz identidade
{
    if (linhas != colunas){ cout << "A matriz precisa ser quadrada para ter uma matriz identidade equivalente" << endl;}
    else{
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++)
                {
                    if (i == j) ponteiro[i][j] = 1;
                    else ponteiro[i][j] = 0;
                }
        }
    }
}


Matriz::~Matriz() // destrutor
{
}
