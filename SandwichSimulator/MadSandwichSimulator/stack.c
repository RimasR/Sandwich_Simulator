#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int CreateStack(Stackk* stack)
{
	*stack = (Stackk) malloc (sizeof(Stackk));
    if(*stack == NULL)
     return 0;
    (*stack)->size=0;
    (*stack)->status=1;    
    (*stack)->head=NULL;
    return 1;
}

int PushElement(Stackk stack, TYPE x)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;
    LIST temp = (LIST) malloc (sizeof(LIST));
    if (temp==NULL)
        return 0;
    else
    {
        if (stack->head == NULL)
        {
            temp->data = x;
            temp->next = NULL;
            stack->head = temp;
        }
        else
        {
            temp->data = x;
            temp->next = stack->head;
            stack->head = temp;
        }
        stack->size++;
        return 1;
    }
}

int PopElement(Stackk stack, TYPE *x)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;
    LIST temp = stack->head;
    *x=temp->data;
    stack->head=temp->next;
    free(temp);
    stack->size--;
    return 1;
}

int CheckIfEmpty(Stackk stack)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;
    if(stack->head==NULL)
        return 1;
    else
        return 0;
}

int Print(Stackk stack)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;

    LIST temp = stack->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 1;
}

int FreeMemory(Stackk* stack)
{
    if((*stack)==NULL)
        return -1;
    if((*stack)->status!=1)
        return -1;
    
    if ((*stack)->head==NULL)
    {
        free(*stack);
        *stack = NULL;
        return 1;
    }

    LIST mem=(*stack)->head;
    (*stack)->head=(*stack)->head->next;

    while ((*stack)->head!=NULL)
    {
        free(mem);
        mem=(*stack)->head;
        (*stack)->head=(*stack)->head->next;
    }

    free(*stack);
    *stack=NULL;
    return 1;
}

int CheckIfFull(Stackk stack)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;

    LIST temp = (LIST)malloc(sizeof(LIST));
    if (temp==NULL)
        return 1;
    else
        free(temp);
        return 0;
}

int SizeOfStack (Stackk stack)
{
    if(stack==NULL)
        return -1;
    if(stack->status!=1)
        return -1;

    return stack->size;
}