#include<iostream>
#include<string>
class A
{
public:
    A(int ii):i(ii){}
    A operator+(const A&aa)
    {
        return A(aa.i + this->i);
    }

    A operator++(int)
    {
        A a(i);
        ++i;
        return a;
    }

    A operator++()
    {
        ++i;
        return *this;
        //i++;
        //A a(i);
        //return a;
    }

    A operator-(const A&aa)
    {
        return A(aa.i - this->i);
    }

    A operator*(const A&aa)
    {
        return A(aa.i * this->i);
    }

    A operator/(const A&aa)
    {
        return A(aa.i / this->i);
    }

    int get(){return i;}

private:
    int i;
};

int main()
{
    A a(2);
    A b(6);
    A c = a + b;

    A d = ++c;
    std::cout << d.get(); 
}