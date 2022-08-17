#include <iostream>
using namespace std;

const int num=10;
template<typename T>
int add(T &ra, T &ry)
{
    return (ra + ry);
}

class A
{
public:
    A &operator=(const A &aa)
    {
        if(&aa != this)
        {
            this->i = aa.i;
            return *this;
        }
        return *this;
    }
private:
    int *i;
};

int main()
{
    int x=2,y=3;
    int a = add(x,y);
    cout<<a<<endl;
}