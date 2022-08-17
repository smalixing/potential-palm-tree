#include <iostream>


class A
{
    friend class B;
public:
    A(){a = 666;}
private:
    int a;
};

class B
{
public:
    int fun(A a)
    {
        return a.a;
    }
};

int main()
{
    B b;
    A a;
    std::cout<<b.fun(a)<<std::endl;
}
