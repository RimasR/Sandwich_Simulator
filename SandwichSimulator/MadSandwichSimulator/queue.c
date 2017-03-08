#include "queue.h"
#include <stdlib.h>

Queue * CreateQueue()
{
    Queue *queue = malloc(sizeof(Queue));
	if (queue == NULL)
		return NULL;
    queue->first = NULL;
	queue->status = QUEUE_INITIALISED;
    return queue;
}

bool IsQueueEmpty(Queue *queue)
{
    return (!IsQueueInitialised(queue) || queue->first == NULL);
}

bool IsQueueFull(Queue *queue)
{
    Node *node = malloc(sizeof(Node));
    if (node != NULL)
    {
        free(node);
        return true;
    }
    else
        return false;
}

int Enqueue(Queue *queue, QueueElement element)
{
	if (!IsQueueInitialised(queue))
		return 1;
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return 2;
    newNode->element = element;
    newNode->next = NULL;

    if (IsQueueEmpty(queue))
        queue->first = newNode;
    else
    {
        Node *node = queue->first;    
        while (node->next != NULL)
            node = node->next;
        node->next = newNode;
    }
    return 0;
}

//Grazina false jei eile tuscia
int Dequeue(Queue *queue, QueueElement *element)
{
	if (!IsQueueInitialised(queue))
		return 1;
    if (IsQueueEmpty(queue))
        return 2;
    *element = queue->first->element;
    Node *newFirst = queue->first->next;
    free(queue->first);
    queue->first = newFirst;
    return 0;
}
//Grazinamas pirmas elementas neisimant jo is eiles
int QueuePeek(Queue *queue, QueueElement *element)
{
	if (!IsQueueInitialised(queue))
		return 1;
    if (IsQueueEmpty(queue))
        return 2;
    *element = queue->first->element;
    return 0;
}

int QueueLength(Queue *queue)
{
    if (!IsQueueInitialised(queue))
        return -1;
    Node *node = queue->first;
    int count = 0;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }
    return count;
}

int DeleteQueue(Queue *queue)
{
    if (!IsQueueInitialised(queue))
        return 1;
    Node *node = queue->first;
    while (node != NULL)
    {
        Node *next = node->next;
        free(node);
        node = next;
    }
    free(queue);
	return 0;
}
bool IsQueueInitialised(Queue *queue)
{
	return (queue != NULL && queue->status == QUEUE_INITIALISED);
}
