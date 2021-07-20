// Lesson13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>

using std::string;

class Car;
class User;

class User {
public:
    string name;
    std::weak_ptr<User> firend;
    std::weak_ptr<Car> car;
    User(string name)
    {
        this->name = name;
    }
    ~User()
    {
        std::cout << "~ " << name << std::endl;
    }
    friend void make_friendship(std::shared_ptr<User> &u1, std::shared_ptr<User> &u2) {
        u1->firend = u2;
        u2->firend = u1;
    }
    //void get_into_car(std::shared_ptr<Car> &c) {
    //    this->car = c;
    //    c->driver = shared_from_this();
    //}
    friend class Car;
    //friend void seat_in_car(std::shared_ptr<User>&, std::shared_ptr<Car>&);
};

class Car : public std::enable_shared_from_this<Car> {
public:
    std::weak_ptr<User> driver;
    void seat(std::shared_ptr<User> &u) {
        this->driver = u;
        //u->get_into_car(shared_from_this());
        //u->car = std::shared_ptr<Car>(this);
        u->car = shared_from_this();
    }
    ~Car()
    {
        std::cout << "~ Car" << std::endl;
    }
    //friend void seat_in_car(std::shared_ptr<User>&, std::shared_ptr<Car>&);
};

//void seat_in_car(std::shared_ptr<User> &u, std::shared_ptr<Car> &c) {
//    u->car = c;
//    c->driver = u;
//}

void show(std::unique_ptr<User> u) {
    std::cout << u->name << std::endl;
}

void show(std::shared_ptr<User> u) {
    std::cout << u->name << std::endl;
}

int main()
{
    /*const char* str = "hello";
    int i = reinterpret_cast<int>(str);
    char* str2 = const_cast<char*>(str);
    std::cout << i << std::endl;*/
    /*std::unique_ptr<User> pu = std::make_unique<User>();
    std::unique_ptr<User> pu2 = std::move(pu);
    show(pu2);*/
    //std::cout << pu->name << std::endl;
    /*std::shared_ptr<User> pu = std::make_shared<User>("hello");
    std::shared_ptr<User> pu2 = pu;
    pu2->name = "asd";
    std::cout << pu->name << std::endl;*/

    //std::unique_ptr<User> pu = std::make_unique<User>("hello");
    //show(std::move(pu));
    //std::cout << pu->name << std::endl;

    /*std::shared_ptr<User> pu1 = std::make_shared<User>("User1");
    std::shared_ptr<User> wpu1 = pu1;
    pu1.reset();
    std::cout << wpu1->name << std::endl;*/

    /*std::shared_ptr<User> pu2 = std::make_shared<User>("User2");
    std::shared_ptr<User> pu4 = std::const_pointer_cast<User>(pu2);
    make_friendship(pu1, pu2);
    std::cout << pu1->firend.lock()->name << std::endl;*/
    //show(pu);
    //std::cout << pu->name << std::endl;

    std::shared_ptr<User> pu1 = std::make_shared<User>("User1");
    std::shared_ptr<Car> pc1 = std::make_shared<Car>();
    pc1->seat(pu1);
}
