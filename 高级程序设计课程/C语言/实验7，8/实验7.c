#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindChar(const char *str,char xCh,int **positions);

int main()
{
    char str[100];
    char xCh;
    int *position;
    int count;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character if present

    printf("Enter a character to find: ");
    scanf(" %c", &xCh);

    count = FindChar(str, xCh, &position);

    if(count == -1)
    {
        return 1; // Exit if memory allocation failed
    }

    if(count == 0)
    {
        printf("Character '%c' not found in the string.\n", xCh);
    }
    else
    {
        printf("Character '%c' found %d times at positions: ", xCh, count);
        for(int i = 0; i < count; i++)
        {
            printf("%d ", position[i]);
        }
        printf("\n");
    }

    free(position);
    return 0;
}

int FindChar(const char *str,char xCh,int **positions)
{
    int count=0;
    int len=strlen(str);
    int *position=(int *)malloc(len*sizeof(int));
    if(position==NULL)
    {
        printf("Error\n");
        return -1;
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]==xCh)
        {
            position[count]=i;
            count++;
        }
    }
    *positions=position;
    return count;
}



