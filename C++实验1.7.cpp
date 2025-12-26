#include<iostream>
using namespace std;
int f(int x);
int main()
{
    int num,digit=0,n[5]={0},new_num=0;
    while(1)
    {
        cout<<" please input a number(0~99999):"<<endl;
        cin>>num;
        if(num<=0||num>99999)
        {
            cout<<"error"<<endl;
            continue;
        }
        break;
    }
    
    for(int i=0;i<5;i++)
    {       
        if(num!=0)
        {
            digit++;
        } 
        n[i]=num%10;
        num/=10;
    }
    cout<<"the digit is:"<<digit<<endl;
    for( int i=digit-1;i>=0;i--)
    {
        cout<<n[i]<<" ";
    }

    for (int i=0;i<digit;i++)
    {
        new_num+=n[i]*f(digit-i-1);
    }
    cout<<"the new number is:"<<new_num<<endl;
    return 0;

}
int f(int x)
{
    int i,sum=1;
    for(i=0;i<x;i++)
    {
        sum*=10;
    }
    return sum;
}