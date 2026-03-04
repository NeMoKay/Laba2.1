#ifndef INPUT_DATA_H
#define INPUT_DATA_H


typedef struct{
    void* Re;
    void* Im;
    char* (*print)(const void*, int);
    void* (*summ)(const void*, const void*);
    void* (*multiply)(const void*, const void*);
    void (*scalar_multiply)(float, void*);
}Complex_number;


int input_data();

//-----------------------

char* float_print(const void* Stuct_Re1, int epsilon_num);
void* float_summ(const void* Stuct_Re1, const void* Stuct_Re2);
void* float_multiply(const void* Stuct_Re1, const void* Stuct_Re2);
void float_scalar_multiply(float scalar, void* Struct_Re1);

char* Complex_print(const void* Comlex1, int epsilon_num);
void* Complex_summ(const void* Comlex1, const void* Comlex2);
void* Complex_multiply(const void* Comlex1, const void* Comlex2);
void Complex_scalar_multiply(float scalar, void* Struct);

Complex_number* create_float(float Real);
Complex_number* create_Complex(float Real, float Imag);

Complex_number* create_matrix(int rank_matrix, int epsilon_num, int question_of_type);
Complex_number* matrix_summ(Complex_number* matrix1, Complex_number* matrix2, int rank_matrix);
Complex_number* matrix_multiply(Complex_number* matrix1, Complex_number* matrix2, int rank_matrix);
Complex_number* matrix_scalar_multiply(Complex_number* matrix, float scalar, int rank_matrix);

void draw_matrix(int tipe_matrix, Complex_number* matrix, int rank_matrix, int epsilon_num);





// typedef struct{
//     void (*print)(const void*, int);
//     void* (*summ)(const void*, const void*);
//     void* (*multiply)(const void*, const void*);
//     void (*scalar_multiply)(float, void*);
// }int_govno;

// typedef struct{
//     void (*print)(const void*, int);
//     void* (*summ)(const void*, const void*);
//     void* (*multiply)(const void*, const void*);
//     void (*scalar_multiply)(float, void*);
// }float_govno;


// typedef struct{
//     void* Re;
//     void* Im;
//     void* float_ili_int_govno
// }Complex_number;











#endif