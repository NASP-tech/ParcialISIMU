#include "array.h"

char createLetter(int n){
    return char(65 + n % 26);
}

int main(void){
    int n = 10;
    int* array;
    int* array2;
    char* array3;
    char* array4;

    cout << "Probando creacion de arreglo de enteros..";

    array = create<int>(n);
    cout << "OK\n";

    cout << "Probando insercion... enteros";
    insert<int>(array, 3, 145);
    cout << "OK\n";

    cout << "Mostrando valor insertado... \n";
    cout << "El valor insertado es: " << array[3] << "\n";

    cout << "Sobreescribiendo valor insertado anteriormente... ";
    insert<int>(array, 3, 225);
    cout << "OK\n";

    cout << "Mostrando nuevo valor insertado ... \n";
    cout << "El valor es: " << array[3] << "\n";

    cout << "Resultado de búsqueda de dato existente: " << search<char>(array3, n, createLetter(5)) << "\n"; //Sé que la letra obtenida a partir del número 5 está en el arreglo
    cout << "Resultado de búsqueda de dato no existente: " << search<char>(array3, n, '#') << "\n";           //Sé que el caracter '#' no está en el arreglo

    cout << "Provocando una repetición de dato en el arreglo de caracteres... ";
    insert<char>(array3,7,createLetter(3));

    cout << "Probando creación de copia del arreglo de caracteres... ";
    array4 = createCopy<char>(array3, n);
    cout << "OK\n";

    cout << "Probando inversión del arreglo de caracteres... ";
    array3 = reverse<char>(array3, n);
    cout << "OK\n";

    return 0;

}