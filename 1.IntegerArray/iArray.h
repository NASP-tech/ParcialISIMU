#include<iostream>
#include<stdlib.h>

using namespace std;

int* create(int size) {
    int* array = (int*)malloc(sizeof(int)*size);
    return array;
}

void insert(int* array, int pos, int value) {
    array[pos] = value;
}

void destroy(int* array) {
    free(array);
}


bool search(int* array, int size, int value){
    bool ans = false;
    for(int i=0; i<size; i++)
        if(array[i]==value){
            break;
        }
        return ans;
}

int count(int* array, int size, int value){
    int cont = 0;
    for(int i = 0; i < size; i++)
        if(array[i] == value)
            cont++;

    return cont;
}

int* createCopy(int* original, int size) {
    int* newOne = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++)
        newOne[i] = original[i];

    return newOne;
}


int* reverse(int* array, int size) {
    int* array2 = (int*)malloc(sizeof(int)*size);

    for(int i = size-1; i >= 0; i--)
        array2[ size - (i+1)] = array[i];

    destroy(array);

    return array2;
}