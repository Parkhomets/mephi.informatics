#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    void *a;
    int n,m;
};
struct Complex{
    float x;//действительная часть
    float y;//мнимая часть

};

void create_int_Matrix(struct Matrix* Matrix1){
    printf("Enter size of the matrix (row, column):\n");
    scanf("%d %d", &Matrix1->n, &Matrix1->m);
    Matrix1->a = (int*)malloc(sizeof(int)*Matrix1->n*Matrix1->m);
    int i,j;
    for (i = 0; i< Matrix1->n; i++)
        for (j = 0; j < Matrix1->m; j++)
            scanf("%d", ((int*)Matrix1->a + Matrix1->m*i + j));
    printf("\n");
}
void create_float_Matrix(struct Matrix* Matrix1){
    printf("Enter size of the matrix (row, column):\n");
    scanf("%d %d", &Matrix1->n, &Matrix1->m);
    Matrix1->a = malloc(sizeof(float)*Matrix1->n*Matrix1->m);
    int i,j;
    for (i = 0; i< Matrix1->n; i++)
        for (j = 0; j < Matrix1->m; j++)
            scanf("%f", ((float*)Matrix1->a + Matrix1->m*i + j) );
    printf("\n");
}
void create_complex_Matrix(struct Matrix* Matrix1){
    printf("Enter size of the matrix (row, column):\n");
    scanf("%d %d", &Matrix1->n, &Matrix1->m);
    Matrix1->a = malloc(sizeof(struct Complex)*Matrix1->n*Matrix1->m);
    int i,j;
    for (i = 0; i< Matrix1->n; i++)
        for (j = 0; j < Matrix1->m; j++)
            scanf("%f %f", &(((struct Complex*)Matrix1->a + Matrix1->m*i + j)->x),&(((struct Complex*)Matrix1->a + Matrix1->m*i + j)->y) );
    printf("\n");
}

void print_int_Matrix(struct Matrix* Matrix1){
int i, j;
    printf("\n");
    for (i=0; i < Matrix1->n; i++){
        for(j = 0; j < Matrix1->m; j ++)
            printf("%d ", *((int*)Matrix1->a+Matrix1->m*i+j));
        printf("\n");
    }
}
void print_float_Matrix(struct Matrix* Matrix1){
int i, j;
    printf("\n");
    for (i=0; i < Matrix1->n; i++){
        for(j = 0; j < Matrix1->m; j ++)
            printf("%f ", *((float*)Matrix1->a+Matrix1->m*i+j));
        printf("\n");
    }
}
void print_complex_Matrix(struct Matrix* Matrix1){
int i, j;
    printf("\n");
    for (i=0; i < Matrix1->n; i++){
        for(j = 0; j < Matrix1->m; j ++)
            printf("(%f + i%f) ", ((struct Complex*)Matrix1->a+Matrix1->m*i+j)->x,((struct Complex*)Matrix1->a+Matrix1->m*i+j)->y);
        printf("\n");
    }
}

void add_int_Matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j;
    M3->n = 0;
    M3->m = 0;
    if (M2->n == M1->n && M1->m == M2->m){
        M3->n = M2->n;
        M3->m = M2->m;
        free(M3->a);
        M3->a = malloc(M1->n * M1->m * sizeof(int));

        for (i = 0; i< M2->n; i++)
            for (j = 0; j < M2->m; j++)
                *((int*)M3->a + M2->m*i + j) = *((int*)M1->a + M2->m*i + j) + *((int*)M2->a + M2->m*i + j);
        printf("\n\n");
    }else{
        printf("Unsupported size for addiction\n");
    }
}
void add_float_Matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j;
    M3->n = 0;
    M3->m = 0;
    if (M2->n == M1->n && M1->m == M2->m){
        M3->n = M2->n;
        M3->m = M2->m;
        free(M3->a);
        M3->a = malloc(M1->n * M1->m * sizeof(float));

        for (i = 0; i< M2->n; i++)
            for (j = 0; j < M2->m; j++)
                *((float*)M3->a + M2->m*i + j) = *((float*)M1->a + M2->m*i + j) + *((float*)M2->a + M2->m*i + j);
        printf("\n\n");
    }else{
        printf("Unsupported size for addiction\n");
    }
}
void add_complex_Matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j;
    M3->n = 0;
    M3->m = 0;
    if (M2->n == M1->n && M1->m == M2->m){
        M3->n = M2->n;
        M3->m = M2->m;
        free(M3->a);
        M3->a = malloc(M1->n * M1->m * sizeof(struct Complex));

        for (i = 0; i< M2->n; i++)
            for (j = 0; j < M2->m; j++){
                (((struct Complex*)M3->a + M2->m*i + j)->x) = (((struct Complex*)M1->a + M2->m*i + j)->x) + (((struct Complex*)M2->a + M2->m*i + j)->x);
                (((struct Complex*)M3->a + M2->m*i + j)->y) = (((struct Complex*)M1->a + M2->m*i + j)->y) + (((struct Complex*)M2->a + M2->m*i + j)->y);
            }
        printf("\n\n");
    }else{
        printf("Unsupported size for addiction\n");
    }
}



void mult_int_matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j;
    M3->m = 0;
    M3->n = 0;

    if (M1->m == M2->n){
        M3->n = M1->n;
        M3->m = M2->m;
        M3->a = (int*)malloc(sizeof(int)*M3->n*M3->m);
        for (i = 0; i< M3->n; i++)
            for (j = 0; j < M3->m; j++)
                *((int*)M3->a + M3->m*i + j) = 0;
        int p;
        for (p = 0; p < M3->n; p++)
            for (i = 0; i < M2->m; i++)
                for (j = 0; j < M1->m; j++)
                    *((int*)M3->a + M2->m*p +i) += *((int*)M1->a + M1->m * p + j) * *((int*)M2->a+j * M2->m + i);
    }else
        printf("Unsupported size for multiplication\n");
}
void mult_float_matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j;
    M3->m = 0;
    M3->n = 0;

    if (M1->m == M2->n){
        M3->n = M1->n;
        M3->m = M2->m;
        M3->a = (float*)malloc(sizeof(float)*M3->n*M3->m);
        for (i = 0; i< M3->n; i++)
            for (j = 0; j < M3->m; j++)
                *((float*)M3->a + M3->m*i + j) = 0;
        int p;
        for (p = 0; p < M3->n; p++)
            for (i = 0; i < M2->m; i++)
                for (j = 0; j < M1->m; j++)
                    *((float*)M3->a + M2->m*p +i) += *((float*)M1->a + M1->m * p + j) * *((float*)M2->a+j * M2->m + i);
    }else
        printf("Unsupported size for multiplication\n");
}
void mult_complex_matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3){
    int i,j,p;
    M3->m = 0;
    M3->n = 0;

    if (M1->m == M2->n){
        M3->n = M1->n;
        M3->m = M2->m;
        M3->a = (struct Complex*)malloc(sizeof(struct Complex)*M3->n*M3->m);

        for (i = 0; i< M3->n; i++)
            for (j = 0; j < M3->m; j++){
                ((struct Complex*)M3->a + M3->m*i + j)->x = 0;
                ((struct Complex*)M3->a + M3->m*i + j)->y = 0;
            }
        float q,w, e, r;
        for (p = 0; p < M2->m; p++)
            for (i = 0; i < M2->m; i++)
                for (j = 0; j < M1->m; j++){
                    q = ((struct Complex*)M1->a + M1->m * p + j)->x; //adress1 a
                    w = ((struct Complex*)M2->a+j * M2->m + i)->x;   //adress2 a'
                    e = ((struct Complex*)M1->a + M1->m * p + j)->y; //adress1 b
                    r = ((struct Complex*)M2->a+j * M2->m + i)->y;   //adress2 b'
                    ((struct Complex*)M3->a + M3->m*i + j)->x += q * w - e * r;
                    ((struct Complex*)M3->a + M3->m*i + j)->y += q * r + e * w;
                }
    }else
        printf("Unsupported size for multiplication");
}

void test_int_matrix(){

    struct Matrix M1, M2, M3, M4, M5, M6;

    printf("To verify, create the first matrix of size 3*4.\n");
    printf("To validate, fill in the matrix elements 2,4,6,5,3,2,4,5,8,7,4,5.\n\n");
    create_int_Matrix(&M1);
    print_int_Matrix(&M1);
    M2.a = (int*)malloc(sizeof(int)*12);
    M2.n = 3;
    M2.m = 4;
    int M[12] = {2,4,6,5,3,2,4,5,8,7,4,5};
    M2.a = &M;
    int i, j, p;
    p =0;
    if(M1.n == M2.n && M1.m == M2.m){
        for (i = 0; i< M1.n; i++)
            for (j = 0; j < M1.m; j++)
                if (*((int*)M1.a + M1.m*i + j)==*((int*)M2.a + M1.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M2.a);
    printf("To verify, create the second matrix of size 3*4.\n");
    printf("To validate, fill in the matrix elements 6,5,8,2,1,5,4,7,8,5,8,9.\n\n");
    create_int_Matrix(&M3);
    print_int_Matrix(&M3);
    M4.a = (int*)malloc(sizeof(int)*12);
    M4.n = 3;
    M4.m = 4;
    int Ml[12] = {6,5,8,2,1,5,4,7,8,5,8,9};
    M4.a = &Ml;
    p =0;
    if(M3.n == M4.n && M3.m == M4.m){
        for (i = 0; i< M1.n; i++)
            for (j = 0; j < M1.m; j++)
                if (*((int*)M3.a + M3.m*i + j)==*((int*)M4.a + M3.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M4.a);
    printf("validation of addition...");
    add_int_Matrix(&M1, &M3, &M5);
    print_int_Matrix(&M5);
    int Ml2[12] = {8,9,14,7,4,7,8,12,16,12,12,14};
    M6.a = &Ml2;
    M6.n = 3;
    M6.m = 4;
    p =0;

    if(M5.n == M6.n && M5.m == M6.m){
        for (i = 0; i< M5.n; i++)
            for (j = 0; j < M5.m; j++)
                if (*((int*)M5.a + M5.m*i + j)==*((int*)M6.a + M5.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M5.a);
    free(M6.a);
    free(M1.a);
    free(M2.a);
    free(M3.a);

    printf("To check multiplication you need to create two other matrices...\n");
    printf("To verify, create the first matrix of size 4*3\n");
    printf("To validate, fill in the matrix elements 2,3,6,5,4,2,5,3,2,4,6,5.\n\n");
    create_int_Matrix(&M1);
    print_int_Matrix(&M1);
    M2.a = (int*)malloc(sizeof(int)*12);
    M2.n = 4;
    M2.m = 3;
    int Mll[12] = {2,3,6,5,4,2,5,3,2,4,6,5};
    M2.a = &Mll;
    p =0;
    if(M1.n == M2.n && M1.m == M2.m){
        for (i = 0; i< M1.n; i++)
            for (j = 0; j < M1.m; j++)
                if (*((int*)M1.a + M1.m*i + j)==*((int*)M2.a + M1.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M2.a);
    printf("To verify, create the second matrix of size 3*2.\n");
    printf("To validate, fill in the matrix elements 8,6,5,4,7,9.\n\n");
    create_int_Matrix(&M2);
    print_int_Matrix(&M2);
    M3.a = (int*)malloc(sizeof(int)*6);
    M3.n = 3;
    M3.m = 2;
    int Ml3[6] = {8,6,5,4,7,9};
    M3.a = &Ml3;
    p =0;
    if(M2.n == M3.n && M2.m == M3.m){
        for (i = 0; i< M2.n; i++)
            for (j = 0; j < M2.m; j++)
                if (*((int*)M2.a + M2.m*i + j)==*((int*)M3.a + M2.m*i + j))
                    p++;
        if (p == 6){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M3.a);
    printf("Checking the correctness of the multiplication...\n");
    mult_int_matrix(&M1,&M2,&M3);
    print_int_Matrix(&M3);
    M4.a = (int*)malloc(sizeof(int)*8);
    M4.n = 4;
    M4.m = 2;
    int Ml4[8] = {73,78,74,64,69,60,97,93};
    M4.a = &Ml4;
    p =0;
    if(M4.n == M3.n && M4.m == M3.m){
        for (i = 0; i< M4.n; i++)
            for (j = 0; j < M4.m; j++)
                if (*((int*)M4.a + M4.m*i + j)==*((int*)M3.a + M3.m*i + j))
                    p++;
        if (p == 8){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M1.a);
    free(M2.a);
    free(M3.a);
    free(M4.a);
}
void test_float_matrix(){
    struct Matrix M1, M2, M3, M4, M5, M6;
    float eps = 0.000001;
    printf("To verify, create the first matrix of size 4*3.\n");
    printf("To validate, fill in the matrix elements 1.25, 2.25, 4.27, 3.71, 5.22, 7.42, 4.51, 3.17, 5.12, 6.62, 2.66, 2.15...\n\n");
    create_float_Matrix(&M1);
    print_float_Matrix(&M1);
    M2.a = (float*)malloc(sizeof(float)*12);
    M2.n = 4;
    M2.m = 3;

    float M[] = {1.25, 2.25, 4.27, 3.71, 5.22, 7.42, 4.51, 3.17, 5.12, 6.62, 2.66, 2.15};
    M2.a = &M;
    int i, j, p;
    p =0;
    if(M1.n == M2.n && M1.m == M2.m){
        for (i = 0; i< M1.n; i++)
            for (j = 0; j < M1.m; j++)
                if (*((float*)M1.a + M1.m*i + j)==*((float*)M2.a + M1.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }

    free(M2.a);
    printf("To verify, create the second matrix of size 4*3.\n");
    printf("To validate, fill in the matrix elements 7.45, 2.23, 2.11, 3.12, 2.27, 3.21, 1.71, 3.08, 4.01, 1.65, 4.42, 2.04...\n\n");
    create_float_Matrix(&M3);
    print_float_Matrix(&M3);
    M2.a = (float*)malloc(sizeof(float)*12);
    M2.n = 4;
    M2.m = 3;

    float Mass[] = {7.45, 2.23, 2.11, 3.12, 2.27, 3.21, 1.71, 3.08, 4.01, 1.65, 4.42, 2.04};
    M2.a = &Mass;
    p =0;
    if(M3.n == M2.n && M3.m == M2.m){
        for (i = 0; i< M3.n; i++)
            for (j = 0; j < M3.m; j++)
                if (*((float*)M3.a + M3.m*i + j)==*((float*)M2.a + M3.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M2.a);

    printf("validation of addition...");
    add_float_Matrix(&M1, &M3, &M5);
    print_float_Matrix(&M5);

    float Mass2[] = {8.7, 4.48, 6.38, 6.83, 7.49, 10.63, 6.22, 6.25, 9.13, 8.27, 7.08, 4.19};
    M6.a = &Mass2;
    M6.n = 4;
    M6.m = 3;
    p =0;

    if(M5.n == M6.n && M5.m == M6.m){
        for (i = 0; i< M5.n; i++)
            for (j = 0; j < M5.m; j++)
                if (abs(*((float*)M5.a + M5.m*i + j)-*((float*)M6.a + M5.m*i + j))<eps)
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }


    printf("To check multiplication you need to create two other matrices...\n");
    printf("To verify, create the first matrix of size 4*3.\n");
    printf("To validate, fill in the matrix elements 8, 9, 5, 3, 4, 1, 2, 1.1, 6.6, 8.1, 3.3, 1...\n\n");
    create_float_Matrix(&M1);
    print_float_Matrix(&M1);
    M2.a = (float*)malloc(sizeof(float)*12);
    M2.n = 4;
    M2.m = 3;
    float Mass3[12] = {8, 9, 5, 3, 4, 1, 2, 1.1, 6.6, 8.1, 3.3, 1};
    M2.a = &Mass3;
    p =0;
    if(M1.n == M2.n && M1.m == M2.m){
        for (i = 0; i< M1.n; i++)
            for (j = 0; j < M1.m; j++)
                if (*((float*)M1.a + M1.m*i + j)==*((float*)M2.a + M1.m*i + j))
                    p++;
        if (p == 12){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M2.a);

    printf("To verify, create the second matrix of size 3*2.\n");
    printf("To validate, fill in the matrix elements 6, 2.2, 4.1, 5, 1.1, 3...\n\n");
    create_float_Matrix(&M2);
    print_float_Matrix(&M2);
    M3.a = (float*)malloc(sizeof(float)*6);
    M3.n = 3;
    M3.m = 2;
    float Mass4[6] = {6, 2.2, 4.1, 5, 1.1, 3};
    M3.a = &Mass4;
    p =0;
    if(M2.n == M3.n && M2.m == M3.m){
        for (i = 0; i< M2.n; i++)
            for (j = 0; j < M2.m; j++)
                if (*((float*)M2.a + M2.m*i + j)==*((float*)M3.a + M2.m*i + j))
                    p++;
        if (p == 6){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    eps = 0.00001;
    printf("Checking the correctness of the multiplication...\n");
    mult_float_matrix(&M1,&M2,&M5);
    print_float_Matrix(&M5);
    M4.a = (float*)malloc(sizeof(float)*8);
    M4.n = 4;
    M4.m = 2;
    float Mass5[8] = {90.400002, 77.599998, 35.500000, 29.600000,23.770000,29.700001,63.230000,37.320000};
    M4.a = &Mass5;
    p =0;
    if(M4.n == M5.n && M4.m == M5.m){
        for (i = 0; i< M4.n; i++)
            for (j = 0; j < M4.m; j++)
                if (abs(*((int*)M4.a + M4.m*i + j)-*((int*)M5.a + M5.m*i + j))<eps)
                    p++;
        if (p == 8){
            printf("\nTest passed.\n\n");
        }else{
            printf("\nTest failed.\n\n");
        }
    }else{
        printf("\nTest failed.\n\n");
    }
    free(M4.a);
    free(M3.a);
    free(M1.a);
    free(M2.a);

}
void test_complex_matrix(){
    struct Matrix M1, M2, M3, M4, M5;
    printf("To verify, create the first matrix of size 2*2.\n");
    printf("To validate, fill in the matrix elements 2, 2 , 3, 5 , 1, 4, 8, 3.\n\n");
    create_complex_Matrix(&M1);
    print_complex_Matrix(&M1);
    float Mx[] = {2,3,1,8};
    float My[] = {2,5,4,3};
    int p, i, j;
    if (M1.n == 2 && M1.m == 2){
        for (i = 0, p =0; i < M1.n*M1.m;i++){
            if (((struct Complex*)M1.a + i)->x== Mx[i])
                p++;
            if (((struct Complex*)M1.a + i)->y == My[i])
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            printf("Test failed.\n");
            }
    }else{
        printf("Test failed.\n");
        }

    printf("To verify, create the second matrix of size 2*2.\n");
    printf("To validate, fill in the matrix elements 3, 1 , 3, 7 , 6, 9, 3, 8.\n\n");
    create_complex_Matrix(&M2);
    print_complex_Matrix(&M2);
    float Mx1[] = {3,3,6,3};
    float My2[] = {1,7,9,8};
    if (M1.n == 2 && M1.m == 2){
        for (i = 0, p =0; i < M2.n*M2.m;i++){
            if (((struct Complex*)M2.a + i)->x== Mx1[i])
                p++;
            if (((struct Complex*)M2.a + i)->y == My2[i])
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            printf("Test failed.\n");
            }
    }else{
        printf("Test failed.\n");
        }

    printf("validation of addition...\n");
    add_complex_Matrix(&M1,&M2,&M3);
    print_complex_Matrix(&M3);
    float eps = 0.00001;
    float Mx3[] = {5,6,7,11};
    float My4[] = {3,12,13,11};
    if (M3.n == 2 && M3.m == 2){
        for (i = 0, p =0; i < M3.n*M3.m;i++){
            if (((struct Complex*)M3.a + i)->x - Mx3[i] < eps)
                p++;
            if (((struct Complex*)M3.a + i)->y - My4[i] < eps)
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            printf("Test failed.\n");
            }
    }else{
        printf("Test failed.\n");
        }
    free(M3.a);

    printf("validation of multiplication...\n");
    mult_complex_matrix(&M1,&M2,&M4);
    print_complex_Matrix(&M4);
    float Mx5[] = {3,-6,-33,-31};
    float My6[] = {21,147,39,112};
    if (M4.n == M1.n && M4.m == M2.m){
        for (i = 0, p =0; i < M4.n*M4.m;i++){
            if (((struct Complex*)M4.a + i)->x - Mx5[i] < eps)
                p++;
            if (((struct Complex*)M4.a + i)->y - My6[i] < eps)
                p++;
        }
        if (p==8){
            printf("Test passed.\n");
        }else{
            printf("Test failed.\n");
            }
    }else{
        printf("Test failed.\n");
        }
    free(M1.a);
    free(M2.a);
    free(M4.a);
}

int main()
{
    struct Matrix M1, M2, M3;
    printf("What would you like to do?\nProvide operations with matrix - 1\nProvide test - 2\n");
    int var;
    scanf("%d", &var);
    printf("%d",var);
    if (var == 1){
        printf("\nWhat kind of matrix you want to use?\nInteger - 1\nFloat - 2\nComplex - 3\n");
        scanf("%d", &var);
        switch(var){
        case 1:
            printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
            scanf("%d", &var);
            create_int_Matrix(&M1);
            print_int_Matrix(&M1);
            create_int_Matrix(&M2);
            print_int_Matrix(&M2);
            if (var == 1){
                add_int_Matrix(&M1,&M2,&M3);
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                print_int_Matrix(&M3);
            }else{
                mult_int_matrix(&M1,&M2,&M3);
                    if(M3.n == 0 || M3.m==0)
                    exit(0);
                print_int_Matrix(&M3);
            }break;
        case 2:
            printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
            scanf("%d", &var);
            create_float_Matrix(&M1);
            print_float_Matrix(&M1);
            create_float_Matrix(&M2);
            print_float_Matrix(&M2);
            if (var == 1){
                add_float_Matrix(&M1,&M2,&M3);
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                print_float_Matrix(&M3);
            }else{
                mult_float_matrix(&M1,&M2,&M3);
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                print_float_Matrix(&M3);
            }break;
            case 3:
                printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
                scanf("%d", &var);
                create_complex_Matrix(&M1);
                print_complex_Matrix(&M1);
                create_complex_Matrix(&M2);
                print_complex_Matrix(&M2);
                if (var == 1){
                    add_complex_Matrix(&M1,&M2,&M3);
                    if(M3.n == 0 || M3.m==0)
                    exit(0);
                    print_complex_Matrix(&M3);
                }else{
                    mult_complex_matrix(&M1,&M2,&M3);
                    if(M3.n == 0 || M3.m==0)
                    exit(0);
                    print_complex_Matrix(&M3);
                }break;
                }
    }else{
        printf("\nWhat type of matrix you want to test?\nInteger - 1\nFloat - 2\nComplex - 3\n");
        scanf("%d",&var);
        switch(var){
        case 1:
            test_int_matrix();
            break;
        case 2:
            test_float_matrix();
            break;
        case 3:
            test_complex_matrix();
            break;
        }
        }
    return 0;
}





















