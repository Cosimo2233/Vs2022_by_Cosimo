#include <stdio.h>

#include <time.h>
int main()
{
     clock_t start,end;
     int big,middle,small,count;
     start=clock();
     big=1;count=0;
     printf("this is a while program\n\n");
     while(big<=33)
     {
        middle=1;
        while(middle<=50)
        {
            small=2;
            while(small<=98)
            {
                if(big + middle + small == 100 && 3 * big + 2 * middle + small*0.5 == 100)
                {
                    count++;
                }
                small+=2;
            }
            middle++;
        }
        big++;
     }
     end=clock();
     printf("the num of method1 is:%d\n\n",count);
     printf("the time is:%5.1f time\n",difftime(end,start));
     return 0;
}