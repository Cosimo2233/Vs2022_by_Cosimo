#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LMAX 5
#define CMAX 5

int main()
{
    //system("cls");
    srand(time(NULL));                  //produce the random;
    int a[LMAX][CMAX];
    int i,j,temp;
    for(i=0;i<LMAX;i++)                
    {
        for(j=0;j<CMAX;j++)
        {
            a[i][j]=rand()%100;
        }
    }
    printf("This is the original number~~~~~:)\n\n");
   for(i=0;i<LMAX;i++)                     //output the number;
    {
        for(j=0;j<CMAX;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<CMAX;j++)                    //change the number;
    {
        temp=a[0][j];
        a[0][j]=a[4][j];
        a[4][j]=temp;

    }

    printf("This is the new number~~~~~:):\n\n");
    for(i=0;i<LMAX;i++)                    //output the new number;
    {
        for(j=0;j<CMAX;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<LMAX;i++)                     //output the biggestt number;
    {
        int max_num =a[i][0];
        int max_column=0;
        for(j=0;j<CMAX;j++)
        {
            if(a[i][j]>max_num)
            {
                max_num=a[i][j];
                max_column=j;
            }
        }
        
        printf("The max => %d,at %d line ,%d column .\n\n",max_num,i+1,max_column+1);
    }

    return 0;
}