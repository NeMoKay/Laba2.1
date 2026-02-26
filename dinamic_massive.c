
#include "input_data.h"
#include <stdio.h>
#include <stdlib.h>

Complex_number *gen_massive(){
    Complex_number *first = malloc(sizeof(Complex_number));

    if (first == NULL){
        return NULL;
    }
    return first;
}

Complex_number *add_forward(Complex_number *first_address, int *len_massive){
    Complex_number *debug;
    debug = realloc(first_address, (*len_massive+1) * sizeof(Complex_number));
    if(debug == NULL){
        return NULL;
    }
    int new_index = *len_massive;

    (*(debug + new_index)).Re = malloc(sizeof(float));
    debug[new_index].Im = malloc(sizeof(float));

    if(debug[new_index].Re == NULL){
        return NULL;
    }
    if(debug[new_index].Im == NULL){
        return NULL;    
    }
    (*len_massive)++;
    return debug;
}