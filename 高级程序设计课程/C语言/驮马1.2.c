#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start,end;
     int big,middle,small,count;
     start=clock();
     big=1;count=0;
     printf("this is a for program\n\n");
     for(big=1;big<=32;big++)
     {
        for(middle=1;middle<=48;middle++)
        {
            small=100-big-middle;
            if(small>=1&&big*3+middle*2+small*0.5==100)
            {
                count++;
            }
        }
     }
     end=clock();
     printf("the num of method2 is:%d\n\n",count);
     printf("the time is:%5.1f time\n",difftime(end,start));
     return 0;
}