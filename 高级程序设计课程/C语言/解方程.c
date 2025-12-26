#include<stdio.h>
#include <math.h>
int main()
{
    double a,b,c;
    printf("a=");
    scanf("%lf",&a);
    printf("b=");
    scanf("%lf",&b);
    printf("c=");
    scanf("%lf",&c);
    double delta;
    double x1,x2;
    if(a==0)
    {
        if(b==0)
        {
            if(c==0)
            {
                printf("countless result!\n");
            }
            else
            {
                printf("error!\n");
            }
        }
        else
        {
            printf("一元一次方程 x1=%f\n",-c/b);
        }
        return 0;
    }

    delta=b*b-4*a*c;
    if(delta>0)
    {
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        printf("有两个不等的实数根：\n");
        printf("x1=%f\n",x1);
        printf("x2=%f\n",x2);
    }else if(delta==0)
            {
                printf("有俩个相等的实数根\n");
                x1=-b/(2*a);
                printf("x1=x2=%f",x1);
            }else
                {
                    printf("有两个虚根\n");
                }
                return 0;
}

