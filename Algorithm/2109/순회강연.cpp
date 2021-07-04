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
   n개의 대학 d일 의 강연을 해주면 p만큼의 강연료를 지불한다고 한다
   각 대학에서 제시하는 d , p 값은 다를 때 벌수 있는 가장 많은 돈을 출력
   
   d , p 에 대한 입력값을 v 배열에 저장한다.
   그리고 v 배열을 d일 을 기준으로 오름차순 정렬

   우선순위큐에 강연료(p)를 넣는다
   우선순위큐의 크기보다 v의 배열의 d의 크기가 크다면 
   같은 기한을 둔 강연이 2개 이상 있다는 것이기에 최소힙에서 최솟값 제거 및 ans 에서도 빼준다
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