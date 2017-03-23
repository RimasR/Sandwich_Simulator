//702
#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

typedef int data_type;  // Pakeisti int i reikalinga duomenu tipa

struct Stack
{ 
	struct node *top;
	int exists;
};

struct node 
{
	data_type data;
	struct node *next;
};

// Funkcijos
int create (Stack* head);
// return 0 - pavyko sukurti Stack'a
// return 1 - Stack'as jau yra sukurtas
int push (Stack* head, data_type *value);
// return 0 - viskas gerai
// return 1 - Stack'as nera sukurtas
// return 2 - nepavyko isskirti atminties
int pop (Stack* head, data_type *value);
// return 0 - viskas gerai
// return 1 - Stack'as nera sukurtas
// return 2 - Stack'as tuscias 
int top (Stack* head, data_type *value);
// return 0 - viskas gerai
// return 1 - Stack'as nera sukurtas
// return 2 - Stack'as tuscias
int size (Stack* head, int *size);
// return 0 - viskas gerai
// return 1 - Stack'as nera sukurtas 
// return 2 - Stack'as tuscias
int destroy (Stack* head);
// return 0 - pavyko istrinti Stack'a
// return 1 - nepavyko istrinti Stack'o 
// return 2 - Stack'as tuscias arba jau istrintas
int empty (Stack* head);
// return 0 - Stack'as yra tuscias
// return 1 - Stack'as nera tuscias
int full_stack (Stack* head);
// return 0 - Stack'as yra pilnas
// return 1 - Stack'as nera pilnas
#endif
