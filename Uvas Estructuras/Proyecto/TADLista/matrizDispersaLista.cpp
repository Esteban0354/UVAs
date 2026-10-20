/*
 * Jose Barrera Ramos
 * Esteban Munoz
 * Proyecto Estructura de Datos / Have Fun With Matrices
 */

#include "matrizDispersaLista.h"
#include "matrizDispersa.h"

#include <vector>
#include <iostream>
#include <list>
#include "matrizDispersaLista.h"
using namespace std;

/**
 * @brief constructor que recibe vectores de listas
 * @param vector<list<int>>& fullMatrix
 * @note Complejidad O(n*m) n = col, m = fil
 */
MatrizDispersaLista::MatrizDispersaLista(vector<list<int>>& fullMatrix) {
    for (int i = 0; i < fullMatrix.size(); i++) {
        int j = 0;
        for (list<int>::iterator it =fullMatrix[i].begin(); it != fullMatrix[i].end();++j) {
            if (*it != 0) {
                valores.push_back(*it);
                filas.push_back(i);
                columnas.push_back(j);
            }
            it++;
        }
    }

    filasOg = fullMatrix.size();
    columnasOg = fullMatrix[0].size();
}
/**
 * @brief constructor que recibe una matriz
 * @param int** &matriz
 * @param int col
 * @param int fil
 * @note Complejidad O(n*m)
 */
MatrizDispersaLista::MatrizDispersaLista(int** &matriz, int col, int fil) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (matriz[i][j] != 0) {
                valores.push_back(matriz[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }

    filasOg = fil;
    columnasOg = col;
}
/**
 * @brief constructor que recibe una matriz dispersa de listas
 * @param MatrizDispersaLista otro
 * @note Complejidad O(1)
 */
MatrizDispersaLista::MatrizDispersaLista(MatrizDispersaLista &otro) {
    this->valores = otro.valores;
    this->filas = otro.filas;
    this->columnas = otro.columnas;
}
/**
 * @brief Obtiene los valores de la fila j
 * @param int j
 * @return un vector con los valores de la fila j
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersaLista::getRow(int j) {
    vector<int> row;
    list<int>::iterator itFilas = filas.begin();
    list<int>::iterator itValores = valores.begin();
    for (int k = 0; k < filas.size();k++) {
        if (*itFilas == j) {
            row.push_back(*itValores);
        }
        itValores++;
        itFilas++;
    }
    return row;
}
/**
 * @brief Obtiene un valor especifico de la matriz
 * @param int j
 * @param int i
 * @return el valor de la matriz en las coordenadas deseadas
 * @note Complejidad O(n*m)
 */
int MatrizDispersaLista::get(int i, int j) {
    int ans = 0;
    list<int>::iterator itFilas = filas.begin();
    list<int>::iterator itValores = valores.begin();
    list<int>::iterator itColumnas = columnas.begin();
    for (int k = 0; k < filas.size(); k++) {
        if (*itFilas == i && *itColumnas == j) {
            ans = *itValores;
        }
        itValores++;
        itFilas++;
        itColumnas++;
    }
    return ans;
}
/**
 * @brief Obtiene los valores de la fila j
 * @param int j
 * @return una lista con los valores de la fila deseada
 * @note Complejidad O(n)
 */
list<int> MatrizDispersaLista::getRowList(int j) {
    list<int> row;
    list<int>::iterator itFilas = filas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int k = 0; k < filas.size(); k++) {
        if (*itFilas == j) {
            row.push_back(*itValores);
        }
        itValores++;
        itFilas++;

    }
    return row;
}
/**
 * @brief Obtiene un vector con los valores de la columna j
 * @param int j
 * @return una vector con los valores de la columna deseada
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersaLista::getCol(int j) {
    vector<int> col;
    list<int>::iterator itCol = columnas.begin();
    list<int>::iterator itValores = valores.begin();
    for (int k = 0; k < columnas.size();k++) {
        if (*itCol== j) {
            col.push_back(*itValores);
        }
        itValores++;
        itCol++;
    }
    return col;
}
/**
 * @brief Obtiene una lista con los valores de la columna j
 * @param int j
 * @return una lista con los valores de la columna deseada
 * @note Complejidad O(n)
 */
list<int> MatrizDispersaLista::getColList(int j) {
    list<int> col;
    list<int>::iterator itCol = columnas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int k = 0; k < columnas.size(); k++) {
        if (*itCol == j) {
            col.push_back(*itValores);
        }
        itValores++;
        itCol++;

    }
    return col;
}
/**
 * @brief Obtiene los valores de la fila j dispersa de la matriz.
 * @param int j
 * @return un vector con los valores de la fila dispersa
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersaLista::getDisperseRow(int j) {
    vector<int> resultado;
    list<int>::iterator itFilas = filas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int i = 0; i < filas.size(); i++) {
        if (*itFilas == j) {
            resultado.push_back(*itValores);
        } else {
            resultado.push_back(0);
        }
        itFilas++;
        itValores++;
    }
    return resultado;
}
/**
 * @brief Obtiene los valores de la fila j dispersa de la matriz.
 * @param int j
 * @return una lista con los valores de la fila dispersa
 * @note Complejidad O(n)
 */
list<int> MatrizDispersaLista::getDisperseRowList(int j){
    list<int> resultadoLis;
    list<int>::iterator itFilas = filas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int i = 0; i < filas.size(); i++) {
        if (*itFilas == j) {
            resultadoLis.push_back(*itValores);
        } else {
            resultadoLis.push_back(0);
        }
        itFilas++;
        itValores++;
    }

    return resultadoLis;
}
/**
 * @brief Obtiene los valores de la columna j dispersa de la matriz.
 * @param int j
 * @return un vector con los valores de la columna dispersa
 * @note Complejidad O(n)
 */
vector<int> MatrizDispersaLista::getDisperseCol(int j) {
    vector<int> resultadoCol;
    list<int>::iterator itColumna= columnas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int i = 0; i < columnas.size(); i++) {
        if (*itColumna == j) {
            resultadoCol.push_back(*itValores);
        } else {
            resultadoCol.push_back(0);
        }
        itColumna++;
        itValores++;
    }

    return resultadoCol;
}
/**
 * @brief Obtiene los valores de la columna j dispersa de la matriz.
 * @param int j
 * @return una lista con los valores de la columna dispersa
 * @note Complejidad O(n)
 */
list<int> MatrizDispersaLista::getDisperseColList(int j) {
    list<int> resultadoCol;
    list<int>::iterator itColumna= columnas.begin();
    list<int>::iterator itValores = valores.begin();

    for (int i = 0; i < filas.size(); i++) {
        if (*itColumna == j) {
            resultadoCol.push_back(*itValores);
        } else {
            resultadoCol.push_back(0);
        }
        itColumna++;
        itValores++;
    }

    return resultadoCol;
}
/**
 * @brief Asigna un valor a una posición específica de la matriz dispersa.
 * @param int j
 * @param int i
 * @param int value
 * @note Complejidad O(n)
 */
void MatrizDispersaLista::assign(int i, int j, int value) {
    list<int>::iterator itColumna= columnas.begin();
    list<int>::iterator itValores = valores.begin();
    list<int>::iterator itFilas = filas.begin();
    for (int k = 0; k < filas.size(); k++) {
        if (*itFilas == i && *itColumna == j) {
            if (value == 0) {
                itValores = valores.erase(itValores);
                itFilas = filas.erase(itFilas);
                itColumna = columnas.erase(itColumna);
            } else {
                *itValores = value;
            }
            return;
        }
        ++itColumna;
        ++itValores;
        ++itFilas;
    }

    if (value != 0) {
        valores.push_back(value);
        filas.push_back(i);
        columnas.push_back(j);
    }
}
/**
 * @brief Se suma una matris disepersa lista a otra
 * @param MatrizDispersaLista otro
 * @note Complejidad O(n)
 */
void MatrizDispersaLista::add(MatrizDispersaLista &otro) {
    list<int>::iterator itColumna= columnas.begin();
    list<int>::iterator itValores = valores.begin();
    list<int>::iterator itFilas = filas.begin();

    for (int k = 0; k < otro.filas.size(); k++) {
        int i = *itFilas;
        int j = *itColumna;
        int value = get(i, j) + *itValores;
        assign(i, j, value);
        ++itColumna;
        ++itValores;
        ++itFilas;
    }
}
/**
 * @brief Imprime la matriz
 * @param string separador
 * @note Complejidad O(n*m)
 */
void MatrizDispersaLista::printMatrix(string separador){
    list<int>::iterator itValores = valores.begin();

    for (int i = 0; i < valores.size(); i++) {
        if (i + 1 != valores.size()) {
            cout << *itValores << separador;
        } else {
            cout << *itValores << endl;
        }
    }
}
/**
 * @brief Da el valor mayor en la matriz
 * @note Complejidad O(n)
 * @return el valor maximo de la matriz
 */
int MatrizDispersaLista::getMax(){
    int max = 1; // Para que no de problemas si esta vacia la matriz
    list<int>::iterator itValores = valores.begin();
    for (int i = 0; i<valores.size(); ++i) {
        if(max<*itValores){
            max = *itValores;
        }
        itValores++;
    }
    return max;
}

/**
 * @brief  Realiza el producto de la matriz dispersa por el vector recibido
 * @param vector<int> vec
 * @note Complejidad O(n*m)
 * @return el vector resultado del producto
 */
vector<int> MatrizDispersaLista::productVector(vector<int>& vec){
    list<int>::iterator itColumna= columnas.begin();
    list<int>::iterator itValores = valores.begin();
    list<int>::iterator itFilas = filas.begin();

    vector<int> producto(columnas.size(),1);

    for (int i = 0; i < filas.size(); i++) {
        int filaActual = *itFilas;
        int valorFila = *itValores;

        producto[filaActual] += valorFila * vec[*itColumna];
        itValores++;
        itColumna++;
        itFilas++;
    }

    return producto;
}
/**
 * @brief  construye la matriz dispersa correspondiente a la transpuesta del objeto actual.
 * @note Complejidad O(n*m)
 * @return la matriz resultante
 */
MatrizDispersaLista MatrizDispersaLista::getTranspose() {
    vector<list<int>> matrizTranspose(columnasOg);
    vector<list<int>> matrizRebuild = rebuild();
    for (int i = 0; i < filasOg; i++) {
        for (int j = 0; j < columnasOg; j++) {
            list<int>::iterator itMatRebuild = matrizRebuild[i].begin();
            advance(itMatRebuild, j);
            int valor = *itMatRebuild;
            if (valor != 0) {
                matrizTranspose[j].push_back(valor);
            }
        }
    }
    MatrizDispersaLista resultadoTranspose(matrizTranspose);
    return resultadoTranspose;
}

//MatrizDispersa MatrizDispersa::addMatrixList(list<MatrizDispersa> &matrices) {
//}

/**
 * @brief Suma dos matricesDispersaLista
 * @note Complejidad O(n)
 * @param MatrizDispersaLista otro
 * @return La suma de las matricesDispersaLista
 */
// PONER PARA QUE SE LLENE DE CEROS LA MAS PEQUENA
MatrizDispersaLista MatrizDispersaLista::operator+(MatrizDispersaLista &otro) {
    MatrizDispersaLista resultado(*this);
    resultado.add(otro);
    return resultado;
}
/**
 * @brief Multiplica dos matricesDispersaLista
 * @note Complejidad O(n^3)
 * @param MatrizDispersaLista otro
 * @return El producto de las matricesDispersaLista
 */
MatrizDispersaLista MatrizDispersaLista::operator*(MatrizDispersaLista& otro) {
    vector<list<int>> resultado(this->filasOg, list<int>(otro.columnasOg, 0));

    for (int i = 0; i < this->filasOg; ++i) {
        for (int j = 0; j < otro.columnasOg; ++j) {
            list<int> ::iterator itResultado = resultado[i].begin();
            for (int k = 0; k < this->columnasOg; ++k) {
                *itResultado += this->get(i,k) * otro.get(k, j);
                ++itResultado;
            }
        }
    }

    return MatrizDispersaLista(resultado);
}


/**
 * @brief Compara dos MatricesDispersaLista
 * @note Complejidad O(n)
 * @param MatrizDispersaLista otro
 * @return un bool que indica si son iguales
 */
bool MatrizDispersaLista:: operator==(MatrizDispersaLista& otro){
    bool resultado;
    if(this->valores == otro.valores && this->filas == otro.filas && this->columnas == otro.columnas){
        resultado = true;
    }else{
        resultado = false;
    }
    return resultado;
}