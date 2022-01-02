#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Vehicle
{
private:
   int wheels;
   string name;
   
public:
    Vehicle() = delete;
    Vehicle(int w, const string& n):wheels(w),
                                        name(n)
    {}
    void run(){
       cout << name << " is running on " << wheels << " wheels" << endl;
    }
    const string& getname() const
    {
        return name;
    }
};

class Car : public Vehicle 
{
public:
   Car():Vehicle(4, "car"){}
};

class Scooter : public Vehicle 
{
public:
   Scooter():Vehicle(2, "scooter"){}
};

unique_ptr<Vehicle> getVehicle(int type)
{
    unique_ptr<Vehicle> ptr1(nullptr);
    switch(type){
        case 0:
            ptr1.reset(new Car);
            break;
        case 1:
            ptr1.reset(new Scooter);
            break;  
        case 2:
            ptr1.reset(new Vehicle(0, "vehicle"));
            break;
    }
    return ptr1;
}

int main()
{
    auto ptr1 = getVehicle(0);
    ptr1->run();
    
    auto ptr2 = getVehicle(1);
    ptr2->run();
    
    auto ptr3 = getVehicle(2);
    ptr3->run();
}
