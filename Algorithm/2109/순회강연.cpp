#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
using namespace std;
/*
   n���� ���� d�� �� ������ ���ָ� p��ŭ�� �����Ḧ �����Ѵٰ� �Ѵ�
   �� ���п��� �����ϴ� d , p ���� �ٸ� �� ���� �ִ� ���� ���� ���� ���
   
   d , p �� ���� �Է°��� v �迭�� �����Ѵ�.
   �׸��� v �迭�� d�� �� �������� �������� ����

   �켱����ť�� ������(p)�� �ִ´�
   �켱����ť�� ũ�⺸�� v�� �迭�� d�� ũ�Ⱑ ũ�ٸ� 
   ���� ������ �� ������ 2�� �̻� �ִٴ� ���̱⿡ �ּ������� �ּڰ� ���� �� ans ������ ���ش�
*/

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, d, p, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		ans += v[i].second;

		if (pq.size() > v[i].first) {
			ans -= pq.top();
			pq.pop();
		}
	}
	
	cout << ans << '\n';

	return 0;
}