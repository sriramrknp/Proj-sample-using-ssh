#include<stdio.h>
#include<stdlib.h>
#define sze 5

int main()
{
    char *roll_num[sze];
    roll_num[0] = (char *)malloc(10 * sizeof(char));
    roll_num[1] = (char *)malloc(10 * sizeof(char));
    roll_num[2] = (char *)malloc(10 * sizeof(char));
    roll_num[3] = (char *)malloc(10 * sizeof(char));
    roll_num[4] = (char *)malloc(10 * sizeof(char));

    char *name[sze];
    name[0] = (char *)malloc(10 * sizeof(char));
    name[1] = (char *)malloc(10 * sizeof(char));
    name[2] = (char *)malloc(10 * sizeof(char));
    name[3] = (char *)malloc(10 * sizeof(char));
    name[4] = (char *)malloc(10 * sizeof(char));

    char *branch[sze];
    branch[0] = (char *)malloc(10 * sizeof(char));
    branch[1] = (char *)malloc(10 * sizeof(char));
    branch[2] = (char *)malloc(10 * sizeof(char));
    branch[3] = (char *)malloc(10 * sizeof(char));
    branch[4] = (char *)malloc(10 * sizeof(char));

    for (int i = 0; i < 3; i++)
    {
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
            roll_num[i][k] = '~';
    }
    for (int i = 0; i < 3; i++)
    {
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
            name[i][k] = '~';
    }
    for (int i = 0; i < 3; i++)
    {
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
            branch[i][k]='~';
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
        {
            printf("%c", roll_num[i][k]);
            // if (*(roll_num[i] + k) == '~')
                // break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
        {
            printf("%c", name[i][k]);
            // if (*(roll_num[i] + k) == '~')
                // break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++)
        {
            printf("%c", branch[i][k]);
            // if (*(roll_num[i] + k) == '~')
            //    break;
        }
    }

    // scanning
    printf("Enter details:\n");
    for (int i = 0; i < 3;i++)
    {
        printf("Enter roll num of person %d:", i);
        //for (int j = 0; j < 2;j++)
            for (int k = 0; k < 10;k++){
                scanf("%[^\n]%*c", &*(roll_num[i] + k));
                if (*(roll_num[i] + k)=='~')
                    break;
            }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Enter name of person %d:", i);
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++){
            scanf("%[^\n]%*c", &*(name[i] + k));
            if (*(roll_num[i] + k) == '~')
                break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Enter branch of person %d:", i);
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++){
            scanf("%[^\n]%*c", &*(branch[i] + k));
            if (*(roll_num[i] + k) == '~')
                break;
        }
    }



    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++){
            printf("%c", *(roll_num[i] + k));
            if (*(roll_num[i] + k) == '~')
                break;
        }
            
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++){
            printf("%c", *(name[i] + k));
            if (*(roll_num[i] + k) == '~')
                break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        // for (int j = 0; j < 2;j++)
        for (int k = 0; k < 10; k++){
            printf("%c", *(branch[i] + k));
            if (*(roll_num[i] + k) == '~')
                break;
        }
    }


    // for (int i = 0; i < 5; i++)
    // {
    //     //printf("Enter details of person %d:", i);
    //     printf("\n");
    //     for (int j = 0; j < 2; j++){
    //         while (t--){
    //             for (int k = 0; k < 2; k++)
    //                 printf("%c %c %c", *(roll_num[i] + j + k), *(name[i] + j + k), *(branch[i] + j + k));
    //         }
    //         t = 3;
    //     }
    // }

    //printf("%c %c %c", *(roll_num[0] + 1), *(name[0] +0), *(branch[0] + 1));
    return 0;
}