#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool a[26] = { false, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);


	for (int i = 0; i < 25; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}