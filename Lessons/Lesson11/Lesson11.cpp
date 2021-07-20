// Lesson11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Character {
private:
    int points;
protected:
    int hp;
    int damage;
    int speed;
    int is_dead{false};
public:
    Character(int points)
    {
        this->points = points;
        std::cout << "ctor Character!\n";
    }
    virtual void attack() {
        //c.hp -= this->damage;
        std::cout << "attack one player from Character!\n";
        isDead();
    }
    void isDead() {
        if (hp <= 0)
            is_dead = true;
    }
    virtual ~Character()
    {
        std::cout << "~ Character!\n";
    }
};
class Shooter : public Character {
protected:
    int ammo;
public:
    Shooter() : Character{ 12 }
    {
        std::cout << "ctor Shooter!\n";
    }
    void attack() override {
        //c.hp -= this->damage;
        std::cout << "attack one player from Shooter!\n";
        isDead();
    }
    ~Shooter()
    {
        attack();
        std::cout << "~ Shooter!\n";
    }
};

class Archer final : public Shooter {
private:
    int type_arrow;
public:
    Archer()
    {
        std::cout << "ctor Archer!\n";
    }
    void attack() override {
        //c.hp -= this->damage;
        std::cout << "attack one player from Archer!\n";
        isDead();
    }
    ~Archer()
    {
        std::cout << "~ Archer!\n";
    }
    void shot(Character& c) {
        Character::attack();
        ammo--;
    }
};

class Gunsmith final : public Shooter {
private:
    int ammo2{0};
public:
    Gunsmith()
    {
        std::cout << "ctor Gunsmith!\n";
    }
    void attack() override {
        //c.hp -= this->damage;
        std::cout << "attack one player from Gunsmith!\n";
        isDead();
    }
    ~Gunsmith()
    {
        std::cout << "~ Gunsmith!\n";
    }
    void shoot(Character& c) {
        Character::attack();
        ammo--;
        ammo2--;
        std::cout << ammo2 << std::endl;
    }
};

class Weapon {
public:
    /*virtual void fire() {
        std::cout << "some weapon!\n";
    }*/
    void hello() {
        std::cout << "hello form weapon!\n";
    }
    virtual ~Weapon()
    {
        hello();
    }
};

class Sword : public Weapon {
public:
    /*void fire() override {
        std::cout << "attack Sword!\n";
    }*/
    void hello() {
        std::cout << "hello form sword!\n";
    }
    ~Sword()
    {
        hello();
    }
};

class Rifle : public Weapon {
public:
    /*void fire() override {
        std::cout << "shoot Rifle!\n";
    }*/
    void hello() {
        std::cout << "hello form rifle!\n";
    }
    ~Rifle()
    {
        hello();
    }
};

class Bow : public Weapon {
public:
    /*void fire() override {
        std::cout << "shoot Bow!\n";
    }*/
};

class Rectangle {
protected:
    int a;
    int b;
public:
    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int getArea() {
        return a * b;
    }
    virtual void setA(int a) {
        this->a = a;
    }
    virtual void setB(int b) {
        this->b = b;
    }
};

class Squeare : public Rectangle {
public:
    Squeare(int a) : Rectangle{ a, a }{}
    void setA(int a) override {
        this->a = a;
        this->b = a;
    }
    void setB(int b) override {
        this->b = b;
        this->a = b;
    }
};

class Animal {
public:
    virtual void walk() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    void live() {
        walk();
        eat();
        sleep();
    }
    virtual ~Animal()
    {
        walk();
        eat();
        sleep();
    }
};

class Rabbit : public Animal {
public:
    virtual void walk() override {
        std::cout << "jump around" << std::endl;
    }
    virtual void eat() override {
        std::cout << "eat grass" << std::endl;
    }
    virtual void sleep() override {
        std::cout << "sleep in hole" << std::endl;
    }
    int a = 12;
    virtual ~Rabbit()
    {
        walk();
        eat();
        sleep();
    }
};

class Lion : public Animal {
    virtual void walk() override {
        std::cout << "run around" << std::endl;
    }
    virtual void eat() override {
        std::cout << "eat meat" << std::endl;
    }
    virtual void sleep() override {
        std::cout << "sleep under tree" << std::endl;
    }
};

class A {
public:
    int a = 12;
    virtual ~A()
    {

    }
    void show() {
        std::cout << "hello A" << std::endl;
    }
};

class B : public A {
public:
    void show() {
        std::cout << "hello B" << std::endl;
    }
};

class C : public A {
public:
    void show() {
        std::cout << "hello C" << std::endl;
    }
};

//class A {
//public:
//    int a = 12;
//    A()
//    {
//        std::cout << "ctor A" << std::endl;
//    }
//    ~A()
//    {
//        std::cout << "~ A" << std::endl;
//    }
//};
//
//class B {
//public:
//    int a = 15;
//    B()
//    {
//        std::cout << "ctor B" << std::endl;
//    }
//    ~B()
//    {
//        std::cout << "~ B" << std::endl;
//    }
//};
//
//class C : public A, public B {
//public:
//    int a = 17;
//    C()
//    {
//        //B::a;
//        std::cout << "ctor C" << std::endl;
//    }
//    ~C()
//    {
//        std::cout << "~ C" << std::endl;
//    }
//};

//class A {
//public:
//    int a = 12;
//};
//
//class B : virtual public A {
//public:
//    B() {}
//};
//
//class C : virtual public A {
//public:
//    C() {}
//};
//
//class D : public B, public C {};

class ICamera {
public:
    ICamera()
    {
        std::cout << "ctor ICamera" << std::endl;
    }
    virtual void takePhoto() = 0;
    virtual ~ICamera() {
        std::cout << "~ ICamera" << std::endl;
    }
};

class Iphone : public ICamera {
public:
    Iphone()
    {
        std::cout << "ctor Iphone" << std::endl;
    }
    virtual void takePhoto() override {
        std::cout << "take photo from Iphone" << std::endl;
    }
    ~Iphone()
    {
        std::cout << "~ Ihpone" << std::endl;
    }
};

class Nikon : public ICamera {
public:
    Nikon()
    {
        std::cout << "ctor Nikon" << std::endl;
    }
    virtual void takePhoto() override {
        std::cout << "take photo from Nikon" << std::endl;
    }
    ~Nikon()
    {
        std::cout << "~ Nikon" << std::endl;
    }
};

class Photographer {
public:
    char* name;
    Photographer(const char* name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }
    void makePhoto(ICamera* ic) {
        std::cout << name << ' ';
        ic->takePhoto();
    }
};

int main()
{
    //Weapon** inventory = new Weapon*[12];
    //Weapon* inventory[3];
    //inventory[0] = new Sword();
    //inventory[1] = new Rifle();
    //inventory[2] = new Bow();
    //for (size_t i = 0; i < 3; i++)
    //{
    //    //inventory[i]->fire();
    //}
    //delete inventory[0];
    //Rectangle* r = new Squeare{12};
    //r->setB(12);
    //std::cout << r->getArea() << std::endl;
    //Animal* a = new Rabbit();
    ////a->live();
    //delete a;
    A* a1 = new B;
    B* b1 = dynamic_cast<B*>(a1);
    C* c1 = dynamic_cast<C*>(a1);

    B* b2 = new B;
    A* a2 = dynamic_cast<A*>(b2);
    C* c2 = dynamic_cast<C*>(a2);
    if (c2)
        std::cout << "hello" << std::endl;
    /*C c;
    std::cout << c.A::a << std::endl;*/

    //D d;
    //d.C::A::a = 1;
    //std::cout << d.B::A::a << std::endl;

    //B b;
    //C c;
    //c.A::a = 1;
    //std::cout << c.A::a << std::endl;
    //std::cout << b.A::a << std::endl;

    /*ICamera* c = new Iphone;
    Photographer p{"Alex"};
    p.makePhoto(c);*/
}