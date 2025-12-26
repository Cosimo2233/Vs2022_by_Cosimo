#include <iostream>
using namespace std;
int f(int x,int y);
int main()
{
    int m,n;
    cout<<"m=";
    cin>>m;
    cout<<"n=";
    cin>>n;
    cout<<"the result is:"<<f(m,n)<<endl;
    return 0;
}

int f(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    else{
        return f(y,x%y);
    }
}
