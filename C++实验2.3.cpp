#include <iostream>
using namespace std;
int f(int x);
int main()
{
    int num;
    while(1)
    {
        cout<<"input a number(50<=num<=10000):"<<endl;
        cin>>num;
        if(num<50||num>10000)
        {
            cout<<"error"<<endl;
            continue;
        }
        break;
    }
    cout<<"the sum is:"<<f(num)<<endl;
    return 0;
}
int f(int x)
{
    int sum=0;
    sum=(x+1)*x/2;
    return sum;
}