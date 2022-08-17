#include <iostream>
#include <string>

class demo
{
private:
    /* data */
    int *n;
public:
    demo(){n = new int;std::cout<<"不带参数的构造函数调用\n";}
    demo(int i){n = new int; *n = i; std::cout<<"带一个参数的构造函数\n";}
    ~demo(){delete n; n = 0; std::cout<<"析构函数调用\n";}

    demo(const demo&a){n = new int; *n = *(a.n);}

    int get()const{return *n;}
    void set(int x){*n = x;}

    demo &opreator=(const demo&r)
    {
        if(this->i)
    }
};

