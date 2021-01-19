#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c, cnt = 0;

void quad(int x , int y , int size) {

	if (x == r && y == c) {
		cout << cnt << "\n";
		return;
	}

	if (r < x + size && r >= x && c < y + size && c >= y) {
		quad(x, y, size / 2);
		quad(x, y + size / 2, size / 2);
		quad(x + size / 2, y, size / 2);
		quad(x + size / 2, y + size / 2, size / 2);
	}
	else {
		cnt += pow(size, 2);
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> r >> c;

	quad(0, 0, pow(2, n));


	return 0;
}