#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;
class Matriz {
private:
    char nombre;
    int orden;
    int determin;
    int** matriz=NULL;
public:
    Matriz(/* args */);
    Matriz(char,int, int,int**);
    int** crear(int);
    Matriz* suma(Matriz*,char);
    int determinante();
    void incremento();
    void decremento();
    Matriz* MultiEscalar(int ,char);
    Matriz* ProEntre(Matriz*,char);
    Matriz* sumaVecto(Matriz*,int,char);
    Matriz* multivecto(int, char);
    int** Traspuesta();
    int** getMatriz();
    int getOrden();
    void toString();
    char getnombre();
    ~Matriz();
};
#endif
