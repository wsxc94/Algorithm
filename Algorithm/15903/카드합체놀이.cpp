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

typedef long long ll;

using namespace std;
/*
   ī���� ���� �ּҰ��� ���ϱ� ���� �ּ���(�켱����ť) ���
   ī���� ���� int �ڷ����� ������ �Ѿ �� ������ long long ���
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	priority_queue<ll , vector<ll> , greater<ll>> q;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	while (m--)
	{
		ll first = q.top();
		q.pop();
		ll second = q.top();
		q.pop();
		ll sum = first + second;
		//���忡 ��� ������ �ϹǷ� �ι� push ����
		q.push(sum);
		q.push(sum);
	}
	
	ll ans = 0;

	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	//��� ���
	cout << ans << "\n";

	
	
	return 0;
}