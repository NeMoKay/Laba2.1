// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     void* Re;
//     void* Im;
//     void (*print)(const void*);
//     void* (*add)(const void*, const void*);
// } ComplexNumber;

// void print_int(const void* value) {
//     printf("%d", *(int*)value);
// }

// void print_double(const void* value) {
//     printf("%.2lf", *(double*)value);
// }

// ComplexNumber create_complex(void* Re, void* Im, void (*print)(const void*)) {
//     ComplexNumber num;
//     num.Re = Re;
//     num.Im = Im;
//     num.print = print;
//     return num;
// }

// void print_complex(ComplexNumber num) {
//     printf("(");
//     num.print(num.Re);
//     printf(" + ");
//     num.print(num.Im);
//     printf("i)\n");
// }


// int main() {
//     int Re_i = 1;
//     int Im_i = 2;
//     ComplexNumber num_i = create_complex(&Re_i, &Im_i, print_int);
//     printf("int\n");
//     print_complex(num_i);
    
//     double Re_d = 1.61803398875;
//     double Im_d = 0.5772156649;
//     ComplexNumber num_d = create_complex(&Re_d, &Im_d, print_double);
//     printf("double\n");
//     print_complex(num_d);
    
//     return 0;
// }


//----------------
