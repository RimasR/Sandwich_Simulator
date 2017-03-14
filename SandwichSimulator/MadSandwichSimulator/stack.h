/*Dovilė Makselytė 2 grupė, 1 pogrupis*/

#ifndef stackh
#define stackh

typedef int TYPE; //Steko elementų tipas.

typedef struct Nodee
{
	TYPE data;
	struct Nodee* next;
}*LIST;

typedef struct Stack
{
	LIST head;
	int size;
	int status;
}*Stackk;

int CreateStack(Stackk* stack);//Funkcija sukuria steką. Jeigu nepavyko sukurti steko - grąžina klaidos kodą "0", jei pavyko - "1".
int PushElement(Stackk stack, TYPE x);//Įterpia elemnentą į steką. Jeigu stekas pilnas, funkcija grąžina klaidos kodą "0", jeigu ne - "1",
									 //jeigu stekas nesukurtas - "-1";
int PopElement(Stackk stack, TYPE *x);//Išima elementą iš steko. Jeigu stekas tuščias, funkcija grąžina klaidos kodą "0", jeigu ne - "1",
									 //o jeigu stekas nesukurtas - "-1";
int CheckIfEmpty(Stackk stack);//Tikrina ar stekas yra tuščias. Jeigu ne, tai grąžina klaidos kodą "0", jeigu pilnas - "1", o
									 //jeigu stekas nesukurtas - "-1";
int Print(Stackk stack);//Atspausdina steko elementus į ekraną. Jeigu stekas nesukurtas grąžina "-1".
int FreeMemory(Stackk* stack);//Funkcija panaikina steką. Jeigu steką panaikinti pavyko grąžina "1", o jeigu stekas nesukurtas - "-1";
int CheckIfFull(Stackk stack);//Funkcija tikrina, ar stekas yra pilnas. Jeigu stekas tuščias grąžina klaidos kodą "0", jeigu ne - "1",
									 //jeigu stekas nesukurtas - "-1"; 
int SizeOfStack (Stackk stack);//Funkcija grąžina steko dydžio reikšmę. Jeigu stekas nesukurtas grąžina "-1".

#endif
