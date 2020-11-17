#include <iostream>
#include <math.h>
using namespace std;
#define X(x) x*x

int main() {
	cout << X(5+3);
	int x1, y1, r1, x2, y2, r2, d, cir1, cir2, num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = pow(x1 - x2, 2) + pow(y1 - y2, 2);

		cir1 = pow(r1 - r2, 2);
		cir2 = pow(r1 + r2, 2);

		if (d == 0)
		{
			if (cir1 == 0)
				cout << "-1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (d == cir1 || d == cir2)
			cout << "1" << '\n';
		else if (cir1 < d && d < cir2)
			cout << "2" << '\n';
		else
			cout << "0" << '\n';

		
	}

}