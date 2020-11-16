#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL);

	int a, b;
	
	while (true)
	{
	   cin >> a >> b;
	   if (!a && !b) break;

	   if (a > b) {
		   if (a % b == 0)
			   cout << "multiple" << "\n";
		   else
			   cout << "neither" << "\n";
	   }
	   else {
		   if (b % a == 0)
			   cout << "factor" << "\n";
		   else
			   cout << "neither" << "\n";
	   }

	}



	return 0;
}