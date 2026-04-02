#ifndef MATRIX_H
#define MATRIX_H

#include "dinamic_massive.h"

typedef struct TypeInfo{
    char* (*print)(const void* data, int epsilon_num);
    void* (*summ)(const void* a, const void* b);
    void* (*multiply)(const void* a, const void* b);
    void  (*scalar_multiply)(void* scalar, void* data, int type_scalar);
} TypeInfo;

typedef struct Complex_number{
    int* Re;
    int* Im;
} Complex_number;

typedef struct number{
    void* type_num;
    TypeInfo* type_info;
} number;

char* number_print(const number* num, int epsilon_num);
char* float_print(const void* data, int epsilon_num);
void* float_summ(const void* a, const void* b);
void* float_multiply(const void* a, const void* b);
void float_scalar_multiply(void *scalar, void* data, int type_scalar);

char* Complex_print(const void* data, int epsilon_num);
void* Complex_summ(const void* a, const void* b);
void* Complex_multiply(const void* a, const void* b);
void Complex_scalar_multiply(void *scalar, void* data, int type_scalar);

number* create_float(float Real);
number* create_Complex(float Real, float Imag);

Matrix* create_matrix(int rank_matrix, int epsilon_num, int question_of_type);
Matrix* matrix_summ(Matrix* matrix1, Matrix* matrix2);
Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2);
Matrix* matrix_scalar_multiply(Matrix* matrix, void *scalar, int type_scalar);

number *get_elem(Matrix *Matrix_info, int index);
void set_elem(Matrix *Matrix_info, int index, number *elem);

void draw_matrix(int type_matrix, number* matrix, int rank_matrix, int epsilon_num);

extern TypeInfo float_typeinfo;
extern TypeInfo complex_typeinfo;

#endif