#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start,end;
     int big,middle,small,count;
     start=clock();
     count=0;
     printf("this is a (do while program) \n\n");
     big=0;
     do 
     {       
        middle=0;
        do
        {   
            small=0;         
            do
            {               
                if(big+middle+small==100&&3*big+2*middle+0.5*small==100)
                {
                    count++;
                }
            small++;
            }while(small<=100);
        middle++;
        }while(middle<=50);
    big++;
     } while(big<=33);
     end=clock();
     printf("the num of method2 is:%d\n\n",count);
     printf("the time is:%5.1f time\n",difftime(end,start));
     return 0;
}