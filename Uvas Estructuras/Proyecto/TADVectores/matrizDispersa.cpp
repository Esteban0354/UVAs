/*
 * Jose Barrera Ramos
 * Esteban Munoz
 * Proyecto Estructura de Datos / Have Fun With Matrices
 */

#include "matrizDispersa.h"

//Librerias
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/**
 * @brief
 * @param fullMatrix
 * @note Complejidad O(n * m)
 */
MatrizDispersa::MatrizDispersa(vector<vector<int>> &fullMatrix) {
    for (int i = 0; i < fullMatrix.size(); i++) {
        for (int j = 0; j < fullMatrix[i].size(); j++) {
            if (fullMatrix[i][j] != 0) {
                valores.push_back(fullMatrix[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }

    filasOriginal = fullMatrix.size();
    columnasOriginal = fullMatrix[0].size();

}

/**
 * @brief
 * @param matriz
 * @note Complejidad O(n * m)
 */
MatrizDispersa::MatrizDispersa(int** &matriz, int tamano) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] != 0) {
                valores.push_back(matriz[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }

    filasOriginal = tamano;
    columnasOriginal = tamano;
}

/**
 * @brief
 * @param otro
 * @note Complejidad O(1)
 */
MatrizDispersa::MatrizDispersa(MatrizDispersa &otro) {
    this->valores = otro.valores;
    this->filas = otro.filas;
    this->columnas = otro.columnas;
}

/**
 * @brief Reconstruye una matrizDispersa a su forma original
 * @return retorna una matriz original hecha de vectores de vectores
 * @note Complejidad O(n)
 */
vector<vector<int>> MatrizDispersa::rebuild() {
    vector<vector<int>> fullMatrix(filasOriginal, vector<int>(columnasOriginal, 0));
    for (int k = 0; k < filas.size(); k++) {
        fullMatrix[filas[k]][columnas[k]] = valores[k];
    }
    return fullMatrix;
}

/**
 * @brief Obtiene el valor de la posicion (i, j) de la matriz
 * @param i La fila de la posicion
 * @param j La columna de la posicion
 * @return El valor de la posicion (i, j)
 * @return Devuelve 0 en caso de no obtener el valor de la posicion (i, j)
 * @note Complejidad O(n)
 */
int MatrizDispersa::get(int i, int j) {
    int ans = 0;
    for (int k = 0; k < filas.size(); k++) {
        if (filas[k] == i && columnas[k] == j) {
            ans = valores[k];
        }
    }
    return ans;
}

/**
 * @brief
 * @param j
 * @return
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersa::getRow(int j) {
    vector<int> row;
    for (int k = 0; k < filas.size(); k++) {
        if (filas[k] == j) {
            row.push_back(valores[k]);
        }
    }
    return row;
}

/**
 * @brief
 * @param j
 * @return
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersa::getCol(int j) {
    vector<int> col;
    for (int k = 0; k < columnas.size(); k++) {
        if (columnas[k] == j) {
            col.push_back(valores[k]);
        }
    }
    return col;
}

/**
 * @brief
 * @param j
 * @return
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersa::getDisperseRow(int j) {
    vector<int> resultado;
    //vector<vector<int>> fullMatriz = rebuild();

    for (int i = 0; i < filasOriginal; i++) {
        if (filas[i] == j) {
            resultado.push_back(valores[i]);
        } else {
            resultado.push_back(0);
        }
    }

    return resultado;
}

/**
 * @brief
 * @param j
 * @return
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersa::getDisperseCol(int j) {
    vector<int> resultado;
    //vector<vector<int>> fullMatriz = rebuild();

    for (int i = 0; i < columnasOriginal; i++) {
        if (columnas[i] == j) {
            resultado.push_back(valores[i]);
        } else {
            resultado.push_back(0);
        }
    }

    return resultado;
}

/**
 * @brief
 * @param i
 * @param j
 * @param value
 * @note Complejidad O(n)
 */
void MatrizDispersa::assign(int i, int j, int value) {
    bool seguir = true;
    for (int k = 0; k < filas.size() && seguir; k++) {
        if (filas[k] == i && columnas[k] == j) {
            if (value == 0) {
                valores.erase(valores.begin() + k);
                filas.erase(filas.begin() + k);
                columnas.erase(columnas.begin() + k);
            } else {
                valores[k] = value;
            }
            seguir = false;
        }
    }

    if (value != 0 && seguir) {
        valores.push_back(value);
        filas.push_back(i);
        columnas.push_back(j);
    }
}


/**
 * @brief
 * @param otro
 * @note Complejidad O(n)
 */
void MatrizDispersa::add(MatrizDispersa &otro) {
    for (int k = 0; k < otro.filas.size(); k++) {
        int i = otro.filas[k];
        int j = otro.columnas[k];
        int value = get(i, j) + otro.valores[k];
        assign(i, j, value);
    }
}

/**
 * @brief
 * @param separador
 * @note Complejidad O(n)
 */
void MatrizDispersa::printMatrix(string separador) {
    for (int i = 0; i < valores.size(); i++) {
        if (i + 1 != valores.size()) {
            cout << valores[i] << separador;
        } else {
            cout << valores[i] << endl;
        }
    }
}

vector<int> MatrizDispersa::productVector(vector<int> &otroVector) {
    vector<int> result;
    int i = 0;

    for (vector<int>::iterator it = otroVector.begin(); it != otroVector.end(); ++it, ++i) {
        for (vector<int>::iterator it2 = valores.begin(); it2 != valores.end(); ++it2) {
            result.push_back(*it2 * *it);
        }
    }

    return result;
}


/**
 * @brief
 * @return
 * @note Complejidad O(n)
 */
int MatrizDispersa::getMax() {
    int resultado = 1;                                                  // 1

    for (int i = 0; i < valores.size(); i++) {                          // n + 1
        resultado = (valores[i] > resultado) ? valores[i] : resultado;  // n
    }

    return resultado;                                                   // 1
}

/**
 * @brief
 * @return
 * @note Complejidad O(n * m)
 */
MatrizDispersa MatrizDispersa::getTranspose() {
    vector<vector<int>> matrizTranspose(filasOriginal, vector<int>(filasOriginal, 0));
    vector<vector<int>> matrizRebuild = rebuild();
    for (int i = 0; i < filasOriginal; i++) {
        for (int j = 0; j < columnasOriginal; j++) {
            matrizTranspose[j][i] = matrizRebuild[i][j];
        }
    }

    MatrizDispersa resultadoTranspose(matrizTranspose);
    return resultadoTranspose;
}

/**
 * @brief
 * @param matrices
 * @return
 * @note Complejidad O(n * M)
 */
//MatrizDispersa MatrizDispersa::addMatrixList(vector<MatrizDispersa> &matrices) {
//    //vector<vector<int>> result = rebuild();
//
//    for (vector<MatrizDispersa>::iterator it = matrices.begin(); it != matrices.end(); ++it) {
//        result = result + *it;
//    }
//
//    return result;
//}


/**
 * @brief Suma 2 matrices para crear una nueva
 * @param otro
 * @return Matriz dispersa resultado de la suma de 2
 * @note Complejidad O(n * m)
 */
MatrizDispersa MatrizDispersa::operator+(MatrizDispersa &otro) {
    vector<vector<int>> matriz = rebuild();
    vector<vector<int>> otraMatriz = otro.rebuild();

    int tamano = (filasOriginal > otro.filasOriginal) ? filasOriginal : otro.filasOriginal;

    vector<vector<int>> sumaMatriz(tamano, vector<int>(tamano, 0));

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            sumaMatriz[i][j] += matriz[i][j];
        }
    }

    for (int i = 0; i < otraMatriz.size(); i++) {
        for (int j = 0; j < otraMatriz.size(); j++) {
            sumaMatriz[i][j] += otraMatriz[i][j];
        }
    }

    MatrizDispersa sumaMatrizDispersa(sumaMatriz);

    return sumaMatrizDispersa;
}

/**
 * @brief Multiplica una matriz con otra
 * @param otro
 * @return
 * @note Complejidad O(n^3)
 */
MatrizDispersa MatrizDispersa::operator*(MatrizDispersa &otro) {
    vector<vector<int>> matriz = rebuild();
    vector<vector<int>> otraMatriz = otro.rebuild();

    int tamano = (filasOriginal > otro.filasOriginal) ? filasOriginal : otro.filasOriginal;

    vector<vector<int>> productoMatriz(tamano, vector<int>(tamano, 0));

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            for (int k = 0; k < matriz.size(); k++) {
                productoMatriz[i][j] += matriz[i][k] * otraMatriz[k][j];
            }
        }
    }

    MatrizDispersa productoMatrizDispersa(productoMatriz);

    return productoMatrizDispersa;
}

/**
 * @brief Esta funcion compara si 2 matrices Dispersas son iguales
 * @param otro
 * @return verdadero o falso dependiendo de si es igual o no
 * @note Complejidad O(n)
 */
bool MatrizDispersa::operator==(MatrizDispersa &otro) {
    bool ans = true;
    if (valores.size() != otro.valores.size()) {
        ans = false;
    }

    for (int i = 0; i < valores.size(); i++) {
        if (valores[i] != otro.valores[i]) {
            ans = false;
        }
    }

    return ans;
}