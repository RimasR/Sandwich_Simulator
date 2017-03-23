#ifndef SWSIM
#define SWSIM
void ReadFromFile(int* simulateTime,int* probOfClient,int* sandwichCount,int* newSandwichPeriod,int* timeToThrow, int* workHours, int* price);
int GetIntFromFile(FILE *fp);
// 0 - no sandwich :(
// 1 - got sandwich :)
int TakeFromOldSolution();
// 0 - no sandwich :(
// 1 - got sandwich :)
int TakeFromNewSolution();
void AddToOldSolution(int currTime, int sandwichCount);
void AddToNewSolution(int currTime, int sandwichCount);
void CleanOldSolution(int currTime, int* lose, int timeToThrow);
void CleanNewSolution(int currTime, int* lose, int timeToThrow);

#endif
