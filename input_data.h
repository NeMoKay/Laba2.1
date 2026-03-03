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
int question(char* question);
float input_number(float min_side, float max_side);



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