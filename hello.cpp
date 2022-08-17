#include <iostream>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;
int main()
{
    int a = 345;
    double b = 123.123;
    char c = '5';
    cout << a << b << c << endl;
    cout << "hello" "world" << endl;
    cout << "杰哥吃粑粑!" << endl;
    /*
    int *p;
    p = new int;
    //int* p = new (std::nothrow) int;
    //如果new失败了，就不会抛出异常而是返回空指针
    delete p;//释放new开辟的空间
    p = nullptr; //空指针 nullptr NULL(c++避免使用NULL)
    */

   int ival;
   char ch;
   cin >> ival >> ch;
   cout << "1: " << ival << ch << endl;

 /*  cin >> ival
        >> ch;
    cout << "2: " << ival << ch << endl;*/
}

