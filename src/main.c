#include <stdio.h>
#include "io.h"


int main(){
    int memorry_checker = 0, test_chacker = 0;
    
    memorry_checker = input_data();
    if(memorry_checker == 0){
        printf("\nПрограмма выполненна без проблем");
    }
    else{
        printf("\nОшибка памяти");
    }
    return 0;
    
}