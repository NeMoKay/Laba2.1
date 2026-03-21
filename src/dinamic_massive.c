#include "Matrix.h"
#include "dinamic_massive.h"
#include <stdlib.h>

void* add_forward_float(Matrix* matrix){
    number* arr = (*matrix).Matrix;
    int len = (*matrix).len_matrix;
    number* new_address = realloc(arr, (len + 1) * sizeof(number));
    if (new_address == NULL){
        return NULL;
    }
    int index = len;
    new_address[index].type_num = NULL;
    new_address[index].type_info = &float_typeinfo;

    (*matrix).len_matrix++;
    (*matrix).Matrix = new_address;
    return new_address;
}

void* add_forward_complex(Matrix* matrix){
    number* arr = (*matrix).Matrix;
    int len = (*matrix).len_matrix;
    number* new_address = realloc(arr, (len + 1) * sizeof(number));
    if (new_address == NULL) return NULL;

    int index = len;
    new_address[index].type_num = NULL;
    new_address[index].type_info = &complex_typeinfo;

    (*matrix).len_matrix++;
    (*matrix).Matrix = new_address;
    return new_address;
}

TypeInfo_Matrix float_array_typeinfo ={
    .add_forward = add_forward_float
};

TypeInfo_Matrix complex_array_typeinfo ={
    .add_forward = add_forward_complex
};






































































