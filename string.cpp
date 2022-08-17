#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
class mystring
{
public:
    mystring()
    {
        _str = new char('\0');
        //*str = '\0';
        _length = 0;
    }
    mystring(const char*str)
    {
        _length = strlen(str);
        _str = new char[_length+1];
        
        strcpy(_str, str);
    }
    mystring(const mystring &str)
    {
        _length = str._length;
        _str = new char[_length+1];
        strcpy(_str, str._str);
    }

    mystring &operator=(mystring &&str)
    {
        _str = str._str;
        _length = str._length;
        str._str = nullptr;
        return *this;
    }

    mystring &operator=(const char* str)
    {
        delete[] _str;
        _length = strlen(str);
        _str = new char[_length+1];
        strcpy(_str, str);
        return *this;
    }

    mystring operator+(const mystring &str)
    {
        //_str+str._str
        int len = _length+str._length+1;

        char *buf = new char[len];

        strcpy(buf, _str);
        strcat(buf, str._str);

        mystring re(buf);
        delete buf;

        return re;
    }

    mystring operator+(const char* str)const
    {
        //_str+str._str
        int len = _length+strlen(str)+1;

        char *buf = new char[len];

        strcpy(buf, _str);
        strcat(buf, str);
        mystring re(buf);
        delete buf;

        return re;
    }

    char& operator[](int index)
    {
        if(index >= 0 && index <= _length)
        {
            return _str[index];
        }
        else
        {
            throw std::out_of_range("下标不对");
            cout<<"你下标有问题";
        }
    }

    const char& operator[](int index)const
    {
        if(index >= 0 && index <= _length)
        {
            return _str[index];
        }
        else
        {
            cout<<"你下标有问题";
            throw std::out_of_range("下标不对");
        }
    }

    ~mystring()
    {
        delete [] _str;
    }

    int getLength()const
    {
        return _length;
    }

private:
    char * _str;
    int _length;

friend mystring operator+(const char*,const mystring&);


friend ostream& operator<<(ostream& o,const mystring&);
};

mystring operator+(const char* str,const mystring&str2)
{
           // _str+str._str
        int len = str2._length+strlen(str)+1;

        char *buff = new char[len];

        strcpy(buff,str);
        strcat(buff,str2._str);

        mystring re(buff);
        delete buff;

        return re;
}

int main()
{
    mystring a;
    mystring b("455455");

    mystring c("呵呵");

    mystring d = a+b+c;

    cout<<d;

    d[100] = 97;

    cout<<d;

    d = "胡椒粉和思考角度划分";

    cout<<d;

    d = "很多技术峰会结束对话"+d;

    cout<<d;
}