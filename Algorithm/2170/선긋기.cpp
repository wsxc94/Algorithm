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
   매우 큰 도화지에 자를 대고 선을 그을 때
   선을 그을 때는 여러번 그은 곳과 한번 그은 곳의 차이를 구별할 수 없다고 한다
   이와 같은 식으로 그었을 때 총 길이를 구하는 프로그램 작성
   선이 여러번 그려진 곳은 한 번씩만 계산

   점의 범위가 -10억 , 10억이기 때문에 일반적인 배열로 풀 수 없음

   sweeping(스위핑)
   어떤 선이나 공간을 한쪽에서부터 싹 스캔
   한 번만 전체 공간을 스캔하면서 마주치는 요소들에 대해 계산

   어렵다
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)	cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end());

	int ans = 0;
	int start = v[0].first;
	int ed = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first <= ed) ed = max(ed, v[i].second);
		else {
			ans += ed - start;
			start = v[i].first;
			ed = v[i].second;
		}
	}

	ans += ed - start;
	cout << ans << '\n';
	
	return 0;
}