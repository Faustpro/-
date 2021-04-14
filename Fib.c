#include <stdio.h>

unsigned long long Fib(int n, int a, int b);

int main()
{
	int n;
	unsigned long long a;
	scanf_s("%d", &n);
	a = Fib(n, 1, 0);
	printf("%ull", a);
	return 0;
}

unsigned long long Fib(int n, int a, int b)
{
	if (0 == n)
		return b;
	return Fib(n - 1, a + b, a);
}
