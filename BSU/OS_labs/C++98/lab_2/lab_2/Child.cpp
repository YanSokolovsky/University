#include "childfunc.h"
int main(int argc, char* argv[])
{
	int* a = MakeMass(argv, argc);
	sort(a, 0, argc - 2);
	for (int i = 0; i < argc - 1; i++)
	{
		cout << a[i] << " ";
	}
	char ret;
	cin >> ret;
	return 0;
}