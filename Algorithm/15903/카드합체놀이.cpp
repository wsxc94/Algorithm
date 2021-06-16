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
   카드의 총합 최소값을 구하기 위해 최소힙(우선순위큐) 사용
   카드의 합이 int 자료형의 범위를 넘어갈 수 있으니 long long 사용
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
		//두장에 모두 덮어써야 하므로 두번 push 해줌
		q.push(sum);
		q.push(sum);
	}
	
	ll ans = 0;

	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	//결과 출력
	cout << ans << "\n";

	
	
	return 0;
}