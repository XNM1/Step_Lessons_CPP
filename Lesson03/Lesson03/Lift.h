#pragma once
#include "LiftState.h"

class Lift
{
private:
	int maxPeople;
	int maxFloors;

	int currentFloor;
	int currentPeople;
	LiftState currentState;
	bool isClose;

private:
	void setMaxPeople(int);
	void setMaxFloors(int);

public:
	int getMaxPeople();
	int getMaxFloors();

	int getCurrentFloor();
	int getCurrentPeople();
	LiftState getCurrentState();
	bool getIsClose();

	Lift();
	Lift(int);
	Lift(int, int);
	Lift(int, int, int);

	void enter(int);
	void getOff(int);
	void switchDoorLift();
	void openDoorLift();
	void closeDoorLift();
	void move(int);
};
