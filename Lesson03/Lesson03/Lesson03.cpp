// Lesson03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lift.h"

int main()
{
    Lift* lift = new Lift(10, 30);
    lift->openDoorLift();
    lift->enter(20);
    std::cout << lift->getCurrentPeople() << std::endl;
    lift->closeDoorLift();
    lift->move(28);
    lift->openDoorLift();
    lift->getOff(4);
    lift->closeDoorLift();
    lift->move(2);
    lift->openDoorLift();
    lift->getOff(5);
    std::cout << lift->getCurrentFloor() << std::endl;
}
