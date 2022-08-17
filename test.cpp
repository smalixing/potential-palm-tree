#include <iostream>
using namespace std;
class A 
{
public:
   A();
   A(A&);
   ~A();
   int get()const{return x;}//注意这里
   void set(const int i){x=i;}
private:
	int x;
};
A::A()
{
   cout<<"执行构造函数创建一个对象\n";
}
A::A(A&)
{
   cout<<"执行复制构造函数创建该对象的副本\n";
}
A::~A()
{
   cout<<"执行析构函数删除该对象\n";
}
const A * func(const A *const one);// 四个const意思
int main()
{
    A a; 
    a.set(99);
   const A * b = func(&a);

    return 0;
}
const A * const func(const A *const one)
{
   //one.set();//这里会错误
    
    //只能调用A类中const成员函数
   cout<<one->get()<<endl;

   return one;
} 