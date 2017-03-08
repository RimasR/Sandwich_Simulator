/*Dovilė Makselytė 2 grupė, 1 pogrupis*/

#ifndef stackh
#define stackh

typedef int TYPE; //Steko elementų tipas.

typedef struct Node
{
	TYPE data;
	struct Node* next;
}*LIST;

typedef struct Stack
{
	LIST head;
	int size;
	int status;
}*Stack;

int CreateStack(Stack* stack);//Funkcija sukuria steką. Jeigu nepavyko sukurti steko - grąžina klaidos kodą "0", jei pavyko - "1".
int PushElement(Stack stack, TYPE x);//Įterpia elemnentą į steką. Jeigu stekas pilnas, funkcija grąžina klaidos kodą "0", jeigu ne - "1",
									 //jeigu stekas nesukurtas - "-1";
int PopElement(Stack stack, TYPE *x);//Išima elementą iš steko. Jeigu stekas tuščias, funkcija grąžina klaidos kodą "0", jeigu ne - "1",
									 //o jeigu stekas nesukurtas - "-1";
int CheckIfEmpty(Stack stack);//Tikrina ar stekas yra tuščias. Jeigu ne, tai grąžina klaidos kodą "0", jeigu pilnas - "1", o
									 //jeigu stekas nesukurtas - "-1";
int Print(Stack stack);//Atspausdina steko elementus į ekraną. Jeigu stekas nesukurtas grąžina "-1".
int FreeMemory(Stack* stack);//Funkcija panaikina steką. Jeigu steką panaikinti pavyko grąžina "1", o jeigu stekas nesukurtas - "-1";
int CheckIfFull(Stack stack);//Funkcija tikrina, ar stekas yra pilnas. Jeigu stekas tuščias grąžina klaidos kodą "0", jeigu ne - "1",
									 //jeigu stekas nesukurtas - "-1"; 
int SizeOfStack (Stack stack);//Funkcija grąžina steko dydžio reikšmę. Jeigu stekas nesukurtas grąžina "-1".

#endif
