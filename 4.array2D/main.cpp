#include "matrix.h"

char createLetter(int n) {
    return char(65 + n % 26);
}

int main(void) {
    int filas = 3, columnas = 4;

    int **matrix;
    int **matrix2;
    char **matrix3;
    char **matrix4;

    cout << "Probando creacion de matrix... ";
    matrix = create<int>(filas, columnas);
    cout << "OK\n";

    cout << "Probando inserción en matriz de enteros... ";
    insert<int>(matrix,2,3,145);
    cout << "OK\n";

    cout << "Mostrando valor insertado...\n";
    cout << "El valor insertado es: " << matrix[2][3] << "\n";

    cout << "Probando eliminación de matriz de enteros... ";
    destroy<int>(matrix, filas);
    cout << "OK\n";

    cout << "Llenando matriz de enteros con valores... ";
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            insert<int>(matrix,i,j,i+j);
    cout << "OK\n";

    cout << "Probando conteo de elementos en matriz de enteros...\n";
    cout << "El resultado del conteo es: " << count<int>(matrix, filas, columnas, 3) << "\n";

    cout << "Probando creación de copia de la matriz de enteros... ";
    matrix2 = createCopy<int>(matrix, filas, columnas);
    cout << "OK\n";

    

    return 0;
}