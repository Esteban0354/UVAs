/*
 * Jose Barrera Ramos
 * Proyecto Estructura de Datos / Have Fun With Matrices
 */

//Librerias
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MatrizDispersa {
private:
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;

    int filasOriginal;
    int columnasOriginal;
public:
    MatrizDispersa(vector<vector<int>>& fullMatrix);
    MatrizDispersa(MatrizDispersa& otro);

    vector<vector<int>> rebuild();
    MatrizDispersa getTranspose();
};

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

MatrizDispersa::MatrizDispersa(MatrizDispersa &otro) {
    this->valores = otro.valores;
    this->filas = otro.filas;
    this->columnas = otro.columnas;
}

vector<vector<int>> MatrizDispersa::rebuild() {
    vector<vector<int>> fullMatrix(filasOriginal, vector<int>(columnasOriginal, 0));
    for (int k = 0; k < filas.size(); k++) {
        fullMatrix[filas[k]][columnas[k]] = valores[k];
    }
    return fullMatrix;
}

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

void havingFunWithMatrices(int num);
void row(MatrizDispersa& matrizDispersa, int valor1, int valor2);
void col(MatrizDispersa& matrizDispersa, int valor1, int valor2);
void inc(MatrizDispersa& matrizDispersa);
void dec(MatrizDispersa& matrizDispersa);
void transpose(MatrizDispersa& matrizDispersa);
void actualizarMatriz(MatrizDispersa& original, vector<vector<int>>& nuevaMatriz);
void havingFunWithMatrices(int num);

int main() {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        havingFunWithMatrices(i);
    }

    return 0;
}

void havingFunWithMatrices(int num) {
    int tamMatriz;
    cin >> tamMatriz;
    string valor;
    vector<vector<int>> matriz(tamMatriz, vector<int>(tamMatriz));

    for (int i = 0; i < tamMatriz; i++) {
        cin >> valor;
        for (int j = 0; j < tamMatriz; j++) {
            string ayuda = string(1, valor[j]);
            matriz[i][j] = stoi(ayuda);
        }
    }

    MatrizDispersa matrizDispersa(matriz);

    int numComandos;
    cin >> numComandos;
    string comandos;
    int valor1, valor2;

    while(numComandos) {
        numComandos--;
        cin >> comandos;

        if (comandos == "row") {
            cin >> valor1 >> valor2;
            row(matrizDispersa, valor1, valor2);
        } else if (comandos == "col") {
            cin >> valor1 >> valor2;
            col(matrizDispersa, valor1, valor2);
        } else if (comandos == "inc") {
            inc(matrizDispersa);
        } else if (comandos == "dec") {
            dec(matrizDispersa);
        } else if (comandos == "transpose") {
            transpose(matrizDispersa);
        }
    }

    cout << "Case #" << num + 1 << endl;
    vector<vector<int>> ayudaVector = matrizDispersa.rebuild();
    for (int i = 0; i < ayudaVector.size(); i++) {
        for (int j = 0; j < ayudaVector.size(); j++) {
            cout << ayudaVector[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void row(MatrizDispersa& matrizDispersa, int valor1, int valor2) {
    vector<vector<int>> matrizActualizada = matrizDispersa.rebuild();

    if(valor1 < matrizActualizada.size() && valor2 < matrizActualizada.size()) {
        vector<int> temp = matrizActualizada[valor1 - 1];
        matrizActualizada[valor1 - 1] = matrizActualizada[valor2 - 1];
        matrizActualizada[valor2 - 1] = temp;
        actualizarMatriz(matrizDispersa, matrizActualizada);
    }
}


void col(MatrizDispersa& matrizDispersa, int valor1, int valor2) {
    vector<vector<int>> matrizActualizada = matrizDispersa.rebuild();

    if(valor1 < matrizActualizada.size() && valor2 < matrizActualizada.size()) {
        for (int i = 0; i < matrizActualizada.size(); i++) {
            int temp = matrizActualizada[i][valor1 - 1];
            matrizActualizada[i][valor1 - 1] = matrizActualizada[i][valor2 - 1];
            matrizActualizada[i][valor2 - 1] = temp;
        }
        actualizarMatriz(matrizDispersa, matrizActualizada);
    }
}

void inc(MatrizDispersa& matrizDispersa) {
    vector<vector<int>> matrizActualizada = matrizDispersa.rebuild();
    int tamMatriz = matrizActualizada.size();
    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            matrizActualizada[i][j] += 1;
            matrizActualizada[i][j] = (matrizActualizada[i][j] == 10) ? 0 : matrizActualizada[i][j];
        }
    }

    actualizarMatriz(matrizDispersa, matrizActualizada);
}

void dec(MatrizDispersa& matrizDispersa) {
    vector<vector<int>> matrizActualizada = matrizDispersa.rebuild();
    int tamMatriz = matrizActualizada.size();
    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            matrizActualizada[i][j] -= 1;
            matrizActualizada[i][j] = (matrizActualizada[i][j] == -1) ? 10 : matrizActualizada[i][j];
        }
    }

    actualizarMatriz(matrizDispersa, matrizActualizada);
}

void transpose(MatrizDispersa& matrizDispersa) {
    MatrizDispersa matrizActualizada = matrizDispersa.getTranspose();
    matrizDispersa = matrizActualizada;
}

void actualizarMatriz(MatrizDispersa& original, vector<vector<int>>& nuevaMatriz) {
    MatrizDispersa nuevaMatrizDispersa(nuevaMatriz);
    original = nuevaMatrizDispersa;
}