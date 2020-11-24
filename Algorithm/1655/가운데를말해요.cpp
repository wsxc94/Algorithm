#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
pqMin : 작은 값들 저장 (내림차순)
pqMax : 큰 값들 저장 (오름차순)

새로운 값이 들어왔을 때 pqMax.top보다 크면 pqMax에 넣어주고
pqMin.top보다 작으면 pqMin에 넣어줍니다.

만약 넣고나서 아래의 조건이 성립하지 않으면

1. pqMax == pqMin + 1
2. pqMax == pqMin

많은 쪽에서 적은쪽으로 top의 위치의 숫자를 옮겨 줍니다.
*/
int main() {

	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> max_pq;
	priority_queue<int> min_pq;

	int n, x;
	cin >> n;

	while (n--)
	{
		cin >> x;

		if (min_pq.empty() || min_pq.top() >= x) {
			min_pq.push(x);
			if (min_pq.size() > max_pq.size() + 1) {
				max_pq.push(min_pq.top());
				min_pq.pop();
			}
		}
		else if (max_pq.empty() || max_pq.top() <= x)
		{
			max_pq.push(x);
			if (max_pq.size() > min_pq.size())
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
			}
		}
		else if (min_pq.size() <= max_pq.size())
		{
			min_pq.push(x);
		}
		else if (min_pq.size() > max_pq.size())
		{
			max_pq.push(x);
		}

		cout << min_pq.top() << "\n";
	}

	return 0;
}