#ifndef SWSIM
#define SWSIM

#define typename(x) _Generic(x), \
	TQueue: "Queue", \
	Stack: "Stack", \
	default: "other" )

void AddSandwichesToBox(int sandwichCount, int currTime, int boxCount);
void TakeSandwichFromBox();
int PeekFirstSandwichInBox();

#endif
