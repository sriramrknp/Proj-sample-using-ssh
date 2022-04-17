#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define sze 20

int main()
{
    char **rollNum, **names, **branch;
    int total = 0;

    printf("Enter number of entities: ");
    scanf("%d", &total);

    rollNum = malloc(total * (sizeof(char *)));
    names = malloc(total * (sizeof(char *)));
    branch = malloc(total * (sizeof(char *)));
    char buffer[sze];
    int length = 0;

    while(getchar()!='\n');

    printf("\n");
    for (int i = 0; i < total; i++)
    {
        printf("Enter rollNum %d: ", i + 1);
        fgets(buffer, sze, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        rollNum[i] = malloc(length * (sizeof(char)));
        strcpy(rollNum[i], buffer);
    
        printf("Enter name of %d: ", i + 1);
        fgets(buffer, sze, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        names[i] = malloc(length * (sizeof(char)));
        strcpy(names[i], buffer);
    
        printf("Enter branch %d: ", i + 1);
        fgets(buffer, sze, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        branch[i] = malloc(length * (sizeof(char)));
        strcpy(branch[i], buffer);

        printf("\n");
    }

    for (int i = 0; i < total; i++)
    {
        printf("\n");
        printf("%s   %s            %s", rollNum[i], names[i], branch[i]);
    }

    printf("\n");
    return 0;
}