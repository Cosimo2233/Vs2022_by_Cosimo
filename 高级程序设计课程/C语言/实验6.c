#include <stdio.h>

int f(int a,int b);
int g(int a,int b);
int inNumber();

int main()
{
    int a,b,c,d;
    a=inNumber( );
    b=inNumber( );
    c=f(a,b);
    d=g(a,b);
    printf("The greatest common divisor is %d\n",c);
    printf("The least common multiple is %d\n",d);

    return 0;
}
int f(int a,int b)
    {
        int t;
        while(b!=0)
        {
            t=a%b;
            a=b;
            b=t;
        }
        return a;
    }

int g(int a,int b)
{
    int t;
    t=(a*b)/f(a,b);
    return t;
}

int inNumber()
{
    int num;
    while (1) 
    {
        printf("Please input a number :");
        scanf("%d", &num);
        if (num > 0) 
        {
            return num; 
        } 
        else 
        {
            printf("error ! \n");
            while (getchar() != '\n');
        }
    }
}