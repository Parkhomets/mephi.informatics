#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

struct Matrix{
    void *a;
    int n,m;
    int size;
};
struct Complex{
    float x;//действительная часть
    float y;//мнимая часть

};
void scanf_int(struct Matrix* Matrix1,int s){
    scanf("%d", ((int*)Matrix1->a + s));
}
void scanf_float(struct Matrix* Matrix1,int s){
    scanf("%f", ((float*)Matrix1->a + s) );
}
void scanf_complex(struct Matrix* Matrix1, int s){
    scanf("%f %f", &(((struct Complex*)Matrix1->a + s)->x),&(((struct Complex*)Matrix1->a + s)->y) );
}
void create_Matrix(struct Matrix* Matrix1,void (*f)(struct Matrix*, int),int mass){
    Matrix1->size = mass;
    printf("Enter size of the matrix (row, column):\n");
    scanf("%d %d", &Matrix1->n, &Matrix1->m);
    Matrix1->a = malloc(Matrix1->size*Matrix1->n*Matrix1->m);
    int i,j;
    for (i = 0; i< Matrix1->n; i++)
        for (j = 0; j < Matrix1->m; j++)
            f(Matrix1,Matrix1->m*i + j);
    printf("\n");
}

void print_int(struct Matrix* Matrix1, int s){
    printf("%d ", *((int*)Matrix1->a + s));
}
void print_float(struct Matrix* Matrix1, int s){
    printf("%f ", *((float*)Matrix1->a + s));
}
void print_complex(struct Matrix* Matrix1, int s){
    printf("(%f + i%f) ", ((struct Complex*)Matrix1->a + s)->x,((struct Complex*)Matrix1->a + s)->y);
}
void print_Matrix(struct Matrix* Matrix1, void (*f)(struct Matrix*, int)){
int i, j;
    for (i=0; i < Matrix1->n; i++){
        for(j = 0; j < Matrix1->m; j ++)
            f(Matrix1,Matrix1->m*i + j);
        printf("\n");
    }
}

void add_int(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int s){
    *((int*)M3->a + s) = *((int*)M1->a + s) + *((int*)M2->a + s);
}
void add_float(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int s){
    *((float*)M3->a + s) = *((float*)M1->a + s) + *((float*)M2->a + s);
}
void add_complex(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int s){
    (((struct Complex*)M3->a + s)->x) = (((struct Complex*)M1->a + s)->x) + (((struct Complex*)M2->a + s)->x);
    (((struct Complex*)M3->a + s)->y) = (((struct Complex*)M1->a + s)->y) + (((struct Complex*)M2->a + s)->y);
}
void add_Matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3,void (*f)(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int), int mass){
    int i,j;
    M3->size = mass;
    M3->n = 0;
    M3->m = 0;
    if (M2->n == M1->n && M1->m == M2->m){
        M3->n = M2->n;
        M3->m = M2->m;
        free(M3->a);
        M3->a = malloc(M1->n * M1->m * M3->size);

        for (i = 0; i< M2->n; i++)
            for (j = 0; j < M2->m; j++)
                f(M1, M2, M3, M2->m*i + j);
        printf("\n\n");
    }else{
        printf("Unsupported size for addiction\n\a");
    }
}

void mult_matrix(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3,void (*f)(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int, int, int, int, int, int), int mass){
    int i,j,k;
    M3->size = mass;
    M3->m = 0;
    M3->n = 0;

    if (M1->m == M2->n){
        M3->n = M1->n;
        M3->m = M2->m;
        M3->a = malloc(M3->n*M3->m*M3->size);
        for (i = 0; i< M3->n; i++)
            for (j = 0; j < M3->m; j++)
                for(k=0; k<mass; k++)
                    *((char*)M3->a + M3->m*i*mass + j*mass + k) = 0;
        int p;
        for (p = 0; p < M3->n; p++)
            for (i = 0; i < M2->m; i++)
                for (j = 0; j < M1->m; j++)
                    f(M1, M2, M3, M2->m*p+i, M1->m*p+j, j*M2->m+i, M1->m*p+j, j*M2->m+i,M3->m*p+i);
                    ////*((int*)M3->a + M2->m*p +i) += *((int*)M1->a + M1->m * p + j) * *((int*)M2->a+j * M2->m + i);*/
    }else
        printf("Unsupported size for multiplication\n\a");
}
void mult_int(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int h,  int b, int c,int z, int v, int l){
    *((int*)M3->a + h) += *((int*)M1->a + b) * *((int*)M2->a+ c);
}
void mult_float(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3, int h, int b, int c, int z, int v, int l){
    *((float*)M3->a + h) += *((float*)M1->a + b) * *((float*)M2->a+ c);
}
void mult_complex(struct Matrix* M1, struct Matrix* M2, struct Matrix* M3,int z, int l, int v, int h, int b, int c){
    float x1,x2,y1,y2;
    x1 = ((struct Complex*)M1->a + h)->x; //adress1 a
    y1 = ((struct Complex*)M1->a + h)->y; //adress1 b
    x2 = ((struct Complex*)M2->a+ b)->x;   //adress2 a'
    y2 = ((struct Complex*)M2->a+ b)->y;   //adress2 b'
    ((struct Complex*)M3->a + c)->x += x1*y1 - x2*y2;
    ((struct Complex*)M3->a + c)->y += x1*y2 + x2*y1;
}


#endif // FUNCTIONS_H_INCLUDED
