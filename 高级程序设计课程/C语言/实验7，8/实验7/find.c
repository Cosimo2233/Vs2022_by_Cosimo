#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int FindChar(const char* str, char xCh, int** positions)
{
    int count = 0;
    int len = strlen(str);
    int* position = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        if (str[i] == xCh)
        {
            position[count] = i;
            count++;
        }
    }
    *positions = position;
    return count;
}


int FindString(const char* str, const char* target, int** positions)
{
    int count = 0;
    int str_len = strlen(str);
    int target_len = strlen(target);
    int* position = (int*)malloc(str_len * sizeof(int));
    for (int i = 0; i <= str_len; i++)
    {
        int found = 1;
        for (int j = 0; j < target_len; j++)
        {
            if (str[i + j] != target[j])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            position[count] = i;
            count++;
        }
    }
    *positions = position;
    return count;
}
