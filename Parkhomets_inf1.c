#include <stdio.h>
#include <stdlib.h>
#include "Tests.h"
#include "functions.h"

int main()
{
    struct Matrix M1, M2, M3;
    printf("What would you like to do?\nProvide operations with matrix - 1\nProvide test - 2\n");
    int var;
    scanf("%d", &var);
    if (var == 1){
        printf("\nWhat kind of matrix you want to use?\nInteger - 1\nFloat - 2\nComplex - 3\n");
        scanf("%d", &var);
        switch(var){
        case 1:
            printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
            scanf("%d", &var);
            create_Matrix(&M1,scanf_int,sizeof(int));
            print_Matrix(&M1,print_int);
            create_Matrix(&M2,scanf_int,sizeof(int));
            print_Matrix(&M2,print_int);
            if (var == 1){
                add_Matrix(&M1,&M2,&M3, add_int,sizeof(int));
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                printf("\nThe answer is:\n");
                print_Matrix(&M3,print_int);
            }else{
                mult_matrix(&M1,&M2,&M3, mult_int, sizeof(int));
                    if(M3.n == 0 || M3.m==0)
                    exit(0);
                printf("\nThe answer is:\n");
                print_Matrix(&M3,print_int);
            }break;
        case 2:
            printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
            scanf("%d", &var);
            create_Matrix(&M1, scanf_float,sizeof(float));
            print_Matrix(&M1,print_float);
            create_Matrix(&M2, scanf_float,sizeof(float));
            print_Matrix(&M2,print_float);
            if (var == 1){
                add_Matrix(&M1,&M2,&M3, add_float,sizeof(float));
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                printf("\nThe answer is:\n");
                print_Matrix(&M3,print_float);
            }else{
                mult_matrix(&M1,&M2,&M3, mult_float,sizeof(float));
                if(M3.n == 0 || M3.m==0)
                    exit(0);
                printf("\nThe answer is:\n");
                print_Matrix(&M3,print_float);
            }break;
            case 3:
                printf("\nAddition or multiplication?\nAddition - 1\nMultiplication - 2\n");
                scanf("%d", &var);
                create_Matrix(&M1, scanf_complex,sizeof(struct Complex));
                print_Matrix(&M1,print_complex);
                create_Matrix(&M2, scanf_complex,sizeof(struct Complex));
                print_Matrix(&M2,print_complex);
                if (var == 1){
                    add_Matrix(&M1,&M2,&M3, add_complex, sizeof(struct Complex));
                    if(M3.n == 0 || M3.m==0)
                        exit(0);
                    printf("\nThe answer is:\n");
                    print_Matrix(&M3,print_complex);
                }else{
                    mult_matrix(&M1,&M2,&M3,mult_complex,sizeof(struct Complex));
                    if(M3.n == 0 || M3.m==0)
                        exit(0);
                    printf("\nThe answer is:\n");
                    int i, j;
                    printf("\n");
                    print_Matrix(&M3,print_complex);
                }break;
                }
    }
    else{
        printf("\nWhat type of matrix you want to test?\nInteger - 1\nFloat - 2\nComplex - 3\n");
        scanf("%d",&var);
        switch(var){
        case 1:
            test_int();
            break;
        case 2:
            test_float();
            break;
        case 3:
            test_complex();
            break;
            }
        }

    return 0;
 }























