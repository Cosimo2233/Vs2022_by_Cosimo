#include<stdio.h>
#include <conio.h>
int main()
{
    char c;
    printf("        2025/11/5\n");

    printf("***************************\n");
    printf("*             Menu        *\n");
    printf("*          1.Input        *\n");
    printf("*          2.Output       *\n");
    printf("*          3.End          *\n");
    printf("***************************\n");
    //start:
    printf("Enter Number=>\n");
       c=getch();
       
       // while(getch() != '\n');
        if(c<'0'||c>'9')
        {
            
            printf("error,please input again!\n");
            
            
        }else{
            printf("Ch=--------->%d\n",c);
        }
        
}