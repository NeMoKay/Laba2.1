#include <stdio.h>
#include "input_data.h"
#include "test.h"


int main(){
    int memorry_checker = 0, test_chacker = 0;
    
    memorry_checker = input_data();
    if(memorry_checker == 0){
        printf("\nПрограмма выполненна без проблем");
    }
    else{
        printf("\nОшибка памяти");
    }

    
    // test_chacker = test_all_func();
    //  if(test_chacker == 0){
    //     printf("\nВсе функции программы работают идеально");
    // }
    // else{
    //     printf("\nОшибка функции");
    // }

    
    
}