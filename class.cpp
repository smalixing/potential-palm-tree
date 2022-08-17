#include<iostream>
class snake
{   
public:
    snake(){std::cout << "初始化snake" << std::endl;}
    snake(int a){std::cout << "初始化snake" << std::endl;setlen(a);}
    ~snake(){std::cout << "结束"  << std::endl;}
    snake(snake &);
    inline void setlen(int);
    inline void changelen(int);
    int getlen()const;
    void lastpoints()const;
    void setname();
    void setscore(int);
    
private:
    int len;
    int hp;
    char *username;
    int score;
};
snake &getpoint(snake &p);
int main()
{
    snake sk(10);
    sk.setname();
    sk.setlen(10);
    sk.getlen();
    sk.changelen(15);
    sk.getlen();
    getpoint(sk);
    sk.lastpoints();
}

snake &getpoint(snake &p)
{
    p.setscore(p.getlen()*10);
    return p;
}

void snake::setscore(int a)
{
    this->score = a;
}

void snake::lastpoints()const
{
    std::cout << this->username <<":"<< this->score << "points" << std::endl;

}

void snake::setname()
{
    std::cout << "请输入username:";
    std::cin >> this->username;
}

void snake::setlen(int l)
{
    len = l;
}

void snake::changelen(int a)
{
    len += a;
}

int snake::getlen()const
{
    std::cout << "snake len: " <<len << std::endl;
    return len;
}