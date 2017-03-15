// MadSandwichSimulator.cpp : Defines the entry point for the console application.
// Add multiple box support
// Add Stack/queue management.
// Add error handling.

#include "stdafx.h"
#include "stack.h"
#include "queue.h"
#include "MadSandwichSimulator.h"
#include <stdlib.h>
#include <time.h>

Queue* box;

int main()
{
	int currTime = 0;
	int probOfClient = 50;
	int sandwichCount = 5;
	int newSandwichPeriod = 1;
	int timeToThrow = 1;
	int price = 5;
	int workHours = 8;
	int sum = 0;
	int lose = 0;
	int boxCount = 0;
	box = CreateQueue();
	

	AddSandwichesToBox(sandwichCount, currTime, boxCount);
	for (currTime = 0; currTime < workHours; currTime++) 
    {
		srand(time(NULL));
		int random = rand() % 100;
		if(random < probOfClient)
		{
			TakeSandwichFromBox();
			sum += price;
		}

		if ((currTime % newSandwichPeriod) == 0) 
		{
			AddSandwichesToBox(sandwichCount, currTime, boxCount);
		}
	}

	int sandwichTime = PeekFirstSandwichInBox();
	while(workHours - sandwichTime > timeToThrow)
	{
		Dequeue(box, &sandwichTime);
		lose += price;
		sandwichTime = PeekFirstSandwichInBox();
	}

	printf("Money got: %d, money spent: %d", sum, lose);

}

void AddSandwichesToBox(int sandwichCount, int currTime, int boxCount)
{
	srand(time(NULL));
	int random = rand() % 2 + 1;

	for (int i = 0; i < sandwichCount; i++)
	{
		Enqueue(box, currTime);
	}
}

void TakeSandwichFromBox()
{
	int sandwichTime;
	int returnCode = Dequeue(box, &sandwichTime);
}

int PeekFirstSandwichInBox()
{
	int sandwichTime = 0;
	int returnCode = QueuePeek(box, &sandwichTime);
	return sandwichTime;
}
