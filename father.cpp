#include <iostream>
#include <string>

class father
{
public:
    //father(std::string fname):name(fname){}
    std::string getFName(){return name;}

    void setFName(std::string fname)
    {
        name = fname;
    }

protected:
    std::string name;

private:
    std::string name2;
};

class son:public father
{
public:
    std::string getInson(){return this->getFName();}
    //son(std::string name):father(name){}
};

int main()
{
    son xiaoming;

    xiaoming.setFName("小明");

    std::cout<<xiaoming.getFName();

}