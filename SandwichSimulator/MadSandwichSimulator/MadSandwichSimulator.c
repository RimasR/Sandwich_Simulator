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
#include <stdbool.h>

Queue* queueNew1;
Queue* queueNew2;
Stack stackOld1;
Stack stackOld2;
int price;


int main()
{
	int simulateTime = 0;
	int currTime = 0;
	int probOfClient = 0;
	int sandwichCount = 0;
	int newSandwichPeriod =0;
	int timeToThrow = 0;
	price = 0;
	int workHours = 0;
	int sumOld = 0;
	int sumNew = 0;
	int loseOld = 0;
	int loseNew = 0;
	int boxCount = 0;
	int temp = 0;

	queueNew1 = CreateQueue();
	queueNew2 = CreateQueue();
	create(&stackOld1);
	create(&stackOld2);

	ReadFromFile(&simulateTime, &probOfClient, &sandwichCount, &newSandwichPeriod, &timeToThrow, &workHours, &price);

	//MAIN LOOP
	for (currTime = 0; currTime < simulateTime; currTime++) 
    {
		if ((currTime % newSandwichPeriod) == 0)
		{
			AddToOldSolution(currTime, sandwichCount);
			AddToNewSolution(currTime, sandwichCount);
		}

		srand(time(NULL));
		int random = rand() % 100;
		if(random <= probOfClient)
		{
			if(TakeFromOldSolution())
			{
				sumOld += price; 
				printf("Client bought a sandwich! Money earned so far on old solution: %d\r\n", sumOld);
			}
			if (TakeFromNewSolution())
			{
				sumNew += price;
				printf("Client bought a sandwich! Money earned so far on new solution: %d\r\n", sumNew);
			}
		}

		if((currTime != 0) && ((currTime % workHours) == 0))
		{
			CleanOldSolution(currTime, &loseOld, timeToThrow);
			printf("Money got from old solution: %d, money spent: %d\r\n", sumOld, loseOld);
			CleanNewSolution(currTime, &loseNew, timeToThrow);
			printf("Money got from new solution: %d, money spent: %d\r\n", sumNew, loseOld);
		}
	}

	printf("Total money balance on old solution: %d\r\n", sumOld - loseOld);
	printf("Total money balance on new solution: %d\r\n", sumNew - loseNew);

}

void ReadFromFile(int * simulateTime, int * probOfClient, int * sandwichCount, int * newSandwichPeriod, int * timeToThrow, int* workHours, int * price)
{
	FILE *fp;
	fopen_s(&fp, "solution.txt", "r");

	if(fp == NULL)
	{
		printf("File not found. Simulation will not be initialized.");
		exit(0);
	}

	*simulateTime = GetIntFromFile(fp);
	*probOfClient = GetIntFromFile(fp);
	*sandwichCount = GetIntFromFile(fp);
	*newSandwichPeriod = GetIntFromFile(fp);
	*timeToThrow = GetIntFromFile(fp);
	*workHours = GetIntFromFile(fp);
	*price = GetIntFromFile(fp);
}

int GetIntFromFile(FILE * fp)
{
	const size_t line_size = 300;
	char* line = malloc(line_size);
	fgets(line, line_size, fp);
	for (int i = 0; line[i] != 00; i++)
	{
		if (line[i] == '/')
		{
			line[i] = 00;
			break;
		}
	}
	printf("%s ",line);
	
	return atoi(line);
}

int TakeFromOldSolution()
{
	int sandwichTime = 0;
	if(rand()%100 <= 50)
	{
		if(pop(&stackOld1, &sandwichTime) == 2)
		{
			if (pop(&stackOld2, &sandwichTime) == 2)
			{
				printf("No sandwiches in stacks :(\r\n");
				return 0;
			}
			return 1;
		}
		return 1;
	}
	else
	{
		if (pop(&stackOld2, &sandwichTime) == 2)
		{
			if (pop(&stackOld1, &sandwichTime) == 2)
			{
				printf("No sandwiches in stacks :(\r\n");
				return 0;
			}
			return 1;
		}
		return 1;
	}
	return 0;
}

int TakeFromNewSolution()
{
	int sandwichTime = 0;
	if (rand() % 100 <= 50)
	{
		if(Dequeue(queueNew1, &sandwichTime) == 2)
		{
			if(Dequeue(queueNew2, &sandwichTime) == 2)
			{
				printf("No sandwiches in queues :(\r\n");
				return 0;
			}
			return 1;
		}
		return 1;
	}
	else
	{
		if (Dequeue(queueNew2, &sandwichTime) == 2)
		{
			if (Dequeue(queueNew1, &sandwichTime) == 2)
			{
				printf("No sandwiches in queues :(\r\n");
				return 0;
			}
			return 1;
		}
		return 1;
	}
	return 0;
}

void AddToOldSolution(int currTime, int sandwichCount)
{
	int size1 = 0;
	int size2 = 0;
	size(&stackOld1, &size1);
	size(&stackOld2, &size2);

	if(size1 >= size2)
	{
		for(int i = 0; i < sandwichCount; i++ )
		{
			printf("Adding new sandwich to old solution 2\r\n");
			push(&stackOld2, &currTime);
		}
	}
	else
	{
		for (int i = 0; i < sandwichCount; i++)
		{
			printf("Adding new sandwich to old solution 1\r\n");
			push(&stackOld1, &currTime);
		}
	}

}
void AddToNewSolution(int currTime, int sandwichCount)
{
	int size1 = 0;
	int size2 = 0;
	size1 = QueueLength(queueNew1);
	size2 = QueueLength(queueNew2);

	if (size1 >= size2)
	{
		for (int i = 0; i < sandwichCount; i++)
		{
			printf("Adding new sandwich to new solution 2\r\n");
			Enqueue(queueNew2, currTime);
		}
	}
	else
	{
		for (int i = 0; i < sandwichCount; i++)
		{
			printf("Adding new sandwich to new solution 1\r\n");
			Enqueue(queueNew1, currTime);
		}
	}
}

void CleanOldSolution(int currTime, int* lose, int timeToThrow)
{
	Stack tempStack;
	create(&tempStack);
	int temp;


	// CLEAN FIRST BOX
	int sandwichTime = 0;
	if (empty(&stackOld1)) {
		while (pop(&stackOld1, &sandwichTime) != 2)
		{
			push(&tempStack, &sandwichTime);
		}

		temp = top(&tempStack, &sandwichTime);

		while ((temp != 2) && (currTime - sandwichTime > timeToThrow))
		{
			printf("Removing old sandwich from old solution 1\r\n");
			pop(&tempStack, &sandwichTime);
			*lose += price;
			temp = top(&tempStack, &sandwichTime);
		}
		while (pop(&tempStack, &sandwichTime) != 2)
		{
			push(&stackOld1, &sandwichTime);
		}
	}

	// CLEAN SECOND BOX
	if (empty(&stackOld2)) {
		while (pop(&stackOld2, &sandwichTime) != 2)
		{
			push(&tempStack, &sandwichTime);
		}

		temp = top(&tempStack, &sandwichTime);

		while ((temp != 2) && (currTime - sandwichTime > timeToThrow))
		{
			printf("Removing old sandwich from old solution 2\r\n");
			pop(&tempStack, &sandwichTime);
			*lose += price;
			temp = top(&tempStack, &sandwichTime);
		}
		while (pop(&tempStack, &sandwichTime) != 2)
		{
			push(&stackOld2, &sandwichTime);
		}
	}
}

void CleanNewSolution(int currTime, int *lose, int timeToThrow)
{
	int sandwichTime = 0;
	int temp = 0;
	if (!IsQueueEmpty(queueNew1)) {
		temp = QueuePeek(queueNew1, &sandwichTime);
		while ((temp != 2) && currTime - sandwichTime > timeToThrow)
		{
			printf("Removing old sandwich from new solution 1\r\n");
			Dequeue(queueNew1, &sandwichTime);
			*lose += price;
			temp = QueuePeek(queueNew1, &sandwichTime);
		}
	}

	if (!IsQueueEmpty(queueNew2)) {
		temp = QueuePeek(queueNew2, &sandwichTime);
		while ((temp != 2) && currTime - sandwichTime > timeToThrow)
		{
			printf("Removing old sandwich from new solution 2\r\n");
			Dequeue(queueNew2, &sandwichTime);
			*lose += price;
			temp = QueuePeek(queueNew2, &sandwichTime);
		}
	}
}

