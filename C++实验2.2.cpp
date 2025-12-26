#include <iostream>
using namespace std;
int main()
{
    float power=0,price=0;
    
    while(1)
    {
        cout<<"please input the power:"<<endl;
        cin>>power;
        if(power<0)
        {
            cout<<"error!"<<endl;
            continue;
        }
        break;
    }
    if(power>0&&power<=20)
    {
        price=power*0.6;
    }else if(power>20&&power<=30)
    {
        price=20*0.6+(power-20)*1.0;
    }else if(power>30)
    {
        price=20*0.6+10*1.0+(power-30)*2.0;
    }
    cout<<"the price is:"<<price<<endl;
    return 0;
}