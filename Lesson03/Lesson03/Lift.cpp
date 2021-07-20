#include "Lift.h"
#include "LiftState.h"

void Lift::setMaxPeople(int maxPeople) {
	if (maxPeople > 0)
		this->maxPeople = maxPeople;
	else
		this->maxPeople = 1;
}

void Lift::setMaxFloors(int maxFloors) {
	if (maxFloors > 1)
		this->maxFloors = maxFloors;
	else
		this->maxFloors = 2;
}

int Lift::getMaxPeople() {
	return this->maxPeople;
}

int Lift::getMaxFloors() {
	return this->maxFloors;
}

int Lift::getCurrentFloor() {
	return this->currentFloor;
}
int Lift::getCurrentPeople() {
	return this->currentPeople;
}
LiftState Lift::getCurrentState() {
	return this->currentState;
}
bool Lift::getIsClose() {
	return this->isClose;
}

Lift::Lift() {
	this->maxPeople = 1;
	this->maxFloors = 2;
	this->currentFloor = 0;
	this->currentPeople = 0;
	this->currentState = LiftState::STOP;
	this->isClose = true;
}

Lift::Lift(int maxPeople) : Lift::Lift() {
	this->setMaxPeople(maxPeople);
}

Lift::Lift(int maxPeople, int maxFloors) : Lift::Lift(maxPeople) {
	this->setMaxFloors(maxFloors);
}

Lift::Lift(int maxPeople, int maxFloors, int currentFloor) : Lift::Lift(maxPeople, maxFloors) {
	if (currentFloor <= maxFloors)
		this->currentFloor = currentFloor;
	else
		this->currentFloor = maxFloors;
}

void Lift::enter(int people) {
	if (!this->isClose)
		this->currentFloor += people;
}

void Lift::getOff(int people) {
	if (people <= this->currentPeople && !this->isClose)
		this->currentFloor -= people;
}

void Lift::switchDoorLift() {
	this->isClose = !this->isClose;
}

void Lift::openDoorLift() {
	if (this->isClose && this->currentState == LiftState::STOP)
		this->isClose = false;
}

void Lift::closeDoorLift() {
	if (!this->isClose && this->currentState == LiftState::STOP)
		this->isClose = true;
}

void Lift::move(int floor) {
	if (this->isClose && floor >= 0 && floor <= this->maxFloors && this->currentPeople <= this->maxPeople) {
		if (floor < this->currentFloor) {
			this->currentState = LiftState::MOVE_DOWN;
			while (this->currentFloor != floor)
			{
				this->currentFloor--;
			}
		}
		else {
			this->currentState = LiftState::MOVE_UP;
			while (this->currentFloor != floor)
			{
				this->currentFloor++;
			}
		}
		this->currentState = LiftState::STOP;
	}
}