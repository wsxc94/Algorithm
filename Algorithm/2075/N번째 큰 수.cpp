#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
/*
   메모리 제한으로 인해 입력값을 전부 큐에 넣으면 메모리초과가 발생함

   최소힙을 가지는 우선순위 큐를 만들어
   큐에 가장 큰 수 n개만 들어갈 수 있도록 함

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;

	cin >> n;

	priority_queue<int , vector<int> , greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num, qSize;
			cin >> num;

			qSize = pq.size();
			// 큐의 사이즈가 n보다 작으면 넣어줌
			if (qSize < n) pq.push(num);
			else if (num > pq.top()) { // 입력된값이 큐의 top값보다 크면 넣고 최소값을 뺌
				pq.push(num);
				pq.pop();
			}
			else continue;
			
		}
	}


	cout << pq.top() << "\n";
	return 0;
}