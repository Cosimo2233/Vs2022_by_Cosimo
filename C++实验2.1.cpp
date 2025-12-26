#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,s,area;
    while(114514)
    {
        cout<<"a=";
        cin>>a;
        cout<<"b=";
        cin>>b;
        cout<<"c=";
        cin>>c;
        if(a<=0||b<=0||c<=0)
        {
            cout<<"error"<<endl;
            continue;
        }
        if(a+b<=c||a+c<=b||b+c<=a)
        {
            cout<<"error"<<endl;
            continue;
        }
        break;
    }
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"area="<<area<<endl;
    return 0;
}