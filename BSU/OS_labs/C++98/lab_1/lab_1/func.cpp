#include "func.h"
mymass::mymass()
{
	Mass = NULL;
	Count = 0;
	NumberOf5 = 0;
};
mymass::mymass(int* array, int count, int numberof5)
{
	Mass = array;
	Count = count;
	NumberOf5 = numberof5;
};
void FuncWroker(mymass* my)
{
	my->NumberOf5 = 0;
	for (int i = 0; i < my->Count; i++)
	{
		if (my->Mass[i] % 5 == 0)
			my->NumberOf5++;
	}
	return;
};
int* FuncMakeMass(int* count)
{
	srand(time(NULL));
	*count = rand() % 10 + 1;
	int* mass = new int[*count];
	for (int i = 0; i < *count; i++)
	{
		mass[i] = rand() % 100;
		cout << mass[i] << " ";
	}
	return mass;
};