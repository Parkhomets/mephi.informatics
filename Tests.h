#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "functions.h"
#include <stdio.h>

void failed_int(struct Matrix* M1,struct Matrix* M2,struct Matrix* M3,struct Matrix* M4){
    printf("\nTest failed.\n\n\a");
    printf("Expected:\n");
    print_Matrix(M4, print_int);
    printf("Received:\n");
    print_Matrix(M3, print_int);
}
void failed_float(struct Matrix* M1,struct Matrix* M2,struct Matrix* M3,struct Matrix* M4){
    printf("\nTest failed.\n\n\a");
    printf("Expected:\n");
    print_Matrix(M4, print_float);
    printf("Received:\n");
    print_Matrix(M3, print_float);
}
void failed_complex(struct Matrix* M1,struct Matrix* M2,struct Matrix* M3,struct Matrix* M4){
    printf("\nTest failed.\n\n\a");
    printf("Expected:\n");
    print_Matrix(M4, print_complex);
    printf("Received:\n");
    print_Matrix(M3, print_complex);
}
void test_int(){

    struct Matrix M1, M2, M3, M4, M5;
    M1.size = M2.size = sizeof(int);
    M1.n = M2.n = 3;
    M1.m = M2.m = 4;
    int M[12] = {2,4,6,5,3,2,4,5,8,7,4,5};
    M1.a = M2.a = M;
    int i, j, p;

    printf("validation of addition...");
    add_Matrix(&M1, &M2, &M3, add_int,sizeof(int));

    int Ml2[12] = {4,8,12,10,6,4,8,10,16,14,8,10};
    M4.a = &Ml2[0];
    M4.n = 3;
    M4.m = 4;
    p =0;

    if(M3.n == M4.n && M3.m == M4.m){
        for (i = 0; i< M3.n; i++)
            for (j = 0; j < M3.m; j++)
                if (*((int*)M3.a + M3.m*i + j)==*((int*)M4.a + M3.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            failed_int(&M1,&M2,&M3,&M4);
        }
    }else{
        failed_int(&M1,&M2,&M3,&M4);
    }
    free(M3.a);

    M1.size = sizeof(int);
    M1.n = 4;
    M1.m = 3;
    int Mll[12] = {2,3,6,5,4,2,5,3,2,4,6,5};
    M1.a = Mll;

    M2.size = sizeof(int);
    M2.n = 3;
    M2.m = 2;
    int Ml3[6] = {8,6,5,4,7,9};
    M2.a = Ml3;
    printf("Checking the correctness of the multiplication...\n");
    mult_matrix(&M1,&M2,&M3, mult_int, sizeof(int));

    M4.n = 4;
    M4.m = 2;
    int Ml4[8] = {73,78,74,64,69,60,97,93};
    M4.a = Ml4;
    p =0;

    if(M4.n == M3.n && M4.m == M3.m){
        for (i = 0; i< M4.n; i++)
            for (j = 0; j < M4.m; j++)
                if (*((int*)M4.a + M4.m*i + j)==*((int*)M3.a + M3.m*i + j))
                    p++;
        if (p == 8){
            printf("\nTest passed.\n\n");
        }else{
            failed_int(&M1,&M2,&M3,&M4);
        }
    }else{
        failed_int(&M1,&M2,&M3,&M4);
    }
    free(M3.a);
}
void test_float(){
    struct Matrix M1, M2, M3, M4, M5, M6;
    float eps = 0.000001;
    M1.n = M2.n = 4;
    M1.m = M2.m = 3;
    float Mass[] = {1.25, 2.25, 4.27, 3.71, 5.22, 7.42, 4.51, 3.17, 5.12, 6.62, 2.66, 2.15};
    M1.a = M2.a = Mass;
    int i, j, p;

    printf("validation of addition...");
    add_Matrix(&M1, &M2, &M3, add_float,sizeof(float));

    float Mass2[] = {2.50, 4.45, 8.54, 7.42, 10.44, 14.84, 9.02, 6.34, 10.24, 13.24, 5.32, 4.30};
    M4.a = Mass2;
    M4.n = 4;
    M4.m = 3;
    p =0;

    if(M3.n == M4.n && M3.m == M4.m){
        for (i = 0; i< M3.n; i++)
            for (j = 0; j < M3.m; j++)
                if (abs(*((float*)M3.a + M3.m*i + j)-*((float*)M4.a + M3.m*i + j))<eps)
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            failed_float(&M1,&M2,&M3,&M4);
        }
    }else{
        failed_float(&M1,&M2,&M3,&M4);
    }
    free(M3.a);

    M1.size = sizeof(float);
    M1.n = 4;
    M1.m = 3;
    float Mass3[12] = {8, 9, 5, 3, 4, 1, 2, 1.1, 6.6, 8.1, 3.3, 1};
    M1.a = Mass3;

    M2.size = sizeof(float);
    M2.n = 3;
    M2.m = 2;
    float Mass4[6] = {6, 2.2, 4.1, 5, 1.1, 3};
    M2.a = Mass4;

    eps = 0.00001;
    printf("Checking the correctness of the multiplication...\n");
    mult_matrix(&M1,&M2,&M3, mult_float, sizeof(float));
    M4.n = 4;
    M4.m = 2;
    float Mass5[8] = {90.400002, 77.599998, 35.500000, 29.600000,23.770000,29.700001,63.230000,37.320000};
    M4.a = Mass5;
    p = 0;
    if(M3.n == M4.n && M3.m == M4.m){
        for (i = 0; i< M4.n; i++)
            for (j = 0; j < M4.m; j++){
                if (abs(*((int*)M3.a + M3.m*i + j)-*((int*)M4.a + M4.m*i + j))<eps){
                    p++;}}
        if (p == 8){
            printf("\nTest passed.\n\n");
        }else{
            failed_float(&M1,&M2,&M3,&M4);
        }
    }else{
        failed_float(&M1,&M2,&M3,&M4);
    }

    free(M3.a);
}
void test_complex(){
    struct Matrix M1, M2, M3, M4, M5;
    M1.m = M1.n =M2.m = M2.n = 2;
    M1.size =M2.size = sizeof(struct Complex);
    M1.a = M2.a = malloc(M1.size*M1.n*M1.m);
    int i,j,p;
    for (j = 0,p=1; j < M1.m*M1.m; j++){
        ((struct Complex*)M1.a + j)->x = p*2;
        ((struct Complex*)M1.a + j)->y = (p*2)+1;
        ((struct Complex*)M2.a + j)->x = p*2;
        ((struct Complex*)M2.a + j)->y = (p*2)+1;
        p++;}

    printf("\nValidation of addition...");
    add_Matrix(&M1,&M2,&M3, add_complex, sizeof(struct Complex));

    float eps = 0.00001;

    M4.m = M4.n = 2;
    M4.size = sizeof(struct Complex);
    M4.a = malloc(M4.size*M4.n*M4.m);
    for (j = 0, p=1; j < M1.m*M1.m; j++){
        ((struct Complex*)M4.a + j)->x = p*4;
        ((struct Complex*)M4.a + j)->y = ((p*2)+1)*2;
        p++;}

    if (M3.n == 2 && M3.m == 2){
        for (i = 0, p =0; i < M3.n*M3.m;i++){
            if (abs(((struct Complex*)M3.a + i)->x - ((struct Complex*)M4.a + i)->x) < eps)
                p++;
            if (abs(((struct Complex*)M3.a + i)->y - ((struct Complex*)M4.a + i)->y) < eps)
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            failed_complex(&M1,&M2,&M3,&M4);
            }
    }else{
        failed_complex(&M1,&M2,&M3,&M4);
        }
    free(M3.a);

    printf("\nValidation of multiplication...\n");
    mult_matrix(&M1,&M2,&M3, mult_complex,sizeof(struct Complex));


    float Mx5[] = {-22,-66,66,22};
    float My6[] = {70,98,142,202};
    for (j = 0; j < M1.m*M1.m; j++){
        ((struct Complex*)M4.a + j)->x = Mx5[j];
        ((struct Complex*)M4.a + j)->y = My6[j];}

    if (M3.n == 2 && M3.m == 2){
        for (i = 0, p =0; i < M3.n*M3.m;i++){
            if (abs(((struct Complex*)M3.a + i)->x - ((struct Complex*)M4.a + i)->x) < eps)
                p++;
            if (abs(((struct Complex*)M3.a + i)->y - ((struct Complex*)M4.a + i)->y) < eps)
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            failed_complex(&M1,&M2,&M3,&M4);
            }
    }else{
        failed_complex(&M1,&M2,&M3,&M4);
        }
    free(M1.a);
    free(M2.a);
    free(M3.a);
    free(M4.a);
}


#endif // TESTS_H_INCLUDED
