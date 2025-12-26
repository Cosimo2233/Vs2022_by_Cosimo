#include<stdio.h>
int main()
{
    int num,i;
    float up,down,sum=0;
    printf("input:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        up=2*i+3;
        down=3*i+5;
        sum+=up/down;
    }
    printf("sum=%f\n",sum);
    return 0;
}