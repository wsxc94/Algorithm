#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	priority_queue<int , vector<int> , cmp> pq;

	int n , m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		if (m == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(m);
		}
	}
	return 0;
}