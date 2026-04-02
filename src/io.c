#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#include "Matrix.h"
#include "io.h"
#include "dinamic_massive.h"

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

float input_number(float min_side, float max_side, int type_num){
    float num = 0.0;
    char char_buffer;
    if(type_num == 0){
        while(scanf("%f%c", &num, &char_buffer) != 2 || char_buffer != '\n' || (num < min_side || num > max_side)){
            printf("Oшибка! Введите число от %.2f до %.2f : ", min_side, max_side);
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
        }
        return num; 
    }
    if(type_num == 1){
        while(scanf("%f%c", &num, &char_buffer) != 2 || char_buffer != '\n' || (num < min_side || num > max_side) || (int)num % 10 > (int)max_side % 10){
            printf("Oшибка! Введите корректный индекс от %.0f до %.0f : ", min_side, max_side);
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
        }
        int i = (int)num / 10;
        int j = (int)num % 10;
        int k = (i - 1) *((int)max_side % 10) + (j - 1);
        return k;
    }
    return 1;
}

int input_data(){
    srand(time(NULL));

    const int max_rank_of_matrix = 10, epsilon_num = 100;

    int len_counter = 0, rank_matrix = 0, question_of_type, len_matrix = 0, question_of_change = 0, index = 0, qestion_stop = 0;
    char question_start[2], char_buffer;
    float scalar = 0.0;
    printf("╔════════════════════════════════════╗\n║     Матричный калькулятор 2.9      ║\n╠════════════════════════════════════╣\n║  [s] -> Сложение матриц            ║\n║  [m] -> Умножение матриц           ║\n║  [k] -> Умножение на скаляр        ║\n╚════════════════════════════════════╝");
    printf("\nВведите команду... ");
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
        question_of_change = 0;
        qestion_stop = 0;
        Matrix *matrix1, *matrix2, *result;
        printf("Введите ранг [1–%d] : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix, 0);
        question_of_type = question("Выберите тип элементов матрицы:\n[y] Вещественные числа\n[n] Комплексные числа\nВвод : ");
        printf("\n╔══════--Заполните матрицу №1--══════╗\n");

        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix1 = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
        printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Изменять значения в матрице? y/n : ");
        if(question_of_change == 1){
            if(question_of_type == 1){
                while(1){
                    float new_num_Re = 0.0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите вещесвтенное число [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    *(float*)((*matrix1).Matrix[index].type_num) = new_num_Re;
                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                } 
            }
            else{
                while(1){
                    int new_num_Re = 0, new_num_Im = 0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите целую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    printf("\nВведите мнимую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Im = input_number(-epsilon_num, epsilon_num, 0);


                    Complex_number *copy = (Complex_number*)((*matrix1).Matrix[index].type_num);
                    *((*copy).Re) = (int)new_num_Re;
                    *((*copy).Im) = (int)new_num_Im;

                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                } 
            }
            
        }
        
        printf("\n╚════════--Конец заполнения--════════╝\n");
        question_of_change = 0;
        qestion_stop = 0;
        printf("\n╔══════--Заполните матрицу №2--══════╗\n");
        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix2 = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix2).Matrix, (*matrix2).rank_of_matrix, epsilon_num);
        printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Изменять значения в матрице? y/n : ");
        if(question_of_change == 1){
            if(question_of_type == 1){
                while(1){
                    float new_num_Re = 0.0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите вещесвтенное число [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    *(float*)((*matrix2).Matrix[index].type_num) = new_num_Re;
                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix2).Matrix, (*matrix2).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                } 
            }
            else{
                while(1){
                    int new_num_Re = 0, new_num_Im = 0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите целую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    printf("\nВведите мнимую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Im = input_number(-epsilon_num, epsilon_num, 0);
                    Complex_number *copy = (Complex_number*)((*matrix2).Matrix[index].type_num);
                    *((*copy).Re) = (int)new_num_Re;
                    *((*copy).Im) = (int)new_num_Im;

                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix2).Matrix, (*matrix2).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                } 
            }
        }
        printf("\n╚════════--Конец заполнения--════════╝\n");

        if (question_start[0] == 's'){
            result = matrix_summ(matrix1, matrix2);
            draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
            printf("\n  +");
            draw_matrix(1, (*matrix2).Matrix, (*matrix2).rank_of_matrix, epsilon_num);
            printf("\n ||");
            draw_matrix(1, (*result).Matrix, (*result).rank_of_matrix, epsilon_num);
        }
        else{
            result = matrix_multiply(matrix1, matrix2);

            draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
            printf("\n  *");
    
            draw_matrix(1, (*matrix2).Matrix, (*matrix2).rank_of_matrix, epsilon_num);
            printf("\n ||");
            draw_matrix(1, (*result).Matrix, (*result).rank_of_matrix, epsilon_num);
        }
    }
    else{
        Matrix *matrix, *result;
        question_of_change = 0;
        printf("Введите ранг [1–%d] : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix, 0);
        question_of_type = question("Выберите тип элементов матрицы:\n[y] Вещественные числа\n[n] Комплексные числа\nВвод : ");
        printf("\n╔═══════--Заполните матрицу--════════╗\n");
        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
        printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Изменять значения в матрице? y/n : ");
        if (question_of_change == 1){
            if (question_of_type == 1){
                while (1){
                    float new_num_Re = 0.0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите вещесвтенное число [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    *(float*)((*matrix).Matrix[index].type_num) = new_num_Re;
                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                }
            }
            if (question_of_type == 0){
                while (1){
                    int new_num_Re = 0, new_num_Im = 0;
                    index = 0;
                    printf("\nВведите индекс матрицы : a");
                    index = input_number(11, rank_matrix * 11, 1);
                    printf("\nВведите целую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Re = input_number(-epsilon_num, epsilon_num, 0);
                    printf("\nВведите мнимую часть комлексного числа [%d ; %d]: ", -epsilon_num, epsilon_num);
                    new_num_Im = input_number(-epsilon_num, epsilon_num, 0);
                    Complex_number *copy = (Complex_number*)((*matrix).Matrix[index].type_num);
                    *((*copy).Re) = (int)new_num_Re;
                    *((*copy).Im) = (int)new_num_Im;

                    printf("\nИзмененная матрица :");
                    draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
                    qestion_stop = question("\nОстановить изменение матрицы? y/n : ");
                    if (qestion_stop == 1){
                        break;
                    }
                }
            }


        }
        question_of_change = 0;
        int question_of_type_scalar = 0;
        int Re_scalar = 0, Im_scalar = 0;
        question_of_type_scalar = question("Введите < y > если скаляр вещественный или < n > если комплексный : ");
        if (question_of_type_scalar == 1){
            printf("\nВведите скаляр на который умножить матрицу : ");
            scalar = input_number(-100, 100, 0);
        }
        if (question_of_type_scalar == 0){
            printf("Введите целую часть скаляра : ");
            Re_scalar = input_number(-epsilon_num, epsilon_num, 0);
            printf("Введите мнимую часть скаляра : ");
            Im_scalar = input_number(-epsilon_num, epsilon_num, 0);
        }
        void* scalar_data_to_pass;
        if (question_of_type_scalar == 1){
            float* temp_float = malloc(sizeof(float));
            if (temp_float == NULL){
                printf("Ошибка выделения памяти для скаляра\n");
                return 1;
            }
            *temp_float = scalar;
            scalar_data_to_pass = temp_float;
        }
        if (question_of_type_scalar == 0){

            Complex_number* number_complex = malloc(sizeof(Complex_number));
            if (number_complex == NULL){
                printf("Ошибка выделения памяти для скаляра\n");
                return 1;
            }
            (*number_complex).Re = malloc(sizeof(int));
            (*number_complex).Im = malloc(sizeof(int));
            if ((*number_complex).Re == NULL || (*number_complex).Im == NULL){
                printf("Ошибка выделения памяти для скаляра\n");
                free((*number_complex).Re);
                free((*number_complex).Im);
                free(number_complex);
                return 1;
            }
            *((*number_complex).Re) = Re_scalar;
            *((*number_complex).Im) = Im_scalar;
            scalar_data_to_pass = number_complex;
        }
        printf("\n╚════════--Конец заполнения--════════╝\n");
        draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
        if (question_of_type_scalar == 1){
            printf("\n  *\n\n  %.2f\n\n  ||", scalar);
        }
        
        if (question_of_type_scalar == 0){
            printf("\n  *\n\n  %d + %di\n\n  ||", Re_scalar, Im_scalar);
        }
        result = matrix_scalar_multiply(matrix, scalar_data_to_pass, question_of_type_scalar);
        draw_matrix(1, (*result).Matrix, (*result).rank_of_matrix, epsilon_num);

        if (question_of_type_scalar == 1){
            free(scalar_data_to_pass);
        }
        if (question_of_type_scalar == 0){
            Complex_number* temp_c_ptr = (Complex_number*)scalar_data_to_pass;
            free((*temp_c_ptr).Re);
            free((*temp_c_ptr).Im);
            free(temp_c_ptr);
        }
        
        return 0;
    }
    return 0;
}