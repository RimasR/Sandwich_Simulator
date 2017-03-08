//Tadas Vaitiekunas 5.2
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

#define QUEUE_INITIALISED 1

typedef int QueueElement;

typedef struct QueueNode
{
    QueueElement element;
    struct QueueNode *next;
} Node;

typedef struct TQueue
{
    Node *first;
	int status;   
} Queue;

//returns NULL if failed to create
Queue * CreateQueue(); 
bool IsQueueEmpty(Queue *queue);
bool IsQueueFull(Queue *queue);

//returns 0 if operation succesfull
//1 - if queue is not initialised
//2 - if failed to allocate space for new object in queue
int Enqueue(Queue *queue, QueueElement element);
//1 - if queue is not initialised
//2 - if passed queue is empty
int Dequeue(Queue *queue, QueueElement *element);

//returns first element withouht taking it out
int QueuePeek(Queue *queue, QueueElement *element);

//returns -1 if queue is not initialised
int QueueLength(Queue *queue);
//returns 1 if queue not initialised
int DeleteQueue(Queue *queue);
bool IsQueueInitialised(Queue *queue);

#endif //QUEUE_H_
