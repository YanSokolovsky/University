#include "childfunc.h"
void sort(int* a, int first, int last)
{
	int i = first;
	int j = last;
	int tmp, x = a[(first + last + 1) / 2];
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j--;
			i++;
		}
	} while (i <= j);
	if (i < last)
		sort(a, i, last);
	if (j > first)
		sort(a, first, j);
};
int* MakeMass(char* arg[], int count)
{
	int* a = new int[count - 1];
	for (int i = 1; i < count; i++)
	{
		a[i - 1] = stoi(arg[i]);
	}
	return a;
};