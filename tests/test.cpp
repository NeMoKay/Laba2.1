#include <gtest/gtest.h>
#include <cstdlib>
#include <cstring>

extern "C"{
#include "Matrix.h"
#include "io.h"
#include "dinamic_massive.h"
}

static void clear_matrix(Matrix* matrix_1){
    if (matrix_1 == nullptr){
        return;
    }
    number* address = (*matrix_1).Matrix;
    int len = (*matrix_1).len_matrix;
    for (int i = 0; i < len; ++i){
        TypeInfo* info = address[i].type_info;
        if (info == &float_typeinfo){
            free(address[i].type_num);
        }
        if (info == &complex_typeinfo){
            Complex_number* complex_elem = (Complex_number*)address[i].type_num;
            free((*complex_elem).Re);
            free((*complex_elem).Im);
            free(complex_elem);
        }
    }
    free(address);
    free(matrix_1);
}

TEST(float_print_test, value){
    int eps = 100;
    float val;
    char* str_res;

    //1
    val = 42.42;
    str_res = float_print(&val, eps);
    EXPECT_STREQ("  42.42", str_res);
    free(str_res);

    //2
    val = -42.42;
    str_res = float_print(&val, eps);
    EXPECT_STREQ(" -42.42", str_res);
    free(str_res);

    //3
    val = 2.42;
    str_res = float_print(&val, eps);
    EXPECT_STREQ("   2.42", str_res);
    free(str_res);

    //4
    val = -2.42;
    str_res = float_print(&val, eps);
    EXPECT_STREQ("  -2.42", str_res);
    free(str_res);
}

TEST(float_summ_test, value){

    //1
    float a = 20.0, b = 22.0;
    void* res = float_summ(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    EXPECT_EQ(*(float*)res, 42.0);
    free(res);

    //2
    a = 82.0; b = -40.0;
    res = float_summ(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    EXPECT_EQ(*(float*)res, 42.0);
    free(res);
}

TEST(float_multiply_test, value){

    //1
    float a = 21.0, b = 2.0;
    void* res = float_multiply(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    float result = *(float*)res;
    EXPECT_EQ(result, 42.0);
    free(res);

    //2
    a = 1.0; b = -42.0;
    res = float_multiply(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    result = *(float*)res;
    EXPECT_EQ(result, -42.0);
    free(res);
}

TEST(float_scalar_multiply_test, value){

    //1
    float scalar = 2.0;
    float data = 21.0;
    float_scalar_multiply(&scalar, &data, 1);
    EXPECT_EQ(data, 42.0);

    //2
    scalar = -1.0;
    data = -42.0;
    float_scalar_multiply(&scalar, &data, 1);
    EXPECT_EQ(data, 42.0);
}

TEST(complex_print_test, value){
    int eps = 100;
    Complex_number complex_elem;
    int Re, Im;
    char* str;

    //1
    Re = 42; Im = 42;
    complex_elem.Re = &Re; complex_elem.Im = &Im;
    str = Complex_print(&complex_elem, eps);
    EXPECT_STREQ("  42+42i ", str);
    free(str);

    //2
    Re = -42; Im = -42;
    complex_elem.Re = &Re; complex_elem.Im = &Im;
    str = Complex_print(&complex_elem, eps);
    EXPECT_STREQ(" -42-42i ", str);
    free(str);

    //3
    Re = 2; Im = 2;
    complex_elem.Re = &Re; complex_elem.Im = &Im;
    str = Complex_print(&complex_elem, eps);
    EXPECT_STREQ("   2+2i  ", str);
    free(str);

    //4
    Re = -2; Im = -2;
    complex_elem.Re = &Re; complex_elem.Im = &Im;
    str = Complex_print(&complex_elem, eps);
    EXPECT_STREQ("  -2-2i  ", str);
    free(str);
}

TEST(complex_summ_test, value){

    //1
    Complex_number a, b;
    int a_re = 21, a_im = 21;
    int b_re = 21, b_im = 21;
    a.Re = &a_re; a.Im = &a_im;
    b.Re = &b_re; b.Im = &b_im;
    void* res = Complex_summ(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    Complex_number* result = (Complex_number*)res;
    EXPECT_EQ(*(*result).Re, 42);
    EXPECT_EQ(*(*result).Im, 42);
    free((*result).Re);
    free((*result).Im);
    free(result);

    //2
    a_re = 43; a_im = 43;
    b_re = -1; b_im = -1;
    a.Re = &a_re; a.Im = &a_im;
    b.Re = &b_re; b.Im = &b_im;

    res = Complex_summ(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    result = (Complex_number*)res;
    EXPECT_EQ(*(*result).Re, 42);
    EXPECT_EQ(*(*result).Im, 42);
    free((*result).Re);
    free((*result).Im);
    free(result);
}

TEST(complex_multiply_test, value){

    //1
    Complex_number a, b;
    int a_re = 0, a_im = -7;
    int b_re = -6, b_im = 6;
    a.Re = &a_re; a.Im = &a_im;
    b.Re = &b_re; b.Im = &b_im;

    void* res = Complex_multiply(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    Complex_number* result = (Complex_number*)res;
    EXPECT_EQ(*(*result).Re, 42);
    EXPECT_EQ(*(*result).Im, 42);
    free((*result).Re);
    free((*result).Im);
    free(result);

    //2
    a_re = 7; a_im = 0;
    b_re = -6; b_im = -6;
    a.Re = &a_re; a.Im = &a_im;
    b.Re = &b_re; b.Im = &b_im;

    res = Complex_multiply(&a, &b);
    if (res == nullptr){
        EXPECT_TRUE(false);
    }
    result = (Complex_number*)res;
    EXPECT_EQ(*(*result).Re, -42);
    EXPECT_EQ(*(*result).Im, -42);
    free((*result).Re);
    free((*result).Im);
    free(result);
}

TEST(complex_scalar_multiply_test, value){

    //1
    float scalar_float = 2.0;
    Complex_number data;
    int data_re = 21, data_im = 21;
    data.Re = &data_re; data.Im = &data_im;
    Complex_scalar_multiply(&scalar_float, &data, 1);
    EXPECT_EQ(*(data.Re), 42);
    EXPECT_EQ(*(data.Im), 42);

    //2
    Complex_number scalar_complex;
    int scalar_re = 1, scalar_im = 1;
    scalar_complex.Re = &scalar_re; scalar_complex.Im = &scalar_im;
    data_re = 21; data_im = 21;
    data.Re = &data_re; data.Im = &data_im;
    Complex_scalar_multiply(&scalar_complex, &data, 0);

    EXPECT_EQ(*(data.Re), 0);
    EXPECT_EQ(*(data.Im), 42);
}

TEST(create_float_test, value){

    //1
    number* num = create_float(42.0);
    if (num == nullptr){
        EXPECT_TRUE(false);
    }
    float* f = (float*)((*num).type_num);
    EXPECT_EQ(*f, 42.0);
    free(f);
    free(num);
}

TEST(create_complex_test, value){
    //1
    number* num = create_Complex(42, 42);
    if (num == nullptr){
        EXPECT_TRUE(false);
    }
    Complex_number* complex_elem = (Complex_number*)((*num).type_num);
    EXPECT_EQ(*(*complex_elem).Re, 42);
    EXPECT_EQ(*(*complex_elem).Im, 42);
    free((*complex_elem).Re);
    free((*complex_elem).Im);
    free(complex_elem);
    free(num);
}

TEST(matrix_summ_test, value){
    int rank = 2;
    int len = rank * rank;

    Matrix* matrix_1 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_1).rank_of_matrix = rank;
    (*matrix_1).len_matrix = len;
    (*matrix_1).Matrix = (number*)malloc(len * sizeof(number));
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 1.0;
        }
        if (i == 1){
            val = 2.0;
        }
        if (i == 2){
            val = 3.0;
        }
        if (i == 3){
            val = 4.0;
        }
        number* num = create_float(val);
        (*matrix_1).Matrix[i] = *num;
        free(num);
    }
    (*matrix_1).typeinfo = &float_address_typeinfo;

    Matrix* matrix_2 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_2).rank_of_matrix = rank;
    (*matrix_2).len_matrix = len;
    (*matrix_2).Matrix = (number*)malloc(len * sizeof(number));
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 5.0;
        }
        if (i == 1){
            val = 6.0;
        }
        if (i == 2){
            val = 7.0;
        }
        if (i == 3){
            val = 8.0;
        }
        number* num = create_float(val);
        (*matrix_2).Matrix[i] = *num;
        free(num);
    }
    (*matrix_2).typeinfo = &float_address_typeinfo;

    //1
    Matrix* sum = matrix_summ(matrix_1, matrix_2);
    if (sum == nullptr){
        EXPECT_TRUE(false);
    }
    EXPECT_EQ((*sum).rank_of_matrix, rank);

    //2 3 4 5
    number* address = (*sum).Matrix;
    for (int i = 0; i < len; ++i){
        float expected;
        if (i == 0){
            expected = 6.0;
        }
        if (i == 1){
            expected = 8.0;
        }
        if (i == 2){
            expected = 10.0;
        }
        if (i == 3){
            expected = 12.0;
        }
        float val = *(float*)address[i].type_num;
        EXPECT_EQ(val, expected);
    }

    clear_matrix(sum);
    clear_matrix(matrix_1);
    clear_matrix(matrix_2);
}

TEST(matrix_multiply_test, value){
    int rank = 2;
    int len = rank * rank;

    Matrix* matrix_1 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_1).rank_of_matrix = rank;
    (*matrix_1).len_matrix = len;
    (*matrix_1).Matrix = (number*)malloc(len * sizeof(number));
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 1.0;
        }
        if (i == 1){
            val = 2.0;
        }
        if (i == 2){
            val = 3.0;
        }
        if (i == 3){
            val = 4.0;
        }
        number* num = create_float(val);
        (*matrix_1).Matrix[i] = *num;
        free(num);
    }
    (*matrix_1).typeinfo = &float_address_typeinfo;

    Matrix* matrix_2 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_2).rank_of_matrix = rank;
    (*matrix_2).len_matrix = len;
    (*matrix_2).Matrix = (number*)malloc(len * sizeof(number));
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 2.0;
        }
        if (i == 1){
            val = 0.0;
        }
        if (i == 2){
            val = 1.0;
        }
        if (i == 3){
            val = 2.0;
        }
        number* num = create_float(val);
        (*matrix_2).Matrix[i] = *num;
        free(num);
    }
    (*matrix_2).typeinfo = &float_address_typeinfo;

    //1
    Matrix* prod = matrix_multiply(matrix_1, matrix_2);
    if (prod == nullptr){
        EXPECT_TRUE(false);
    }
    //2 3 4 5
    number* address = (*prod).Matrix;
    for (int i = 0; i < len; ++i){
        float expected;
        if (i == 0){
            expected = 4.0;
        }
        if (i == 1){
            expected = 4.0;
        }
        if (i == 2){
            expected = 10.0;
        }
        if (i == 3){
            expected = 8.0;
        }
        EXPECT_EQ(*(float*)address[i].type_num, expected);
    }

    clear_matrix(prod);
    clear_matrix(matrix_1);
    clear_matrix(matrix_2);
}

TEST(matrix_scalar_multiply_test, value){
    int rank = 2;
    int len = rank * rank;

    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    (*m).rank_of_matrix = rank;
    (*m).len_matrix = len;
    (*m).Matrix = (number*)malloc(len * sizeof(number));
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 1.0;
        }
        if (i == 1){
            val = 2.0;
        }
        if (i == 2){
            val = 3.0;
        }
        if (i == 3){
            val = 4.0;
        }
        number* num = create_float(val);
        (*m).Matrix[i] = *num;
        free(num);
    }
    (*m).typeinfo = &float_address_typeinfo;

    float scalar = 2.0;

    //1
    Matrix* result = matrix_scalar_multiply(m, &scalar, 1);
    if (result == nullptr){
        EXPECT_TRUE(false);
    }
    
    //2 3 4 5
    number* address = (*result).Matrix;
    for (int i = 0; i < len; ++i){
        float expected;
        if (i == 0){
            expected = 2.0;
        }
        if (i == 1){
            expected = 4.0;
        }
        if (i == 2){
            expected = 6.0;
        }
        if (i == 3){
            expected = 8.0;
        }

        EXPECT_EQ(*(float*)address[i].type_num, expected);
    }

    clear_matrix(result);
    clear_matrix(m);
}

TEST(matrix_summ_test, mismatched_ranks){
    int rank1 = 2, rank2 = 3;
    int len1 = rank1 * rank1, len2 = rank2 * rank2;
    
    //1
    Matrix* matrix_1 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_1).rank_of_matrix = rank1;
    (*matrix_1).len_matrix = len1;
    (*matrix_1).Matrix = (number*)malloc(len1 * sizeof(number));
    for (int i = 0; i < len1; ++i){
        number* num = create_float(1.0);
        (*matrix_1).Matrix[i] = *num;
        free(num);
    }
    (*matrix_1).typeinfo = &float_address_typeinfo;

    Matrix* matrix_2 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_2).rank_of_matrix = rank2;
    (*matrix_2).len_matrix = len2;
    (*matrix_2).Matrix = (number*)malloc(len2 * sizeof(number));
    for (int i = 0; i < len2; ++i){
        number* num = create_float(1.0);
        (*matrix_2).Matrix[i] = *num;
        free(num);
    }
    (*matrix_2).typeinfo = &float_address_typeinfo;

    Matrix* sum = matrix_summ(matrix_1, matrix_2);
    EXPECT_EQ(sum, nullptr);

    clear_matrix(matrix_1);
    clear_matrix(matrix_2);
}

TEST(get_elem_test, value){
    int rank = 2;
    int len = rank * rank;

    Matrix* matrix_1 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_1).rank_of_matrix = rank;
    (*matrix_1).len_matrix = len;
    (*matrix_1).Matrix = (number*)malloc(len * sizeof(number));
    
    
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 1.0;
        }
        if (i == 1){
            val = 2.0;
        }
        if (i == 2){
            val = 3.0;
        }
        if (i == 3){
            val = 4.0;
        }
        number* num = create_float(val);
        (*matrix_1).Matrix[i] = *num;
        free(num);
    }

    //1 2 3 4 5
    for (int i = 0; i < len; ++i){
        number* elem = get_elem(matrix_1, i);
        if (elem == nullptr){
            EXPECT_TRUE(false);
        }
        float expected;
        if (i == 0){
            expected = 1.0;
        }
        if (i == 1){
            expected = 2.0;
        }
        if (i == 2){
            expected = 3.0;
        }
        if (i == 3){
            expected = 4.0;
        }
        EXPECT_EQ(*(float*)((*elem).type_num), expected);
    }
    // 6 7 8
    number* elem_neg = get_elem(matrix_1, -1);
    EXPECT_EQ(elem_neg, nullptr);
    number* elem_out = get_elem(matrix_1, len);
    EXPECT_EQ(elem_out, nullptr);
    number* elem_out2 = get_elem(matrix_1, len + 5);
    EXPECT_EQ(elem_out2, nullptr);

    clear_matrix(matrix_1);
}

TEST(set_elem_test, value){
    int rank = 2, len = 4;

    Matrix *matrix_1 = (Matrix*)malloc(sizeof(Matrix));
    (*matrix_1).Matrix = (number*)malloc(len * sizeof(number));
    (*matrix_1).len_matrix = len;
    (*matrix_1).rank_of_matrix = rank;

    //1 2 3 4
    for (int i = 0; i < len; ++i){
        float val;
        if (i == 0){
            val = 1.0;
        }
        if (i == 1){
            val = 2.0;
        }
        if (i == 2){
            val = 3.0;
        }
        if (i == 3){
            val = 4.0;
        }
        number* num = create_float(val);
        (*matrix_1).Matrix[i] = *num;
        free(num);
    }
    //5
    for (int i = 0; i < len; ++i){
        number *elem = create_float(42);
        set_elem(matrix_1, i, elem);
        EXPECT_EQ(*(float*)((*matrix_1).Matrix[i].type_num), 42);
    }
    

}


