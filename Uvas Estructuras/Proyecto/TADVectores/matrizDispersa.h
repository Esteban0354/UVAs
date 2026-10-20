/*
 * Jose Barrera Ramos
 * Esteban Munoz
 * Proyecto Estructura de Datos / Have Fun With Matrices
 */

#ifndef PROYECTOESTRUCTURAS_MATRIZDISPERSA_H
#define PROYECTOESTRUCTURAS_MATRIZDISPERSA_H

//Librerias
#include <vector>
#include <list>
#include <string>

using namespace std;

/**
 * @class MatrizDispersa (Vectores)
 * @brief Clase para representar una Matriz Dispersa
 *
 * Esta matriz almacena una matriz dispersa en formato coordenado
 */
class MatrizDispersa {
private:
    //Formato Coordenado - Atributos
    vector<int> valores;  //Este vector contiene los valores de la matrizDispersa
    vector<int> filas;    //Este vector contiene las posiciones de las filas donde hay valores en la matrizDispersa
    vector<int> columnas; //Este vector contiene las posiciones de las columbas donde hay valores en la MatrizDispersa

    //Tamano MatrizOriginal
    int filasOriginal;
    int columnasOriginal;
public:
    // Constructores
    MatrizDispersa(vector<vector<int>>& fullMatrix);                       //Comprobado
    MatrizDispersa(int**& matriz, int tamano);                             //Comprobado
    MatrizDispersa(MatrizDispersa& otro);                                  //Comprobado

    // Operaciones
    vector<vector<int>> rebuild();                                         //Comprobado
    int get(int i, int j);                                                 //Comprobado
    vector<int> getRow(int j);                                             //Comprobado?
    vector<int> getCol(int j);                                             //Comprobado
    vector<int> getDisperseRow(int j);                                     //Comprobado?
    vector<int> getDisperseCol(int j);                                     //Comprobado
    void assign(int i, int j, int value);                                  //Comprobado
    void add(MatrizDispersa& otro);                                        //Comprobado
    void printMatrix(string separador);                                    //Comprobado
    vector<int> productVector(vector<int>& vec);                           //...
    int getMax();                                                          //Comprobado
    MatrizDispersa getTranspose();                                         //Comprobado
    static MatrizDispersa addMatrixList(vector<MatrizDispersa> &matrices); //F

    // Sobrecarga de operadores
    MatrizDispersa operator+(MatrizDispersa& otro);                        //Hecho
    MatrizDispersa operator*(MatrizDispersa& otro);                        //Hecho
    bool operator==(MatrizDispersa& otro);                                 //Hecho
};

#endif //PROYECTOESTRUCTURAS_MATRIZDISPERSA_H