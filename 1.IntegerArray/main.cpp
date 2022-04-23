#include "iArray.h";

int main(void) {
    int n = 10;

    int* array;

    int* array2;

    cout << "Probando creacion de arreglo ... " ;

    array = create(n);
    cout << "Ok\n";

    cout << "Probando insercion en arreglo.. ";

    insert(array, 3, 145);
    cout << "Ok\n";

    cout <<"Mostrar valor insertado";
    cout << "Valor: " << array[3] << "\n";

    cout << "Sobreescribiendo insertado \n";
    insert(array, 3, 255);
    cout << "Ok\n";

    cout <<"Mostrar valor insertado";
    cout << "Valor: " << array[3] << "\n";

    cout << "Probando eliminacion .. ";
    destroy(array);
    cout << "Ok\n";

    cout << "Valor de la celda: " << array[3] << "\n";

    cout << "Nuevo arreglo...";
    array = create(n);
    cout << "Ok\n";

    cout << "Llenando arreglo de valores ... ";
    for(int i = 0; i < n; i++)
        insert(array, i, i);
    cout << "Ok\n";

    cout << "Mostrando primeras posiciones.. \n";
    cout << array[0] << "-" << array[1] << "-" << array[2] << "\n";

    cout << "Mostrando resultado de busqueda... \n";
    cout << "Resultado dato: " << search(array, n, 1) << "\n";
    cout << "Resultado dato: " << search(array, n, 2) << "\n";

    cout << "Provocando una repeticion de dato en el arreglo..  ";
    insert(array, 7, 3);
    cout << "Ok\n";

    cout << "Probando conteo de elementos: \n";
    cout << "El resultado del conteo es: " << count(array, n, 3) << "\n";

    cout << "Repeticion del conteo.. \n";
    cout << "El resultado es: " << count(array2, n, 3) << " \n";
    
    cout << "Probando inversion.. \n";
    array = reverse(array, n);
    cout << "Ok\n";

    cout << "Mostrando primeras posiciones del arreglo invertido \n";
    cout << array[0] << "-" << array[1] << "-" << array[2] << "\n";

    return 0;
}