#include<iostream>
void swap(int &a, int &b);
int main()
{
    int a = 9;
    int &ra = a;
    std::cout << ra << std::endl;
    std::cin >> ra;
    std::cout << a << std::endl;
    int z = 123;
    int x = 321;
    swap(z, x);
    std::cout << z << " " << x;    
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}