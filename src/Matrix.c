
#include "Matrix.h"
#include "io.h"
#include "dinamic_massive.h"


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char* number_print(const number* num, int epsilon_num){
    return (*((*num).type_info)).print((*num).type_num, epsilon_num);
}

char* float_print(const void* data, int epsilon_num){
    float num = *(const float*)data;
    int int_part = (int)num;
    int len_epsilon = 0, len_int = 0;
    int epsilon = epsilon_num;
    int start_i = 0;

    while (epsilon / 10 != 0){
        epsilon = epsilon / 10;
        len_epsilon++;
        if (int_part / 10 != 0){
            int_part = int_part / 10;
            len_int++;
        }
    }

    char *p_string = malloc(len_epsilon + 4);
    if (p_string == NULL){
        return NULL;
    }

    for (int i = 0; i < len_epsilon - len_int; i++){
        p_string[start_i++] = ' ';
    }

    if (num < 0){
        sprintf(p_string + start_i, "%.2f", num);
    }
    else{
        sprintf(p_string + start_i, " %.2f", num);
    }

    return p_string;
}

void* float_summ(const void* a, const void* b){
    float x = *(const float*)a;
    float y = *(const float*)b;
    float* result = malloc(sizeof(float));
    if (result == NULL){
        return NULL;
    }
    *result = x + y;
    return result;
}

void* float_multiply(const void* a, const void* b){
    float x = *(const float*)a;
    float y = *(const float*)b;
    float* result = malloc(sizeof(float));
    if (result == NULL){
        return NULL;
    }
    *result = x * y;
    return result;
}

void float_scalar_multiply(void *scalar, void* data, int type_scalar){

    if (type_scalar == 1){ 
        float* num = (float*)data;
        float* scl = (float*)scalar;
        *num = *scl * *num;
    } 
    else{

        float old_float_val = *(float*)data;
        free(data);

        Complex_number* new_complex_data = malloc(sizeof(Complex_number));
        if (new_complex_data == NULL){
            return;
        }
        (*new_complex_data).Re = malloc(sizeof(int));
        (*new_complex_data).Im = malloc(sizeof(int));
        if ((*new_complex_data).Re == NULL || (*new_complex_data).Im == NULL){
             free((*new_complex_data).Re);
             free((*new_complex_data).Im);
             free(new_complex_data);
             return;
        }
        *((*new_complex_data).Re) = (int)old_float_val;
        *((*new_complex_data).Im) = 0;

        Complex_number* scalar_complex = (Complex_number*)scalar;

        int Re1 = *((*new_complex_data).Re);
        int Imatrix_1 = *((*new_complex_data).Im);
        int Re2 = *((*scalar_complex).Re);
        int Imatrix_2 = *((*scalar_complex).Im);

        int New_Re = Re1 * Re2 - Imatrix_1 * Imatrix_2;
        int New_Im = Re1 * Imatrix_2 + Imatrix_1 * Re2;

        *((*new_complex_data).Re) = New_Re;
        *((*new_complex_data).Im) = New_Im;
    }
    
}

char* Complex_print(const void* data, int epsilon_num){
    const Complex_number* number = (const Complex_number*)data;
    int Re = *((*number).Re);
    int Im = *((*number).Im);

    int int_part_Re = Re, int_part_Im = Im;
    int len_epsilon_Re = 0, len_int_Re = 0;
    int len_epsilon_Im = 0, len_int_Im = 0;
    int epsilon_Re = epsilon_num, epsilon_Im = epsilon_num;

    while (epsilon_Re / 10 != 0){
        epsilon_Re = epsilon_Re / 10;
        len_epsilon_Re++;
        if (int_part_Re / 10 != 0){
            int_part_Re = int_part_Re / 10;
            len_int_Re++;
        }
    }
    while (epsilon_Im / 10 != 0){
        epsilon_Im = epsilon_Im / 10;
        len_epsilon_Im++;
        if (int_part_Im / 10 != 0){
            int_part_Im = int_part_Im / 10;
            len_int_Im++;
        }
    }

    char *p_string = malloc(len_epsilon_Re + 9 + len_epsilon_Im);
    if (p_string == NULL){
        return NULL;
    }
    
    int index = 0;
    for (int i = 0; i < len_epsilon_Re - len_int_Re; i++){
        p_string[index] = ' ';
        index++;
        
    }

    if (Re < 0){
        index += sprintf(p_string + index, "%d", Re);
    }
    else{
        index += sprintf(p_string + index, " %d", Re);
    }
        
    if (Im < 0){
        index += sprintf(p_string + index, "%di", Im);
    }
    else{
        index += sprintf(p_string + index, "+%di", Im);
    }
        
    for (int i = 0; i < len_epsilon_Im - len_int_Im; i++){
        p_string[index] = ' ';
        index++;
    }
    p_string[index] = '\0';
    return p_string;
}

void* Complex_summ(const void* a, const void* b){
    const Complex_number* numatrix_1 = (const Complex_number*)a;
    const Complex_number* numatrix_2 = (const Complex_number*)b;

    Complex_number* result = malloc(sizeof(Complex_number));
    if (result == NULL){
        return NULL;
    }

    (*result).Re = malloc(sizeof(int));
    (*result).Im = malloc(sizeof(int));
    if ((*result).Re == NULL || (*result).Im == NULL){
        free((*result).Re);
        free((*result).Im);
        free(result);
        return NULL;
    }

    *(int*)(*result).Re = *(const int*)(*numatrix_1).Re + *(const int*)(*numatrix_2).Re;
    *(int*)(*result).Im = *(const int*)(*numatrix_1).Im + *(const int*)(*numatrix_2).Im;

    return result;
}

void* Complex_multiply(const void* a, const void* b){
    const Complex_number* numatrix_1 = (const Complex_number*)a;
    const Complex_number* numatrix_2 = (const Complex_number*)b;

    int Re1 = *(const int*)(*numatrix_1).Re;
    int Imatrix_1 = *(const int*)(*numatrix_1).Im;
    int Re2 = *(const int*)(*numatrix_2).Re;
    int Imatrix_2 = *(const int*)(*numatrix_2).Im;

    Complex_number* result = malloc(sizeof(Complex_number));
    if (result == NULL){
        return NULL;
    }

    (*result).Re = malloc(sizeof(int));
    (*result).Im = malloc(sizeof(int));
    if ((*result).Re == NULL || (*result).Im == NULL){
        free((*result).Re);
        free((*result).Im);
        free(result);
        return NULL;
    }

    *(int*)(*result).Re = Re1 * Re2 - Imatrix_1 * Imatrix_2;
    *(int*)(*result).Im = Re1 * Imatrix_2 + Imatrix_1 * Re2;

    return result;
}

void Complex_scalar_multiply(void *scalar, void* data, int type_scalar){

    Complex_number* num = (Complex_number*)data;

    if (type_scalar == 1){
        int Re1 = *((*num).Re);
        int Imatrix_1 = *((*num).Im);
        float* scalar_floatloat = (float*)scalar;
        float scalar_float = *scalar_floatloat;

        *((*num).Re) = (int)((float)Re1 * scalar_float);
        *((*num).Im) = (int)((float)Imatrix_1 * scalar_float);
    } 
    else{
        Complex_number *scalar_complex = (Complex_number*)scalar;

        int Re1 = *((*num).Re);
        int Imatrix_1 = *((*num).Im);
        int Re2 = *((*scalar_complex).Re);
        int Imatrix_2 = *((*scalar_complex).Im);

        int New_Re = Re1 * Re2 - Imatrix_1 * Imatrix_2;
        int New_Im = Re1 * Imatrix_2 + Imatrix_1 * Re2;

        *((*num).Re) = New_Re;
        *((*num).Im) = New_Im;
    }
}

number *get_elem(Matrix *Matrix_info, int index){
    if  (index >= (*Matrix_info).len_matrix || index < 0){
        return NULL;
    }
    return (*Matrix_info).Matrix + index;
}

void set_elem(Matrix *Matrix_info, int index, number *elem){
    number *now_data = get_elem(Matrix_info, index);
    if (now_data == NULL){
        return;
    }
    *now_data = *elem;
}

number* create_float(float Real){
    number* num = malloc(sizeof(number));
    if (num == NULL){
        return NULL;
    }
    float* data = malloc(sizeof(float));
    if (data == NULL){
        free(num);
        return NULL;
    }
    *data = Real;
    
    (*num).type_num = data;
    (*num).type_info = &float_typeinfo;

    return num;
}

number* create_Complex(float Real, float Imag){
    number* num = malloc(sizeof(number));
    if (num == NULL){
        return NULL;
    }

    Complex_number* complex = malloc(sizeof(Complex_number));
    if (complex == NULL){
        free(num);
        return NULL;
    }

    (*complex).Re = malloc(sizeof(int));
    (*complex).Im = malloc(sizeof(int));
    if ((*complex).Re == NULL || (*complex).Im == NULL){
        free((*complex).Re);
        free((*complex).Im);
        free(complex);
        free(num);
        return NULL;
    }

    *((*complex).Re) = (int)Real;
    *((*complex).Im) = (int)Imag;

    (*num).type_num = complex;
    (*num).type_info = &complex_typeinfo;

    return num;
}

Matrix* create_matrix(int rank_matrix, int epsilon_num, int question_of_type){
    Matrix* matrix = malloc(sizeof(Matrix));
    if (matrix == NULL){
        return NULL;
    }

    number* data = malloc(rank_matrix * rank_matrix * sizeof(number));
    if (data == NULL){
        free(matrix);
        return NULL;
    }

    int question_of_random = question("Выберите способ заполнения матрицы:\n[y] Случайные значения\n[n] Ввод вручную\nВвод : ");

    if (question_of_random == 0){
        if (question_of_type == 0){
            for (int i = 0; i < rank_matrix; i++){
                for (int k = 0; k < rank_matrix; k++){
                    printf("\nВведите a%d%d (Re): ", i+1, k+1);
                    float Re = input_number(-1 * epsilon_num, epsilon_num, 0);
                    printf("Введите a%d%d (Im): ", i+1, k+1);
                    float Im = input_number(-1 * epsilon_num, epsilon_num, 0);

                    number* elem = create_Complex(Re, Im);
                    
                    if (elem == NULL){
                        for (int index = 0; index < i*rank_matrix + k; index++){
                            free(data[index].type_num);
                        }  
                        free(data);
                        free(matrix);
                        return NULL;
                    }

                    data[i*rank_matrix + k] = *elem;
                    free(elem);
                }
            }
        } 
        else{
            for (int i = 0; i < rank_matrix; i++){
                for (int k = 0; k < rank_matrix; k++){
                    printf("\nВведите a%d%d : ", i+1, k+1);
                    float Re = input_number(-1 * epsilon_num, epsilon_num, 0);
                    number* elem = create_float(Re);
                    if (elem == NULL){
                        for (int index = 0; index < i*rank_matrix + k; index++){
                            free(data[index].type_num);
                        }
                        free(data);
                        free(matrix);
                        return NULL;
                    }
                    data[i*rank_matrix + k] = *elem;
                    free(elem);
                }
            }
        }
    } 
    else{
        srand(time(NULL));
        if (question_of_type == 0){
            for (int i = 0; i < rank_matrix; i++){
                for (int k = 0; k < rank_matrix; k++){
                    float Re = (rand() % (2 * epsilon_num + 1)) - epsilon_num;
                    float Im = (rand() % (2 * epsilon_num + 1)) - epsilon_num;

                    number* elem = create_Complex(Re, Im);
                    if (elem == NULL){
                        for (int index = 0; index < i*rank_matrix + k; index++){
                            free(data[index].type_num);
                        }
                        free(data);
                        free(matrix);
                        return NULL;
                    }
                    data[i*rank_matrix + k] = *elem;
                    free(elem);
                }
            }
        } 
        else{
            for (int i = 0; i < rank_matrix; i++){
                for (int k = 0; k < rank_matrix; k++){
                    float Re = (rand() % (2 * epsilon_num + 1)) - epsilon_num;
                    number* elem = create_float(Re);
                    if (elem == NULL){
                        for (int index = 0; index < i*rank_matrix + k; index++){
                            free(data[index].type_num);
                        }
                        free(data);
                        free(matrix);
                        return NULL;
                    }
                    data[i*rank_matrix + k] = *elem;
                    free(elem);
                }
            }
        }
    }

    (*matrix).Matrix = data;
    (*matrix).rank_of_matrix = rank_matrix;
    (*matrix).len_matrix = rank_matrix * rank_matrix;
    if (question_of_type == 0){
        (*matrix).typeinfo = &complex_address_typeinfo;
    }
    else{
        (*matrix).typeinfo = &float_address_typeinfo;
    }
    return matrix;
}

Matrix* matrix_summ(Matrix* matrix1, Matrix* matrix2){
    if (matrix1 == NULL || matrix2 == NULL){
        return NULL;
    }
    if ((*matrix1).rank_of_matrix != (*matrix2).rank_of_matrix){
        return NULL;
    }
    
    int rank_of_matrix = (*matrix1).rank_of_matrix;

    Matrix* result = malloc(sizeof(Matrix));
    if (result == NULL){
        return NULL;
    }

    number* result_data = malloc(rank_of_matrix * rank_of_matrix * sizeof(number));
    if (result_data == NULL){
        free(result);
        return NULL;
    }

    number* matrix_1 = (*matrix1).Matrix;
    number* matrix_2 = (*matrix2).Matrix;

    for (int i = 0; i < rank_of_matrix * rank_of_matrix; i++){
        TypeInfo* info = matrix_1[i].type_info;
        void* sum = (*info).summ(matrix_1[i].type_num, matrix_2[i].type_num);
        if (sum == NULL){
            for (int j = 0; j < i; j++){
                free(result_data[j].type_num);
            }
            free(result_data);
            free(result);
            return NULL;
        }
        result_data[i].type_num = sum;
        result_data[i].type_info = info;
    }

    (*result).Matrix = result_data;
    (*result).rank_of_matrix = rank_of_matrix;
    (*result).len_matrix = rank_of_matrix * rank_of_matrix;
    (*result).typeinfo = (*matrix1).typeinfo;

    return result;
}

Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2){

    if (matrix1 == NULL || matrix2 == NULL){
        return NULL;
    }
    if ((*matrix1).rank_of_matrix != (*matrix2).rank_of_matrix){
        return NULL;
    }

    int rank_of_matrix = (*matrix1).rank_of_matrix;

    Matrix* result = malloc(sizeof(Matrix));
    if (result == NULL) return NULL;

    number* result_data = malloc(rank_of_matrix * rank_of_matrix * sizeof(number));
    if (result_data == NULL){
        free(result);
        return NULL;
    }

    number* matrix_1 = (*matrix1).Matrix;
    number* matrix_2 = (*matrix2).Matrix;

    for (int i = 0; i < rank_of_matrix; i++){
        for (int j = 0; j < rank_of_matrix; j++){

            int index = i * rank_of_matrix + j;
            void* sum_data = NULL;
            TypeInfo* info = matrix_1[i*rank_of_matrix].type_info;

            for (int k = 0; k < rank_of_matrix; k++){

                int indexA = i * rank_of_matrix + k;
                int indexB = k * rank_of_matrix + j;

                void* result_multiply = (*info).multiply(matrix_1[indexA].type_num, matrix_2[indexB].type_num);

                if (result_multiply == NULL){
                    if (sum_data != NULL){
                        free(sum_data); 
                    }
                    for (int row = 0; row <= i; row++){
                        int col_limit;
                        if (row == i){
                            col_limit = j;
                        } 
                        else{
                            col_limit = rank_of_matrix;
                        }
                        for (int col = 0; col < col_limit; col++){
                            free(result_data[row * rank_of_matrix + col].type_num);
                        }  
                    }
                    free(result_data);
                    free(result);
                    return NULL;
                }

                if (k == 0){
                    sum_data = result_multiply;
                } 

                else{
                    void* new_sum = (*info).summ(sum_data, result_multiply);
                    free(sum_data);
                    free(result_multiply);
                    if (new_sum == NULL){
                        for (int row = 0; row <= i; row++){
                            int col_limit;
                            if (row == i){
                                col_limit = j;
                            } 
                            else{
                                col_limit = rank_of_matrix;
                            }
                            for (int col = 0; col < col_limit; col++){
                                free(result_data[row * rank_of_matrix + col].type_num);
                            }
                        }
                        free(result_data);
                        free(result);
                        return NULL;
                    }
                    sum_data = new_sum;
                }
            }

            result_data[index].type_num = sum_data;
            result_data[index].type_info = info;
        }
    }

    (*result).Matrix = result_data;
    (*result).rank_of_matrix = rank_of_matrix;
    (*result).len_matrix = rank_of_matrix * rank_of_matrix;
    (*result).typeinfo = (*matrix1).typeinfo;

    return result;
}

Matrix* matrix_scalar_multiply(Matrix* matrix, void *scalar, int type_scalar){
    if (matrix == NULL){
        return NULL;
    }

    int rank_of_matrix = (*matrix).rank_of_matrix;

    Matrix* result = malloc(sizeof(Matrix));
    if (result == NULL){
        return NULL;
    }

    number* result_data = malloc(rank_of_matrix * rank_of_matrix * sizeof(number));
    if (result_data == NULL){
        free(result);
        return NULL;
    }

    number* main_matrix = (*matrix).Matrix;

    int trigger_error = 1;

    for (int i = 0; i < rank_of_matrix * rank_of_matrix; i++){
        TypeInfo* info = main_matrix[i].type_info;
        void* main_matrix_data = main_matrix[i].type_num;

        TypeInfo* result_info = info;
        void* new_elem_data = NULL;

        if (info == &float_typeinfo){
            if (type_scalar == 0){
                float old_float_val = *(float*)main_matrix_data;

                Complex_number* number_complex = malloc(sizeof(Complex_number));
                if (number_complex == NULL){
                    trigger_error = 0;
                    break;
                }

                (*number_complex).Re = malloc(sizeof(int));
                (*number_complex).Im = malloc(sizeof(int));
                if ((*number_complex).Re == NULL || (*number_complex).Im == NULL){
                    free((*number_complex).Re);
                    free((*number_complex).Im);
                    free(number_complex);
                    trigger_error = 0;
                    break;
                }

                *((*number_complex).Re) = (int)old_float_val;
                *((*number_complex).Im) = 0;

                Complex_number* scalar_complex = (Complex_number*)scalar;

                int Re1 = *((*number_complex).Re);
                int Imatrix_1 = *((*number_complex).Im);
                int Re2 = *((*scalar_complex).Re);
                int Imatrix_2 = *((*scalar_complex).Im);

                Complex_number* final_complex = malloc(sizeof(Complex_number));
                if (final_complex == NULL){
                    free((*number_complex).Re);
                    free((*number_complex).Im);
                    free(number_complex);
                    trigger_error = 0;
                    break;
                }

                (*final_complex).Re = malloc(sizeof(int));
                (*final_complex).Im = malloc(sizeof(int));
                if ((*final_complex).Re == NULL || (*final_complex).Im == NULL){
                    free((*final_complex).Re);
                    free((*final_complex).Im);
                    free(final_complex);
                    free((*number_complex).Re);
                    free((*number_complex).Im);
                    free(number_complex);
                    trigger_error = 0;
                    break;
                }

                *((*final_complex).Re) = Re1 * Re2 - Imatrix_1 * Imatrix_2;
                *((*final_complex).Im) = Re1 * Imatrix_2 + Imatrix_1 * Re2;

                free((*number_complex).Re);
                free((*number_complex).Im);
                free(number_complex);

                new_elem_data = final_complex;
                result_info = &complex_typeinfo;
            }
            else{
                float* copy_float = malloc(sizeof(float));
                if (copy_float == NULL){
                    trigger_error = 0;
                    break;
                }

                *copy_float = *(float*)main_matrix_data;
                *copy_float = (*copy_float) * (*(float*)scalar);

                new_elem_data = copy_float;
                result_info = &float_typeinfo;
            }
        }
        else{
            if (info == &complex_typeinfo){
                Complex_number* original_complex = (Complex_number*)main_matrix_data;

                Complex_number* copy_complex = malloc(sizeof(Complex_number));
                if (copy_complex == NULL){
                    trigger_error = 0;
                    break;
                }

                (*copy_complex).Re = malloc(sizeof(int));
                (*copy_complex).Im = malloc(sizeof(int));
                if ((*copy_complex).Re == NULL || (*copy_complex).Im == NULL){
                    free((*copy_complex).Re);
                    free((*copy_complex).Im);
                    free(copy_complex);
                    trigger_error = 0;
                    break;
                }

                *((*copy_complex).Re) = *((*original_complex).Re);
                *((*copy_complex).Im) = *((*original_complex).Im);

                if (type_scalar == 1){
                    int Re1 = *((*copy_complex).Re);
                    int Imatrix_1 = *((*copy_complex).Im);
                    float scalar_float = *(float*)scalar;

                    *((*copy_complex).Re) = (int)((float)Re1 * scalar_float);
                    *((*copy_complex).Im) = (int)((float)Imatrix_1 * scalar_float);
                }
                else{
                    Complex_number* scalar_complex = (Complex_number*)scalar;

                    int Re1 = *((*copy_complex).Re);
                    int Imatrix_1 = *((*copy_complex).Im);
                    int Re2 = *((*scalar_complex).Re);
                    int Imatrix_2 = *((*scalar_complex).Im);

                    int New_Re = Re1 * Re2 - Imatrix_1 * Imatrix_2;
                    int New_Im = Re1 * Imatrix_2 + Imatrix_1 * Re2;

                    *((*copy_complex).Re) = New_Re;
                    *((*copy_complex).Im) = New_Im;
                }

                new_elem_data = copy_complex;
                result_info = &complex_typeinfo;
            }
            else{
                trigger_error = 0;
                break;
            }
        }

        result_data[i].type_num = new_elem_data;
        result_data[i].type_info = result_info;
    }

    if (trigger_error == 0){
        for (int j = 0; j < rank_of_matrix * rank_of_matrix; j++){
            if (result_data[j].type_info == &float_typeinfo){
                free(result_data[j].type_num);
            }
            else{
                Complex_number* complex_elem = (Complex_number*)result_data[j].type_num;
                free((*complex_elem).Re);
                free((*complex_elem).Im);
                free(complex_elem);
            }
        }

        free(result_data);
        free(result);
        return NULL;
    }

    (*result).Matrix = result_data;
    (*result).rank_of_matrix = rank_of_matrix;
    (*result).len_matrix = rank_of_matrix * rank_of_matrix;

    if (result_data[0].type_info == &complex_typeinfo){
        (*result).typeinfo = &complex_address_typeinfo;
    }
    else{
        (*result).typeinfo = &float_address_typeinfo;
    }

    return result;
}

void draw_matrix(int type_matrix, number* matrix, int rank_matrix, int epsilon_num){
    if (type_matrix == 0){
        printf("\nШаблон заполнения матрицы : \n");
        for (int i = 0; i < rank_matrix; i++){
            printf("\n| ");
            for (int k = 0; k < rank_matrix; k++){
                printf("a%d%d ", i+1, k+1);
            }
            printf("|");
        }
    }
    else{
        printf("\n");
        for (int i = 0; i < rank_matrix; i++){
            printf("\n|");
            for (int k = 0; k < rank_matrix; k++){
                int index = i * rank_matrix + k;
                char* str = number_print(&matrix[index], epsilon_num);
                if (str){
                    printf("%s ", str);
                    free(str);
                }
                else{
                    printf("??? ");
                }
            }
            printf("|");
        }
    }
    printf("\n");
}

TypeInfo float_typeinfo ={
    .print = float_print,
    .summ = float_summ,
    .multiply = float_multiply,
    .scalar_multiply = float_scalar_multiply
};

TypeInfo complex_typeinfo ={

    .print = Complex_print,
    .summ = Complex_summ,
    .multiply = Complex_multiply,
    .scalar_multiply = Complex_scalar_multiply
};
