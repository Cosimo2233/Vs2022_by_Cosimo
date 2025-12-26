#include <iostream>
using namespace std;

int main()
{
    int letter,num,space,other;
    letter=0;num=0;space=0;other=0;
    char ch;
    cout<<"input a string:"<<endl;
    while((ch=cin.get())!='\n')
    {
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){letter++;}
        else if(ch>='0'&&ch<='9'){num++;}
        else if(ch==' '){space++;}
        else {other++;}
    }
    cout<<"letter="<<letter<<endl;
    cout<<"num="<<num<<endl;
    cout<<"space="<<space<<endl;
    cout<<"other="<<other<<endl;
    return 0;
}