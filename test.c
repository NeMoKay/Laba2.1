
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "test.h"
#include "input_data.h"
#include "dinamic_massive.h"



int test_print_float(){
    int eps = 100;
    int count_error = 0;
    char *test_str;
    
    //1
    Complex_number *Test1 = malloc(sizeof(Complex_number));
    (*Test1).Re = malloc(sizeof(float));
    *(float*)(*Test1).Re = 42.42;
    test_str = float_print(Test1, eps);
    if(strcmp("  42.42", test_str) != 0){
        printf("\n\nФункция float_print тест №1 провален.\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Test1).Re);
    free(Test1);

    //2
    Complex_number *Test2 = malloc(sizeof(Complex_number));
    (*Test2).Re = malloc(sizeof(float));
    *(float*)(*Test2).Re = -42.42;
    test_str = float_print(Test2, eps);
    if(strcmp(" -42.42", test_str) != 0){
        printf("\n\nФункция float_print тест №2 провален.\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Test2).Re);
    free(Test2);

    //3
    Complex_number *Test3 = malloc(sizeof(Complex_number));
    (*Test3).Re = malloc(sizeof(float));
    *(float*)(*Test3).Re = 2.42;
    test_str = float_print(Test3, eps);
    if(strcmp("   2.42", test_str) != 0){
        printf("\n\nФункция float_print тест №3 провален.\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Test3).Re);
    free(Test3);

    //4
    Complex_number *Test4 = malloc(sizeof(Complex_number));
    (*Test4).Re = malloc(sizeof(float));
    *(float*)(*Test4).Re = -2.42;
    test_str = float_print(Test4, eps);
    if(strcmp("  -2.42", test_str) != 0){
        printf("\n\nФункция float_print тест №4 провален.\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Test4).Re);
    free(Test4);

    //5
    // Complex_number *Test5 = malloc(sizeof(Complex_number));
    // (*Test5).Re = malloc(sizeof(float));
    // *(float*)(*Test5).Re = eps+1;
    // test_str = float_print(Test5, eps);
    // if(test_str != NULL){
    //     printf("\n\nФункция float_print тест №5 провален.\nЧисло вне диапазона прошло");
    //     count_error++;
    // }
    // free((*Test4).Re);
    // free(Test4);

    return count_error;
}

int test_float_summ(){


    int count_error = 0;
    Complex_number *rezult;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T1 = malloc(sizeof(Complex_number));
    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct2_T1).Re = malloc(sizeof(float));
    *(float*)(*Struct1_T1).Re = 20;
    *(float*)(*Struct2_T1).Re = 22;
    rezult = float_summ(Struct1_T1, Struct2_T1);
    if(*(float*)(*rezult).Re != 42){
        printf("\n\nФункция float_summ тест №1 провален.\nНесоответсвие результата суммы");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct2_T1).Re);
    free(Struct1_T1);
    free(Struct2_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T2 = malloc(sizeof(Complex_number));
    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct2_T2).Re = malloc(sizeof(float));
    *(float*)(*Struct1_T2).Re = 82;
    *(float*)(*Struct2_T2).Re = -40;
    rezult = float_summ(Struct1_T2, Struct2_T2);
    if(*(float*)(*rezult).Re != 42){
        printf("\n\nФункция float_summ тест №2 провален.\nНесоответсвие результата суммы");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct2_T2).Re);
    free(Struct1_T2);
    free(Struct2_T2);

    return count_error;
}

int test_float_multiply(){
    int count_error = 0;
    Complex_number *rezult;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T1 = malloc(sizeof(Complex_number));
    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct2_T1).Re = malloc(sizeof(float));
    *(float*)(*Struct1_T1).Re = 21;
    *(float*)(*Struct2_T1).Re = 2;
    rezult = float_multiply(Struct1_T1, Struct2_T1);
    if(*(float*)(*rezult).Re != 42){
        printf("\n\nФункция float_multiply тест №1 провален.\nНесоответсвие результата произведения");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct2_T1).Re);
    free(Struct1_T1);
    free(Struct2_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T2 = malloc(sizeof(Complex_number));
    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct2_T2).Re = malloc(sizeof(float));
    *(float*)(*Struct1_T2).Re = 1;
    *(float*)(*Struct2_T2).Re = -42;
    rezult = float_multiply(Struct1_T2, Struct2_T2);
    if(*(float*)(*rezult).Re != -42){
        printf("\n\nФункция float_multiply тест №2 провален.\nНесоответсвие результата произведения");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct2_T2).Re);
    free(Struct1_T2);
    free(Struct2_T2);

    return count_error;
}

int test_float_scalar_multiply(){
    float scalar = 2;
    int count_error = 0;
    //1
    Complex_number *Struct_T1 = malloc(sizeof(Complex_number));
    (*Struct_T1).Re = malloc(sizeof(float));
    *(float*)(*Struct_T1).Re = 21;
    float_scalar_multiply(scalar, Struct_T1);
    if(*(float*)(*Struct_T1).Re != 42){
        printf("\n\nФункция test_float_scalar_multiply тест №1 провален.\nНесоответсвие результата произведения на скаляр");
        count_error++;
    }

    //2
    scalar = -1;
    Complex_number *Struct_T2 = malloc(sizeof(Complex_number));
    (*Struct_T2).Re = malloc(sizeof(float));
    *(float*)(*Struct_T2).Re = -42;
    float_scalar_multiply(scalar, Struct_T2);
    if(*(float*)(*Struct_T2).Re != 42){
        printf("\n\nФункция test_float_scalar_multiply тест №2 провален.\nНесоответсвие результата произведения на скаляр");
        count_error++;
    }
    return count_error;
}


int test_Complex_print(){
    int count_error = 0, eps = 100;
    char *test_str;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));

    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct1_T1).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T1).Re = 42.42;
    *(float*)(*Struct1_T1).Im = 42.42;

    test_str = Complex_print(Struct1_T1, eps);
    if(strcmp("  42.42+42.42i ", test_str) != 0){
        printf("\n\nФункция test_Complex_print тест №1 провален\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct1_T1).Im);
    free(Struct1_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));

    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct1_T2).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T2).Re = -42.42;
    *(float*)(*Struct1_T2).Im = -42.42;

    test_str = Complex_print(Struct1_T2, eps);
    if(strcmp(" -42.42-42.42i ", test_str) != 0){
        printf("\n\nФункция test_Complex_print тест №2 провален\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct1_T2).Im);
    free(Struct1_T2);

    //3
    Complex_number *Struct1_T3 = malloc(sizeof(Complex_number));

    (*Struct1_T3).Re = malloc(sizeof(float));
    (*Struct1_T3).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T3).Re = 2.42;
    *(float*)(*Struct1_T3).Im = 2.42;

    test_str = Complex_print(Struct1_T3, eps);

    if(strcmp("   2.42+2.42i  ", test_str) != 0){
        printf("\n\nФункция test_Complex_print тест №3 провален\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Struct1_T3).Re);
    free((*Struct1_T3).Im);
    free(Struct1_T3);

    //4
    Complex_number *Struct1_T4 = malloc(sizeof(Complex_number));

    (*Struct1_T4).Re = malloc(sizeof(float));
    (*Struct1_T4).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T4).Re = -2.42;
    *(float*)(*Struct1_T4).Im = -2.42;

    test_str = Complex_print(Struct1_T4, eps);
    
    if(strcmp("  -2.42-2.42i  ", test_str) != 0){
        printf("\n\nФункция test_Complex_print тест №4 провален\nНесоответсвие строки результата");
        count_error++;
    }
    free((*Struct1_T4).Re);
    free((*Struct1_T4).Im);
    free(Struct1_T4);
    
    //5
    // Complex_number *Struct1_T5 = malloc(sizeof(Complex_number));

    // (*Struct1_T5).Re = malloc(sizeof(float));
    // (*Struct1_T5).Im = malloc(sizeof(float));

    // *(float*)(*Struct1_T5).Re = eps+1;
    // *(float*)(*Struct1_T5).Im = eps+1;

    // test_str = Complex_print(Struct1_T5, eps);
    
    // if(test_str != NULL){
    //     printf("\n\nФункция test_Complex_print тест №5 провален\nЧисло вне диапазона прошло");
    //     count_error++;
    // }
    // free((*Struct1_T5).Re);
    // free((*Struct1_T5).Im);
    // free(Struct1_T5);

    return count_error;
}

int test_Complex_summ(){
    int count_error = 0;
    Complex_number *result;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T1 = malloc(sizeof(Complex_number));

    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct1_T1).Im = malloc(sizeof(float));

    (*Struct2_T1).Re = malloc(sizeof(float));
    (*Struct2_T1).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T1).Re = 21;
    *(float*)(*Struct1_T1).Im = 21;

    *(float*)(*Struct2_T1).Re = 21;
    *(float*)(*Struct2_T1).Im = 21;

    result = Complex_summ(Struct1_T1, Struct2_T1);

    if(*(float*)(*result).Re != 42 || *(float*)(*result).Im != 42){
        printf("\n\nФункция Complex_summ тест №1 провален.\nНесоответсвие результата суммы");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct2_T1).Re);
    free((*Struct1_T1).Im);
    free((*Struct2_T1).Im);
    free(Struct1_T1);
    free(Struct2_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T2 = malloc(sizeof(Complex_number));

    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct1_T2).Im = malloc(sizeof(float));

    (*Struct2_T2).Re = malloc(sizeof(float));
    (*Struct2_T2).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T2).Re = 43;
    *(float*)(*Struct1_T2).Im = 43;

    *(float*)(*Struct2_T2).Re = -1;
    *(float*)(*Struct2_T2).Im = -1;

    result = Complex_summ(Struct1_T2, Struct2_T2);

    if(*(float*)(*result).Re != 42 || *(float*)(*result).Im != 42) {
        printf("\n\nФункция Complex_summ тест №2 провален.\nНесоответсвие результата суммы");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct2_T2).Re);
    free((*Struct1_T2).Im);
    free((*Struct2_T2).Im);
    free(Struct1_T2);
    free(Struct2_T2);


    return count_error;
}

int test_Complex_multiply(){
    int count_error = 0;
    Complex_number *result;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T1 = malloc(sizeof(Complex_number));

    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct1_T1).Im = malloc(sizeof(float));

    (*Struct2_T1).Re = malloc(sizeof(float));
    (*Struct2_T1).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T1).Re = 0;
    *(float*)(*Struct1_T1).Im = -7;

    *(float*)(*Struct2_T1).Re = -6;
    *(float*)(*Struct2_T1).Im = 6;

    result = Complex_multiply(Struct1_T1, Struct2_T1);

    if(*(float*)(*result).Re != 42 || *(float*)(*result).Im != 42){
        printf("\n\nФункция Complex_multiply тест №1 провален.\nНесоответсвие результата произведения");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct2_T1).Re);
    free((*Struct1_T1).Im);
    free((*Struct2_T1).Im);
    free(Struct1_T1);
    free(Struct2_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));
    Complex_number *Struct2_T2 = malloc(sizeof(Complex_number));

    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct1_T2).Im = malloc(sizeof(float));

    (*Struct2_T2).Re = malloc(sizeof(float));
    (*Struct2_T2).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T2).Re = 7;
    *(float*)(*Struct1_T2).Im = 0;

    *(float*)(*Struct2_T2).Re = -6;
    *(float*)(*Struct2_T2).Im = -6;

    result = Complex_multiply(Struct1_T2, Struct2_T2);

    if(*(float*)(*result).Re != -42 || *(float*)(*result).Im != -42){
        printf("\n\nФункция Complex_multiply тест №2 провален.\nНесоответсвие результата произведения");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct2_T2).Re);
    free((*Struct1_T2).Im);
    free((*Struct2_T2).Im);
    free(Struct1_T2);
    free(Struct2_T2);


    return count_error;
}

int test_Complex_scalar_multiply(){
    float scalar = 2;
    int count_error = 0;

    //1
    Complex_number *Struct1_T1 = malloc(sizeof(Complex_number));

    (*Struct1_T1).Re = malloc(sizeof(float));
    (*Struct1_T1).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T1).Re = 21;
    *(float*)(*Struct1_T1).Im = 21;

    Complex_scalar_multiply(scalar, Struct1_T1);
    if(*(float*)(*Struct1_T1).Re != 42 || *(float*)(*Struct1_T1).Im != 42){
        printf("\n\nФункция test_Complex_scalar_multiply тест №1 провален.\nНесоответсвие результата произведения на скаляр");
        count_error++;
    }
    free((*Struct1_T1).Re);
    free((*Struct1_T1).Im);
    free(Struct1_T1);

    //2
    Complex_number *Struct1_T2 = malloc(sizeof(Complex_number));

    (*Struct1_T2).Re = malloc(sizeof(float));
    (*Struct1_T2).Im = malloc(sizeof(float));

    *(float*)(*Struct1_T2).Re = -21;
    *(float*)(*Struct1_T2).Im = -21;

    Complex_scalar_multiply(scalar, Struct1_T2);
    if(*(float*)(*Struct1_T2).Re != -42 || *(float*)(*Struct1_T2).Im != -42){
        printf("\n\nФункция test_Complex_scalar_multiply тест №2 провален.\nНесоответсвие результата произведения на скаляр");
        count_error++;
    }
    free((*Struct1_T2).Re);
    free((*Struct1_T2).Im);
    free(Struct1_T2);

    return count_error;
}


int test_create_float(){
    int count_error = 0;
    float num = 42.0;

    Complex_number *result = malloc(sizeof(Complex_number));
    
    //1
    result = create_float(num);
    if(result == NULL){
        printf("\n\nФункция test_create_float тест №1 провален.\nНеудалсь выделить память");
        count_error++;
    }

    //2
    result = create_float(num);
    if(*(float*)(*result).Re != num){
        printf("\n\nФункция test_create_float тест №2 провален.\nНесоответсвие значения записанной переменной");
        count_error++;
    }


    free(result);
    return count_error;
}

int test_create_Complex(){
    int count_error = 0;
    float num_Re = 42.0,  num_Im = 42.0;
    Complex_number *result = malloc(sizeof(Complex_number));
    
    //1
    result = create_Complex(num_Re, num_Im);
    if(result == NULL){
        printf("\n\nФункция test_create_Complex тест №1 провален.\nНеудалсь выделить память");
        count_error++;
    }
    //2
    result = create_Complex(num_Re, num_Im);
    if(*(float*)(*result).Re != num_Re || (*(float*)(*result).Im != num_Im)){
        printf("\n\nФункция test_create_float тест №2 провален.\nНесоответсвие значения записанной переменной");
        count_error++;
    }


    free(result);
    return count_error;
}


int test_gen_massive(){
    int count_error = 0;
    Complex_number *massive;

    //1
    massive = gen_massive();
    if(massive == NULL){
        printf("\n\nФункция test_gen_massive тест №1 провален.\nНеудалсь выделить память");
        count_error++;
    }
    return count_error;
}

int test_add_forward(){
    int count_error = 0;
    int len = 2;
    Complex_number *massive;

    //1
    massive = add_forward(massive, &len);
    if(massive == NULL){
        printf("\n\nФункция test_add_forward тест №1 провален.\nНеудалсь выделить память");
        count_error++;
    }

    return count_error;
}


int test_matrix_summ(){
    int count_error = 0;
    int rank_matrix = 2;
    Complex_number *matrix1, *matrix2;
    int len_matrix1 = 0, len_matrix2 = 0;

    Complex_number *rezult = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
    
    //1
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_Complex(21, 21);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = (*copy).Im;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = (*copy).Im;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(*(float*)rezult[i].Re != 42 || *(float*)rezult[i].Im != 42){
            printf("\n\nФункция matrix_summ тест №1 провален.\nНесоответсвие матрицы суммы");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //2
    len_matrix1 = 0;
    len_matrix2 = 0;
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_Complex(21, 21);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = (*copy).Im;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = (*copy).Im;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(rezult[i].Re == NULL || rezult[i].Im == NULL){
            printf("\n\nФункция matrix_summ тест №2 провален.\nНеудалось выделить память");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    //3
    len_matrix1 = 0;
    len_matrix2 = 0;
    rank_matrix = 3;
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_Complex(21, 21);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = (*copy).Im;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = (*copy).Im;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(*(float*)rezult[i].Re != 42 || *(float*)rezult[i].Im != 42){
            printf("\n\nФункция matrix_summ тест №3 провален.\nНесоответсвие матрицы суммы");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    //4
    len_matrix1 = 0;
    len_matrix2 = 0;
    rank_matrix = 2;

    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_float(21);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = NULL;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = NULL;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(*(float*)rezult[i].Re != 42){
            printf("\n\nФункция matrix_summ тест №4 провален.\nНесоответсвие матрицы суммы");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //5
    len_matrix1 = 0;
    len_matrix2 = 0;
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_float(42);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = NULL;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = NULL;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    if(rezult == NULL){
        printf("\n\nФункция matrix_summ тест №5 провален.\nНеудалось выделить память");
        count_error++;
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    //6
    len_matrix1 = 0;
    len_matrix2 = 0;
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix; i++){
        for(int k = 0; k < rank_matrix; k++){
            matrix1 = add_forward(matrix1, &len_matrix1);
            matrix2 = add_forward(matrix2, &len_matrix2);
            int index = len_matrix1 - 1;
            Complex_number* copy = create_Complex(21, 21);
            matrix1[index].Re = (*copy).Re;
            matrix1[index].Im = (*copy).Im;
            matrix1[index].print = (*copy).print;
            matrix1[index].summ = (*copy).summ;
            matrix1[index].multiply = (*copy).multiply;
            matrix1[index].scalar_multiply = (*copy).scalar_multiply;
            matrix2[index].Re = (*copy).Re;
            matrix2[index].Im = (*copy).Im;
            matrix2[index].print = (*copy).print;
            matrix2[index].summ = (*copy).summ;
            matrix2[index].multiply = (*copy).multiply;
            matrix2[index].scalar_multiply = (*copy).scalar_multiply;
            free(copy);
        }
    }
    rezult = matrix_summ(matrix1, matrix2, rank_matrix);
    if(rezult == NULL){
        printf("\n\nФункция matrix_summ тест №6 провален.\nНеудалось выделить память");
        count_error++;
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    free(rezult);
    return count_error;

}

int test_matrix_multiply(){
    int count_error = 0;
    int rank_matrix = 2;
    Complex_number *matrix1, *matrix2;
    int len_matrix1 = 0, len_matrix2 = 0;

    Complex_number *rezult = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
    
    //1
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_float(i+1);
        Complex_number* copy2 = create_float(i+5);


        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = NULL;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = NULL;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(i == 0){
            if(*(float*)rezult[i].Re != 19){
                printf("\n\nФункция test_matrix_multiply тест №1 провален.\nНесоответсвие результата умножение a11");
                count_error++;
                break;
            }   
        }
        if(i == 1){
            if(*(float*)rezult[i].Re != 22){
                printf("\n\nФункция test_matrix_multiply тест №1 провален.\nНесоответсвие результата умножение a12");
                count_error++;
                break;
            }   
        }
        if(i == 2){
            if(*(float*)rezult[i].Re != 43){
                printf("\n\nФункция test_matrix_multiply тест №1 провален.\nНесоответсвие результата умножние a21");
                count_error++;
                break;
            }   
        }
        if(i == 3){
            if(*(float*)rezult[i].Re != 50){
                printf("\n\nФункция test_matrix_multiply тест №1 провален.\nНесоответсвие результата умножение a22");
                count_error++;
                break;
            }   
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    //2
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    len_matrix1 = 0;
    len_matrix2 = 0;
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_Complex(i+1, i+1);
        Complex_number* copy2 = create_Complex(i+5, i+5);


        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = (*copy1).Im;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = (*copy2).Im;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(i == 0){
            if(*(float*)rezult[i].Re != 0 || *(float*)rezult[i].Im != 38){
                printf("\n\nФункция test_matrix_multiply тест №2 провален.\nНесоответсвие результата умножение a11");
                count_error++;
                break;
            }   
        }
        if(i == 1){
            if(*(float*)rezult[i].Re != 0 || *(float*)rezult[i].Im != 44){
                printf("\n\nФункция test_matrix_multiply тест №2 провален.\nНесоответсвие результата умножение a12");
                count_error++;
                break;
            }   
        }
        if(i == 2){
            if(*(float*)rezult[i].Re != 0 || *(float*)rezult[i].Im != 86){
                printf("\n\nФункция test_matrix_multiply тест №2 провален.\nНесоответсвие результата умножние a21");
                count_error++;
                break;
            }   
        }
        if(i == 3){
            if(*(float*)rezult[i].Re != 0 || *(float*)rezult[i].Im != 100){
                printf("\n\nФункция test_matrix_multiply тест №2 провален.\nНесоответсвие результата умножение a22");
                count_error++;
                break;
            }   
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //3
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    len_matrix1 = 0;
    len_matrix2 = 0;
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_Complex(i+1, i+1);
        Complex_number* copy2 = create_Complex(i+5, i+5);


        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = (*copy1).Im;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = (*copy2).Im;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    if(rezult == NULL){
        printf("\n\nФункция test_matrix_multiply тест №3 провален.\nНеудалось выделить память");
        count_error++;
    }   
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //5
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    len_matrix1 = 0;
    len_matrix2 = 0;
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_float(i+1);
        Complex_number* copy2 = create_float(i+5);

        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = NULL;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = NULL;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    if(rezult == NULL){
        printf("\n\nФункция test_matrix_multiply тест №4 провален.\nНеудалось выделить память");
        count_error++;
    }   
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //6
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    len_matrix1 = 0;
    len_matrix2 = 0;
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_Complex(i+1, i+1);
        Complex_number* copy2 = create_Complex(i+5, i+5);


        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = (*copy1).Im;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = (*copy2).Im;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if((float*)rezult[i].Re == NULL || (float*)rezult[i].Im == NULL){
            printf("\n\nФункция test_matrix_multiply тест №6 провален.\nНеудалось выделить память");
            count_error++;
            break;
        }   
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);

    //7
    //6
    matrix1 = gen_massive();
    matrix2 = gen_massive();
    len_matrix1 = 0;
    len_matrix2 = 0;
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
    
        matrix1 = add_forward(matrix1, &len_matrix1);
        matrix2 = add_forward(matrix2, &len_matrix2);
        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_float(i+1);
        Complex_number* copy2 = create_float(i+5);


        matrix1[index].Re = (*copy1).Re;
        matrix1[index].Im = NULL;
        matrix1[index].print = (*copy1).print;
        matrix1[index].summ = (*copy1).summ;
        matrix1[index].multiply = (*copy1).multiply;
        matrix1[index].scalar_multiply = (*copy1).scalar_multiply;

        matrix2[index].Re = (*copy2).Re;
        matrix2[index].Im = NULL;
        matrix2[index].print = (*copy2).print;
        matrix2[index].summ = (*copy2).summ;
        matrix2[index].multiply = (*copy2).multiply;
        matrix2[index].scalar_multiply = (*copy2).scalar_multiply;
        free(copy1);
        free(copy2);
    }
    rezult = matrix_multiply(matrix1, matrix2, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if((float*)rezult[i].Re == NULL){
            printf("\n\nФункция test_matrix_multiply тест №7 провален.\nНеудалось выделить память");
            count_error++;
            break;
        }   
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(rezult[i].Re);
        free(rezult[i].Im);

        free(matrix1[i].Re);
        free(matrix1[i].Im);
    }
    free(matrix1);
    free(matrix2);


    
    return count_error;

}

int test_matrix_scalar_multiply(){
    int count_error = 0;
    int rank_matrix = 2, scalar = 2, len_matrix1 = 0;
    Complex_number *matrix;
    Complex_number *rezult = malloc(sizeof(Complex_number) * rank_matrix * rank_matrix);
    
    //1
    len_matrix1 = 0;
    matrix = gen_massive();
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        matrix = add_forward(matrix, &len_matrix1);

        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_float(42);
        matrix[index].Re = (*copy1).Re;
        matrix[index].Im = NULL;
        matrix[index].print = (*copy1).print;
        matrix[index].summ = (*copy1).summ;
        matrix[index].multiply = (*copy1).multiply;
        matrix[index].scalar_multiply = (*copy1).scalar_multiply;
        free(copy1);
    }
    rezult = matrix_scalar_multiply(matrix, scalar, rank_matrix);

    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if((rezult[i]).Re == NULL){
            printf("\n\nФункция matrix_scalar_multiply тест №1 провален.\nНеудалось выделить память");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(matrix[i].Re);
        free(matrix[i].Im);
    }
    free(matrix);

    //2
    len_matrix1 = 0;
    matrix = gen_massive();
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        matrix = add_forward(matrix, &len_matrix1);

        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_float(21);
        matrix[index].Re = (*copy1).Re;
        matrix[index].Im = NULL;
        matrix[index].print = (*copy1).print;
        matrix[index].summ = (*copy1).summ;
        matrix[index].multiply = (*copy1).multiply;
        matrix[index].scalar_multiply = (*copy1).scalar_multiply;
        free(copy1);
    }
    rezult = matrix_scalar_multiply(matrix, scalar, rank_matrix);

    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(*(float*)(rezult[i]).Re != 42){
            printf("\n\nФункция matrix_scalar_multiply тест №2 провален.\nНеверный результат умножения на скаляр");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(matrix[i].Re);
        free(matrix[i].Im);
    }
    free(matrix);
    
    //3
    len_matrix1 = 0;
    matrix = gen_massive();
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        matrix = add_forward(matrix, &len_matrix1);

        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_Complex(21,21);
        matrix[index].Re = (*copy1).Re;
        matrix[index].Im = (*copy1).Im;
        matrix[index].print = (*copy1).print;
        matrix[index].summ = (*copy1).summ;
        matrix[index].multiply = (*copy1).multiply;
        matrix[index].scalar_multiply = (*copy1).scalar_multiply;
        free(copy1);
    }
    rezult = matrix_scalar_multiply(matrix, scalar, rank_matrix);

    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if((*matrix).Re == NULL || (*matrix).Im == NULL){
            printf("\n\nФункция matrix_scalar_multiply тест №3 провален.\nНеудалось выделить память");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(matrix[i].Re);
        free(matrix[i].Im);
    }
    free(matrix);

    //4
    len_matrix1 = 0;
    matrix = gen_massive();
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        matrix = add_forward(matrix, &len_matrix1);

        int index = len_matrix1 - 1;
        Complex_number* copy1 = create_Complex(21, 21);
        matrix[index].Re = (*copy1).Re;
        matrix[index].Im = (*copy1).Im;
        matrix[index].print = (*copy1).print;
        matrix[index].summ = (*copy1).summ;
        matrix[index].multiply = (*copy1).multiply;
        matrix[index].scalar_multiply = (*copy1).scalar_multiply;
        free(copy1);
    }
    rezult = matrix_scalar_multiply(matrix, scalar, rank_matrix);
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        if(*(float*)(rezult[i]).Re != 42 || *(float*)(rezult[i]).Im != 42){

            printf("\n\nФункция matrix_scalar_multiply тест №4 провален.\nНеверный результат умножения на скаляр");
            count_error++;
            break;
        }
    }
    for(int i = 0; i < rank_matrix*rank_matrix; i++){
        free(matrix[i].Re);
        free(matrix[i].Im);
    }
    free(matrix);

    free(rezult);
    return count_error;
}

//--------------------------------------------------------------------------------------------------------
int test_all_func(){
    int count_error = 0;

    count_error += test_print_float();
    count_error += test_float_summ();
    count_error += test_float_multiply();
    count_error += test_float_scalar_multiply();

    count_error += test_Complex_print();
    count_error += test_Complex_summ();
    count_error += test_Complex_multiply();
    count_error += test_Complex_scalar_multiply();

    count_error += test_create_float();
    count_error += test_create_Complex();

    count_error += test_gen_massive();
    count_error += test_add_forward();

    count_error += test_matrix_summ();
    count_error += test_matrix_multiply();
    count_error += test_matrix_scalar_multiply();

    
    return count_error;
}