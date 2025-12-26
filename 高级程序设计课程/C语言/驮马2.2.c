#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start,end;
     int big,middle,small,count;
     start=clock();
     count=0;
     printf("this is a (do while program) \n\n");
     for(big=0;big<=33;big++)
     {
        for(middle=0;middle<=50;middle++)
        {
            small=100-big-middle;
            if(6*big+4*middle+small==200)
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