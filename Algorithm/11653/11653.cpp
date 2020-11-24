#include<stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 2; i*i <= n; i++)
	{
		while (n%i == 0)
		{
			n /= i;
			printf("%d\n", i);
		}
	}
	if (n > 1)printf("%d\n", n);
}