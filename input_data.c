#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "input_data.h"
#include "dinamic_massive.h"

char* float_print(const void* Stuct_Re1, int epsilon_num){
    const Complex_number *number = (const Complex_number*)Stuct_Re1;
    float num = *(const float*)(*number).Re;
    int int_num = (int)num, len_epsilon = 0, len_num = 0, epsilon = epsilon_num, start_i = 0;

    while(epsilon / 10 != 0){
        epsilon = epsilon / 10;
        len_epsilon++;
        if(int_num / 10 != 0){
            int_num = int_num / 10;
            len_num++;
        }
    }
    char *p_string = malloc(len_epsilon + 4);
    if (p_string == NULL) {
        return NULL;
    }

    for(int i = 0; i < len_epsilon - len_num; i++){
        p_string[i] = ' ';
        start_i++;
    }
    if(num < 0){
        sprintf(p_string + start_i, "%.2f", num);
    }
    else{
        sprintf(p_string + start_i, " %.2f", num);
    }
    return p_string;
}
 
void* float_summ(const void* Stuct_Re1, const void* Stuct_Re2){
    
    Complex_number *rezult = malloc(sizeof(Complex_number));
    const Complex_number *number1 = (const Complex_number*)Stuct_Re1;
    const Complex_number *number2 = (const Complex_number*)Stuct_Re2;

    (*rezult).Re = malloc(sizeof(float));
    (*rezult).Im = NULL;
    *(float*)(*rezult).Re = *(const float*)(*number1).Re + *(const float*)(*number2).Re;
    return rezult;
}

void* float_multiply(const void* Stuct_Re1, const void* Stuct_Re2){
    Complex_number *rezult = malloc(sizeof(Complex_number));
    const Complex_number *number1 = (const Complex_number*)Stuct_Re1;
    const Complex_number *number2 = (const Complex_number*)Stuct_Re2;

    (*rezult).Re = malloc(sizeof(float));
    (*rezult).Im = NULL;

    *(float*)(*rezult).Re = *(const float*)(*number1).Re * *(const float*)(*number2).Re;
    return rezult;
}

void float_scalar_multiply(float scalar, void* Struct_Re1){

    Complex_number* number = (Complex_number*)Struct_Re1;
    *(float*)(*number).Re = scalar * (*(float*)(*number).Re);

}

char* Complex_print(const void* Comlex1, int epsilon_num){
    const Complex_number* number = (const Complex_number*)Comlex1;
    float num_Re = *(const float*)(*number).Re;
    float num_Im = *(const float*)(*number).Im;

    int int_num_Re = (int)num_Re, int_num_Im = (int)num_Im;
    int len_epsilon_Re = 0, len_num_Re = 0;
    int len_epsilon_Im = 0, len_num_Im = 0;
    int epsilon_Re = epsilon_num, epsilon_Im = epsilon_num;

    while(epsilon_Re / 10 != 0){
        epsilon_Re /= 10;
        len_epsilon_Re++;
        if (int_num_Re / 10 != 0){
            int_num_Re = int_num_Re / 10;
            len_num_Re++;
        }
    }
    while(epsilon_Im / 10 != 0){
        epsilon_Im /= 10;
        len_epsilon_Im++;
        if (int_num_Im / 10 != 0){
            int_num_Im = int_num_Im / 10;
            len_num_Im++;
        }
    }
    char *p_string = malloc(len_epsilon_Re + 9 + len_epsilon_Im);
    if(p_string == NULL){
        return NULL;
    }
    int index = 0;
    for(int i = 0; i < len_epsilon_Re - len_num_Re; i++){
        p_string[index++] = ' ';
    }

    if(num_Re < 0){
        index += sprintf(p_string + index, "%.2f", num_Re);
    }
    else{
        index += sprintf(p_string + index, " %.2f", num_Re);
    }
    if(num_Im < 0){
        index += sprintf(p_string + index, "%.2fi", num_Im);
    }
    else{
        index += sprintf(p_string + index, "+%.2fi", num_Im);
    }
    for(int i = 0; i < len_epsilon_Im - len_num_Im; i++){
        p_string[index++] = ' ';
    }
    p_string[index] = '\0';
    return p_string;
}

void* Complex_summ(const void* Comlex1, const void* Comlex2){
        
    Complex_number *number1 = (Complex_number*)Comlex1;
    Complex_number *number2 = (Complex_number*)Comlex2;
    Complex_number *rezult = malloc(sizeof(Complex_number));

    (*rezult).Re = malloc(sizeof(float));
    (*rezult).Im = malloc(sizeof(float));

    *(float*)(*rezult).Re = *(const float*)(*number1).Re + *(const float*)(*number2).Re;
    *(float*)(*rezult).Im = *(const float*)(*number1).Im + *(const float*)(*number2).Im;
    return rezult;
}

void* Complex_multiply(const void* Comlex1, const void* Comlex2){   

    Complex_number *rezult = malloc(sizeof(Complex_number));
    Complex_number *number1 = (Complex_number*)Comlex1;
    Complex_number *number2 = (Complex_number*)Comlex2;

    (*rezult).Re = malloc(sizeof(float));
    (*rezult).Im = malloc(sizeof(float));

    *(float*)(*rezult).Re = *(const float*)(*number1).Re * *(const float*)(*number2).Re - *(const float*)(*number1).Im * *(const float*)(*number2).Im;

    *(float*)(*rezult).Im = *(const float*)(*number1).Re * *(const float*)(*number2).Im + *(const float*)(*number1).Im * *(const float*)(*number2).Re;
    
    return rezult;
}

void Complex_scalar_multiply(float scalar, void* Struct){
    Complex_number* number = (Complex_number*)Struct;
    *(float*)(*number).Re = scalar * (*(float*)(*number).Re);
    *(float*)(*number).Im = scalar * (*(float*)(*number).Im);
}

Complex_number* create_float(float Real){
    Complex_number *Struct_for_num = malloc(sizeof(Complex_number));
    (*Struct_for_num).Re = malloc(sizeof(float));
    (*Struct_for_num).Im = NULL;
    *(float*)(*Struct_for_num).Re = Real;

    (*Struct_for_num).print = float_print;
    (*Struct_for_num).summ = float_summ;
    (*Struct_for_num).multiply = float_multiply;
    (*Struct_for_num).scalar_multiply = float_scalar_multiply;
    
    return Struct_for_num;
}

Complex_number* create_Complex(float Real, float Imag){
    Complex_number* Struct_for_complex = malloc(sizeof(Complex_number));
    (*Struct_for_complex).Re = malloc(sizeof(float));
    (*Struct_for_complex).Im = malloc(sizeof(float));

    *(float*)(*Struct_for_complex).Re = Real;
    *(float*)(*Struct_for_complex).Im = Imag;

    (*Struct_for_complex).print = Complex_print;
    (*Struct_for_complex).summ = Complex_summ;
    (*Struct_for_complex).multiply = Complex_multiply;
     (*Struct_for_complex).scalar_multiply = Complex_scalar_multiply;
     
    return Struct_for_complex;
}

//------------------------------------------------

int question(char* question){

    printf("\n%s", question);
    char main_answer[2], char_buffer;
    int len_counter;
    while (1){
        len_counter = 0;
        if (scanf(" %1[yn]", main_answer) == 1){
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF){
                len_counter++;
            }
            if (len_counter == 0){
                break;
            }
            else{
                printf("\nВведенна неверная команда \nВвведите < y > или < n > : ");
            }
        }
        else{
            printf("\nВведенна неверная команда \nВвведите < y > или < n > : ");
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
        }
    }
    if (main_answer[0] == 'y'){
        return 1;
    }
    else{
        return 0;
    }
}

void draw_matrix(int tipe_matrix, Complex_number* matrix, int rank_matrix, int epsilon_num){
    char *result_print;
    if(tipe_matrix == 0){
        printf("\nШаблон заполнения матрицы : \n\n| ");
        for(int i = 0; i < rank_matrix; i++){
            for(int k = 0; k < rank_matrix; k++){
                printf("a%d%d ", i+1, k+1);
            }
            printf("|");
        }   
    }
    else{
        printf("\n");
        for (int i = 0; i < rank_matrix; i++) {
            printf("\n|");
            for(int k = 0; k < rank_matrix; k++){
                int index = i * rank_matrix + k;
                result_print = matrix[index].print(&matrix[index], epsilon_num);
                printf("%s ", result_print);
            }
            printf("|");
        }
    }
    printf("\n");
}

float input_number(float min_side, float max_side){
    float num = 0.0;
    char char_buffer;
    while(scanf("%f", &num) != 1 || (num < min_side || num > max_side)){
        printf("Oшибка! Введите число от %.5g до %.5g : ", min_side, max_side);
        while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
    }
    num = ((int)(num*1000)) / 1000.0;
    return num;
}

//------------------------------------------------

Complex_number* create_matrix(int rank_matrix, int epsilon_num, int question_of_type){  
    
    int question_of_random;
    int len_matrix = 0;
    Complex_number *matrix = gen_massive();

    question_of_random = question("Введите < y > если заполнить матрицу рандомом или < n > если вводить вручную : ");

    if(question_of_random == 0){
        if(question_of_type == 0){
            float Re, Im;
            for(int i = 0; i < rank_matrix; i++){
                for(int k = 0; k < rank_matrix; k++){
                    printf("\nВведите a%d%d (Re): ", i+1, k+1);
                    Re = input_number(-1 * epsilon_num, epsilon_num);
                    printf("Введите a%d%d (Im): ", i+1, k+1);
                    Im = input_number(-1 * epsilon_num, epsilon_num);

                    matrix = add_forward(matrix, &len_matrix);
                    int index = len_matrix - 1;

                    Complex_number* copy = create_Complex(Re, Im);
                    matrix[index].Re = (*copy).Re;
                    matrix[index].Im = (*copy).Im;
                    matrix[index].print = (*copy).print;
                    matrix[index].summ = (*copy).summ;
                    matrix[index].multiply = (*copy).multiply;
                    matrix[index].scalar_multiply = (*copy).scalar_multiply;
                    free(copy);
                }
            }
        }
        else{
            float Re;
            for(int i = 0; i < rank_matrix; i++){
                for(int k = 0; k < rank_matrix; k++){

                    printf("\nВведите a%d%d : ", i+1, k+1);
                    Re = input_number(-epsilon_num, epsilon_num);

                    matrix = add_forward(matrix, &len_matrix);
                    int index = len_matrix - 1;
                    Complex_number* copy = create_float(Re);
                    matrix[index].Re = (*copy).Re;
                    matrix[index].Im = NULL;
                    matrix[index].print = (*copy).print;
                    matrix[index].summ = (*copy).summ;
                    matrix[index].multiply = (*copy).multiply;
                    matrix[index].scalar_multiply = (*copy).scalar_multiply;
                    free(copy);
                }
            }
        }
    }
    else{
        if(question_of_type == 0){
            float Re, Im;
            for(int i = 0; i < rank_matrix; i++){
                for(int k = 0; k < rank_matrix; k++){

                    Re = (rand() % (2 * epsilon_num + 1)) - epsilon_num;
                    Im = (rand() % (2 * epsilon_num + 1)) - epsilon_num;

                    matrix = add_forward(matrix, &len_matrix);
                    int index = len_matrix - 1;
                    Complex_number* copy = create_Complex(Re, Im);
                    matrix[index].Re = (*copy).Re;
                    matrix[index].Im = (*copy).Im;
                    matrix[index].print = (*copy).print;
                    matrix[index].summ = (*copy).summ;
                    matrix[index].multiply = (*copy).multiply;
                    matrix[index].scalar_multiply = (*copy).scalar_multiply;
                    free(copy);
                }
            }
        }
        else{
            float Re;
            for(int i = 0; i < rank_matrix; i++){
                for(int k = 0; k < rank_matrix; k++){
                    Re = (rand() % (2 * epsilon_num + 1)) - epsilon_num;
                    matrix = add_forward(matrix, &len_matrix);

                    int index = len_matrix - 1;

                    Complex_number* copy = create_float(Re);
                    matrix[index].Re = (*copy).Re;
                    matrix[index].Im = NULL;
                    matrix[index].print = (*copy).print;
                    matrix[index].summ = (*copy).summ;
                    matrix[index].multiply = (*copy).multiply;
                    matrix[index].scalar_multiply = (*copy).scalar_multiply;
                    free(copy);
                }
            }
        }
    }
    return matrix;
}

Complex_number* matrix_summ(Complex_number* matrix1, Complex_number* matrix2, int rank_matrix){
    Complex_number *result = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
    if(result == NULL){
        return NULL;
    }
    for (int i = 0; i < rank_matrix * rank_matrix; i++){
        Complex_number *copy = matrix1[i].summ(&matrix1[i], &matrix2[i]);

        result[i].Re = malloc(sizeof(float));
        if(result[i].Re == NULL){
            return NULL;
        }
        *(float*)result[i].Re = *(float*)(*copy).Re;

        if((*copy).Im != NULL){
            result[i].Im = malloc(sizeof(float));
            if(result[i].Im == NULL){
                return NULL;
            }
            *(float*)result[i].Im = *(float*)(*copy).Im;
        } 
        else{
            result[i].Im = NULL;
        }
        result[i].print = matrix1[i].print;
        result[i].summ = matrix1[i].summ;
        result[i].multiply = matrix1[i].multiply;
        result[i].scalar_multiply = matrix1[i].scalar_multiply;

        if ((*copy).Im != NULL){
            free((*copy).Im);
        }
        free((*copy).Re);
        free(copy);
    }
    return result;
}

Complex_number* matrix_multiply(Complex_number* matrix1, Complex_number* matrix2, int rank_matrix){
    Complex_number *result = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
    if(result == NULL){
        return NULL;
    }
    for(int i = 0; i < rank_matrix; i++){
        for(int j = 0; j < rank_matrix; j++){
            int index = i * rank_matrix + j;

            int k = 0;
            int indexA = i * rank_matrix + k;
            int indexB = k * rank_matrix + j;
            Complex_number *copy = matrix1[indexA].multiply(matrix1 + indexA, &matrix2[indexB]);

            result[index].Re = malloc(sizeof(float));
            if(result[index].Re == NULL){
                return NULL;
            }
            *(float*)result[index].Re = *(float*)(*copy).Re;

            if((*copy).Im != NULL){
                result[index].Im = malloc(sizeof(float));
                if(result[index].Im == NULL){
                    return NULL;
                }
                *(float*)result[index].Im = *(float*)(*copy).Im;
            }
            else{
                result[index].Im = NULL;
            }

            result[index].print = matrix1[indexA].print;
            result[index].summ = matrix1[indexA].summ;
            result[index].multiply = matrix1[indexA].multiply;
            result[index].scalar_multiply = matrix1[indexA].scalar_multiply;

            if((*copy).Im != NULL){
                free((*copy).Im);
            }
            free((*copy).Re);
            free(copy);
            for(k = 1; k < rank_matrix; k++){
                indexA = i * rank_matrix + k;
                indexB = k * rank_matrix + j;
                copy = matrix1[indexA].multiply(&matrix1[indexA], &matrix2[indexB]);

                Complex_number *sum = result[index].summ(&result[index], copy);

                if(result[index].Im != NULL){
                    free(result[index].Im);
                }
                free(result[index].Re);

                result[index].Re = malloc(sizeof(float));
                if(result[index].Re == NULL){
                    return NULL;
                }
                *(float*)result[index].Re = *(float*)(*sum).Re;

                if((*sum).Im != NULL){
                    result[index].Im = malloc(sizeof(float));
                    if(result[index].Im == NULL){
                        return NULL;
                    }
                    *(float*)result[index].Im = *(float*)(*sum).Im;
                }
                else{
                    result[index].Im = NULL;
                }

                if((*sum).Im != NULL){
                    free((*sum).Im);
                }
                free((*sum).Re);
                free(sum);
                
                if((*copy).Im != NULL){
                    free((*copy).Im);
                }
                free((*copy).Re);
                free(copy);
            }
        }
    }
    return result;
}

Complex_number* matrix_scalar_multiply(Complex_number* matrix, float scalar, int rank_matrix){
    Complex_number *result = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
    if(result == NULL){
        return NULL;
    }
    for(int i = 0; i < rank_matrix * rank_matrix; i++){
        result[i].Re = malloc(sizeof(float));
        if(result[i].Re == NULL){
            return NULL;
        }
        *(float*)result[i].Re = *(float*)matrix[i].Re * scalar;
        
        if(matrix[i].Im != NULL){
            result[i].Im = malloc(sizeof(float));
            if(result[i].Im == NULL){
                return NULL;
            }
            *(float*)result[i].Im = *(float*)matrix[i].Im * scalar;
        }
        else{
            result[i].Im = NULL;
        }
        
        result[i].print = matrix[i].print;
        result[i].summ = matrix[i].summ;
        result[i].multiply = matrix[i].multiply;
        result[i].scalar_multiply = matrix[i].scalar_multiply;
    }
    return result;
}

//------------------------------------------------

int input_data(){
    srand(time(NULL));

    const int max_rank_of_matrix = 10, epsilon_num = 100;

    int len_counter = 0, rank_matrix = 0, question_of_type, len_matrix = 0;
    char question_start[2], char_buffer;
    float scalar = 0.0;

    printf("\nПривет! Здесь представленн алгоритм работы : \n< s > Матричного сложения\n< m > Матричного умножения\n< k > Умножения матрицы на скаляр\nВведите s или m или k : ");
    while (1){
        len_counter = 0;

        if (scanf(" %1[smk]", question_start) == 1){
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF){
                len_counter++;
            }
            if (len_counter == 0){
                break;
            }
            else{
                printf("\nВведенна неверная команда \nВведите s или m или k : ");
            }
        }
        else{
            printf("\nВведенна неверная команда \nВведите s или m или k : ");
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
        }
    }

    if(question_start[0] != 'k'){

        Complex_number *matrix1, *matrix2, *result;
        printf("Для начала введите общий ранг матриц от 1 до %d : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix);
        result = malloc(rank_matrix * rank_matrix * sizeof(Complex_number));
        if(result == NULL){
            return 1;
        }

        question_of_type = question("Введите < y > если вводить вещественные числа в матрицу или < n > если вводить комплексные : ");
        printf("\n--Заполните матрицу №1--\n");
        draw_matrix(0, 0, rank_matrix, epsilon_num);
        matrix1 = create_matrix(rank_matrix, epsilon_num, question_of_type);
        printf("\n--Заполните матрицу №2--\n");
        matrix2 = create_matrix(rank_matrix, epsilon_num, question_of_type);

        if (question_start[0] == 's'){

            result = matrix_summ(matrix1, matrix2, rank_matrix);
            draw_matrix(1, matrix1, rank_matrix, epsilon_num);
            printf("\n  +");
            draw_matrix(1, matrix2, rank_matrix, epsilon_num);
            printf("\n ||");
            draw_matrix(1, result, rank_matrix, epsilon_num);

        }

        else{
            result = matrix_multiply(matrix1, matrix2, rank_matrix);
            draw_matrix(1, matrix1, rank_matrix, epsilon_num);
            printf("\n  *");
            draw_matrix(1, matrix2, rank_matrix, epsilon_num);
            printf("\n ||");
            draw_matrix(1, result, rank_matrix, epsilon_num);
        }
    } 
    else{
        Complex_number* matrix, *result;
        printf("Для начала введите ранг матрицы от 1 до %d : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix);
        question_of_type = question("Введите < y > если вводить вещественные числа в матрицу или < n > если вводить комплексные : ");
        printf("\n--Заполните матрицу--\n");
        draw_matrix(0, 0, rank_matrix, epsilon_num);
        matrix = create_matrix(rank_matrix, epsilon_num, question_of_type);
        printf("\nВведите скаляр на который умножить матрицу : ");
        scalar = input_number(-100,100);
        draw_matrix(1, matrix, rank_matrix, epsilon_num);
        printf("\n  *\n\n  %.2f\n\n  ||", scalar);

        result = matrix_scalar_multiply(matrix, scalar, rank_matrix);
        draw_matrix(1, result, rank_matrix, epsilon_num);
    }
    return 0;
}