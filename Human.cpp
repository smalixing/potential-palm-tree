#include <iostream>
#include <cstring>
int i = 0;
int j = int(2);
class Human
{
private:
    char *name;
    int age;
    char *tel;

public:
    Human();
    ~Human();
    Human(char *n, int a, char *t) : name(n), age(a), tel(t)
    {
        ++i;
        std::cout << "----执行初始化构造方法创建对象----" << std::endl;
    }
    /*申请内存，实现赋值操作*/
    void init(const char *n, const char *t)
    {
        std::cout << "调用init申请内存空间"<< std::endl;
        std::size_t len1 = std::strlen(n) + 1;
        name = new char[len1];
        std::memcpy(name, n, len1); //填充   另一种赋值方法strcpy_s();
        std::size_t len2 = std::strlen(t) + 1;
        tel = new char[len2];
        std::memcpy(tel, t, len2); //填充
    }
    /*拷贝构造函数*/
    Human(const Human &human) noexcept
    {
        std::cout << "----执行拷贝构造方法----" << std::endl;
        age = human.age;
        init(human.name, human.tel);
    }
    /*拷贝赋值操作符*/
    Human &operator=(const Human &human) // 复制赋值
    {
        std::cout << "----执行赋值操作符重载----" << std::endl;
        if (this != &human)
        {
            if(name != nullptr)
                delete[] name; // 解分配
            if(tel != nullptr)
                delete[] tel;
            this->age = human.age;
            init(human.name, human.tel);  
        }
        return *this;
    }
    /*移动构造函数*/
    Human(Human &&s) //移动操作不应抛出任何异常
                     //成员初始化器接管s中的资源
        : name(s.name), age(s.age), tel(s.tel)
    {
        std::cout << "----执行移动拷贝构造方法----" << std::endl;
        //令s进入这样的状态一 对其运行析构函数是安全的
        s.name = s.tel = nullptr;
    }
    /*移动赋值操作符*/
    Human &operator=(Human &&rhs) noexcept
    {
        std::cout << "----执行移动赋值操作符----" << std::endl;
        //直接检测自赋值
        if (this != &rhs)
        {
            if(name != nullptr)
                delete[] name; // 解分配
            if(tel != nullptr)
                delete[] tel;
            //释放已有元素
            name = rhs.name; //从rhs接管资源
            tel = rhs.tel;
            age = rhs.age;
            //将rhs置于可析构状态
            rhs.name = rhs.tel = nullptr;
        }
        return *this;
    }
    const Human &outPut(const Human &);
};

Human::Human()
{
    std::cout << "----执行无参初始化构造方法创建对象----" << std::endl;
}

/*析构函数*/
Human::~Human()
{
    std::cout << "----执行析构方法----" << i << std::endl;
    if (name != nullptr)
        delete[] name; // 解分配
    if (tel != nullptr)
        delete[] tel;
}

/*打印信息方法*/
const Human &Human::outPut(const Human &human)
{
    std::cout << "----执行打印信息方法----" << std::endl;
    std::cout << "name: " << human.name << "  age: "
              << human.age << "  tel: " << human.tel << std::endl;
    return human;
}

int main()
{
    Human *human1 = new Human((char *)"大白兔", 6, (char *)"17554566545");
    human1->outPut(*human1);
    // delete human1;
    // human1 = nullptr;

    Human *human2 = new Human((char *)"小白兔", 2, (char *)"16483967495");
    human2->outPut(*human2);
    Human hu;
    hu.operator=(*human2);
    hu.outPut(hu);

    // delete human2;
    // human2 = nullptr;
    return 0;
}
