#include <iostream>
using namespace std;

class poser
{
public:
    virtual void beat()const{cout<<"一般选手一拳的力量260磅\n";}
protected:
    int age;
};
class Ali:public poser
{
public:
    void beat()const{cout<<"阿里一拳的力量为420磅\n";}
};
class Lewis:public poser
{
public:
    void beat()const{cout<<"刘易斯一拳的力量为480磅\n";}
};
class Tyson:public poser
{
public:
    void beat()const{cout<<"泰森一拳的力量为500磅\n";}
};
class holy:public poser
{
public:
    void beat()const{cout<<"霍利菲尔德一拳的力量为350磅\n";}
};
int main() 
{ 
    poser *a[5];
    poser *p;
    int choice,i;
    for(i=0;i<5;i++)
    {
        cout<<"(1)阿里(2)刘易斯(3)泰森(4)霍利菲尔德：";
        cin>>choice;
        switch(choice)
        {
            case 1:p=new Ali;
                //选择1时，新建Ali对象，并用指针p来指向它
                break;
            case 2:p=new Lewis;
                break;
            case 3:p=new Tyson;
                //选择3时，新建Tyson对象，并用指针p来指向它
                break;
            case 4:p=new holy;
                //选择4时，新建holy对象，并用指针p来指向它
                break;
            default:p=new poser;
                //默认时，也就是选其他数字，新建poser对象
                break;
        }
        a[i]=p;
        a[i]->beat();
    }
}