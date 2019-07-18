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

