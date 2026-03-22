
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

void float_scalar_multiply(float scalar, void* data){
    float* num = (float*)data;
    *num = scalar * *num;
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
    const Complex_number* num1 = (const Complex_number*)a;
    const Complex_number* num2 = (const Complex_number*)b;

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

    *(int*)(*result).Re = *(const int*)(*num1).Re + *(const int*)(*num2).Re;
    *(int*)(*result).Im = *(const int*)(*num1).Im + *(const int*)(*num2).Im;

    return result;
}

void* Complex_multiply(const void* a, const void* b){
    const Complex_number* num1 = (const Complex_number*)a;
    const Complex_number* num2 = (const Complex_number*)b;

    int re1 = *(const int*)(*num1).Re;
    int im1 = *(const int*)(*num1).Im;
    int re2 = *(const int*)(*num2).Re;
    int im2 = *(const int*)(*num2).Im;

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

    *(int*)(*result).Re = re1 * re2 - im1 * im2;
    *(int*)(*result).Im = re1 * im2 + im1 * re2;

    return result;
}

void Complex_scalar_multiply(float scalar, void* data){
    Complex_number* num = (Complex_number*)data;
    *(int*)(*num).Re = (int)(scalar * (*(int*)(*num).Re));
    *(int*)(*num).Im = (int)(scalar * (*(int*)(*num).Im));
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

    int question_of_random = question("Введите < y > если заполнить матрицу рандомом или < n > если вводить вручную : ");

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
        } else{
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
        (*matrix).typeinfo = &complex_array_typeinfo;
    }
    else{
        (*matrix).typeinfo = &float_array_typeinfo;
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

    number* m1 = (*matrix1).Matrix;
    number* m2 = (*matrix2).Matrix;

    for (int i = 0; i < rank_of_matrix * rank_of_matrix; i++){
        TypeInfo* info = m1[i].type_info;
        void* sum = (*info).summ(m1[i].type_num, m2[i].type_num);
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

    number* m1 = (*matrix1).Matrix;
    number* m2 = (*matrix2).Matrix;

    for (int i = 0; i < rank_of_matrix; i++){
        for (int j = 0; j < rank_of_matrix; j++){

            int index = i * rank_of_matrix + j;
            void* sum_data = NULL;
            TypeInfo* info = m1[i*rank_of_matrix].type_info;

            for (int k = 0; k < rank_of_matrix; k++){

                int indexA = i * rank_of_matrix + k;
                int indexB = k * rank_of_matrix + j;

                void* result_multiply = (*info).multiply(m1[indexA].type_num, m2[indexB].type_num);

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

Matrix* matrix_scalar_multiply(Matrix* matrix, float scalar){
    if (matrix == NULL){
        return NULL;
    }
    int rank_of_matrix = (*matrix).rank_of_matrix;

    Matrix* result = malloc(sizeof(Matrix));
    if (result == NULL) return NULL;

    number* result_data = malloc(rank_of_matrix * rank_of_matrix * sizeof(number));
    if (result_data == NULL){
        free(result);
        return NULL;
    }

    number* main_matrix = (*matrix).Matrix;

    for (int i = 0; i < rank_of_matrix * rank_of_matrix; i++){
        TypeInfo* info = main_matrix[i].type_info;
        void* main_matrix_data = main_matrix[i].type_num;
        void* new_elem = NULL;

        if (info == &float_typeinfo){
            float* float_new_elem = malloc(sizeof(float));
            if (float_new_elem == NULL){
                for (int j = 0; j < i; j++) free(result_data[j].type_num);
                free(result_data);
                free(result);
                return NULL;
            }
            *float_new_elem = *(float*)main_matrix_data;
            new_elem = float_new_elem;
        }
        else{
            if (info == &complex_typeinfo){
                Complex_number* copy_main_matrix = (Complex_number*)main_matrix_data;
                Complex_number* copy_new_elem = malloc(sizeof(Complex_number));
                if (copy_new_elem == NULL){
                    for (int j = 0; j < i; j++){
                        free(result_data[j].type_num);
                    }
                    free(result_data);
                    free(result);
                    return NULL;
                }
                (*copy_new_elem).Re = malloc(sizeof(int));
                (*copy_new_elem).Im = malloc(sizeof(int));
                if ((*copy_new_elem).Re == NULL || (*copy_new_elem).Im == NULL){
                    free((*copy_new_elem).Re);
                    free((*copy_new_elem).Im);
                    free(copy_new_elem);
                    for (int j = 0; j < i; j++) free(result_data[j].type_num);
                    free(result_data);
                    free(result);
                    return NULL;
                }

                *(*copy_new_elem).Re = *(*copy_main_matrix).Re;
                *(*copy_new_elem).Im = *(*copy_main_matrix).Im;
                new_elem = copy_new_elem;
            } 
            else{
                for (int j = 0; j < i; j++){
                    free(result_data[j].type_num);
                }
                free(result_data);
                free(result);
                return NULL;
            }
        }
        

        (*info).scalar_multiply(scalar, new_elem);
        result_data[i].type_num = new_elem;
        result_data[i].type_info = info;
    }

    (*result).Matrix = result_data;
    (*result).rank_of_matrix = rank_of_matrix;
    (*result).len_matrix = rank_of_matrix * rank_of_matrix;
    (*result).typeinfo = (*matrix).typeinfo;

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
