#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename type>
type** create(int rows, int cols){
    type** matrix = (type**)malloc(sizeof(type*)*rows);

    for(int i = 0; i < rows; i++){
        *(matrix + i) = (type*)malloc(sizeof(type)*cols);
    }
    return matrix;
}

template <typename type>
void insert(type** matrix, int row, int col, type value){
    matrix[row][col] = value;
}

template <typename type>
void destroy(type** matrix, int nrows) {
    for(int i = 0; i < nrows; i++){
        free(*(matrix + i));
    }
    free(matrix);
}

template <typename type>
bool search(type** matrix, int nrows, int ncols, type value){
    bool ans = false;

    for(int i = 0; i < nrows*ncols; i++){
        if(matrix[i/ncols][i%ncols] == value){
            ans = true;
            break;
        }
    }
    return ans;
}

template <typename type>
int count (type** matrix, int nrows, int ncols, type value){
    int cont = 0;

    for(int i = 0; i < nrows*ncols; i++){
        if(matrix[i/ncols][i%ncols] == value){
            cont++;
        }
    }
    return cont;
}

template <typename type>
type** createCopy(type** original, int nrows, int ncols){
    type** newOne = (type**)malloc(sizeof(type*)*nrows);

    for(int i = 0; i < nrows; i++){
        *(newOne + 1) = (type*)malloc(sizeof(type)(*ncols));
    }

    for(int i = 0; i < nrows*ncols; i++){
        newOne[i/ncols][i%ncols] = original[i/ncols][i%ncols];
    }

    return newOne;
}