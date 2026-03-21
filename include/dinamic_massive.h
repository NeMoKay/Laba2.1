#ifndef DINAMIC_MASSIVE_H
#define DINAMIC_MASSIVE_H

typedef struct Matrix Matrix;
typedef struct number number;

typedef struct TypeInfo_Matrix{
    void* (*add_forward)(Matrix* matrix);
} TypeInfo_Matrix;

struct Matrix{
    number* Matrix;
    int rank_of_matrix;
    int len_matrix;
    TypeInfo_Matrix* typeinfo;
};

extern TypeInfo_Matrix float_array_typeinfo;
extern TypeInfo_Matrix complex_array_typeinfo;

#endif