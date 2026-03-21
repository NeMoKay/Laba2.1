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
        while(scanf("%f", &num) != 1 || (num < min_side || num > max_side)){
            printf("Oшибка! Введите число от %.2f до %.2f : ", min_side, max_side);
            while ((char_buffer = getchar()) != '\n' && char_buffer != EOF);
        }
        return num;
    }
    if(type_num == 1){
        while(scanf("%f", &num) != 1 || (num < min_side || num > max_side) || (int)num % 10 > (int)max_side % 10){
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

    int len_counter = 0, rank_matrix = 0, question_of_type, len_matrix = 0, question_of_change = 0;
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
        question_of_change = 0;
        Matrix *matrix1, *matrix2, *result;
        printf("Для начала введите общий ранг матриц от 1 до %d : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix, 0);

        question_of_type = question("Введите < y > если вводить вещественные числа в матрицу или < n > если вводить комплексные : ");
        printf("\n--Заполните матрицу №1--\n");
        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix1 = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
        printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Введите < y > если хотите изменить числа в матрице или < n > если нет : ");
        if(question_of_type == 1){
            int index = 0;
            printf("\nВведите индекс матрицы : a");
            index = input_number(11, rank_matrix * 11, 1);
            printf("\nИзмненение значения элемента по индексу а%d :", index);
            
              
            
        }

        question_of_change = 0;
        printf("\n--Заполните матрицу №2--\n");
        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix2 = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix1).Matrix, (*matrix1).rank_of_matrix, epsilon_num);
        printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Введите < y > если хотите изменить числа в матрице или < n > если нет : ");
        if(question_of_type == 1){
            
        }
        question_of_change = 0;

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
        printf("Для начала введите ранг матрицы от 1 до %d : ", max_rank_of_matrix);
        rank_matrix = input_number(1, max_rank_of_matrix, 0);
        question_of_type = question("Введите < y > если вводить вещественные числа в матрицу или < n > если вводить комплексные : ");
        printf("\n--Заполните матрицу--\n");
        draw_matrix(0, NULL, rank_matrix, epsilon_num);
        matrix = create_matrix(rank_matrix, epsilon_num, question_of_type);
        draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
         printf("\nЖелаете изменить матрицу?\n");
        question_of_change = question("Введите < y > если хотите изменить числа в матрице или < n > если нет : ");
        if(question_of_type == 1){
            
        }
        question_of_change = 0;
        printf("\nВведите скаляр на который умножить матрицу : ");
        scalar = input_number(-100,100, 0);
        draw_matrix(1, (*matrix).Matrix, (*matrix).rank_of_matrix, epsilon_num);
        printf("\n  *\n\n  %.2f\n\n  ||", scalar);
        result = matrix_scalar_multiply(matrix, scalar);
        draw_matrix(1, (*result).Matrix, (*result).rank_of_matrix, epsilon_num);
    }
    return 0;
}