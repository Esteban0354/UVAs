/*
 * Jose Barrera Ramos
 * Esteban Munoz
 * Proyecto Estructura de Datos / Have Fun With Matrices
 */

#ifndef PROYECTOESTRUCTURAS_MATRIZDISPERSALISTA_H
#define PROYECTOESTRUCTURAS_MATRIZDISPERSALISTA_H

//Librerias
#include <list>
#include <string>
#include <vector>

using namespace std;

class MatrizDispersaLista {
private:
    vector<list<int>> matrizDispersaLista;
    list<int> valores;
    list<int> filas;
    list<int> columnas;
    int filasOg;
    int columnasOg;
public:
    //Constructores
    MatrizDispersaLista(int** &matriz, int col, int fil);
    MatrizDispersaLista(vector<list<int>>& fullMatrix);
    MatrizDispersaLista(MatrizDispersaLista& otro);


    //Operaciones
    vector<list<int>> rebuild();
    int get(int i, int j);
    vector<int> getRow(int j);
    list<int> getRowList(int j);
    vector<int> getCol(int j);
    list<int> getColList(int j);
    vector<int> getDisperseRow(int j);
    list<int> getDisperseRowList(int j);
    vector<int> getDisperseCol(int j);
    list<int> getDisperseColList(int j);
    void assign(int i, int j, int value);
    void add(MatrizDispersaLista& otro);
    void printMatrix(string separador);
    vector<int> productVector(vector<int>& vec);
    int getMax();
    MatrizDispersaLista getTranspose();
    static MatrizDispersaLista addMatrixList(list<MatrizDispersaLista>& matrices);

    // Sobrecarga de operadores
    MatrizDispersaLista operator+(MatrizDispersaLista& otro);
    MatrizDispersaLista operator*(MatrizDispersaLista& otro);
    bool operator==(MatrizDispersaLista& otro);


};

#endif //PROYECTOESTRUCTURAS_MATRIZDISPERSALISTA_H
