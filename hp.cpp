#include<iostream>

class Air
{
public:
    inline void setTemp(float t);
    inline void setHum(int h);

    int getTemp(){return temp;};
    int getHum(){return hum;};
private:
    float temp;
    int hum;
};

int main()
{
    Air air;
    float t;
    int h;
    std::cin >> t >> h;
    air.setTemp(t);
    air.setHum(h);
    std::cout << "Temp: " <<air.getTemp() << "*C" << std::endl;
    std::cout << "Hum: " <<air.getHum() << "%" <<std::endl;   

    


}

void Air::setTemp(float t)
{
    //this->temp = t;
    temp = t;
}

void Air::setHum(int h)
{
    //this->hum = h;
    hum = h;
}