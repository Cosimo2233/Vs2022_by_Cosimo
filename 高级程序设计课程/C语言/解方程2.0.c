#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double delta;
    int sign;

    printf("请输入 a, b, c 的值（用空格分隔）: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("这不是二次方程！\n");
        return 0;
    }

    delta = b * b - 4 * a * c;

   
    if (delta > 0) 
    {
        sign = 1; 
    } else if (delta == 0) 
    {
        sign = 0; 
    } else 
    {
        sign = -1;
    }

    switch (sign) {
        case 1:
            printf("两个不等实根:\n");
            printf("x1 = %f\n", (-b + sqrt(delta)) / (2 * a));
            printf("x2 = %f\n", (-b - sqrt(delta)) / (2 * a));
            break;
        case 0:
            printf("两个相等实根:\n");
            printf("x1 = x2 = %f\n", -b / (2 * a));
            break;
        case -1:
            printf("有两个虚根:\n");
            break;
        default:
            printf("错误情况\n");
    }

    return 0;
}