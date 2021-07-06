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
   �ſ� ū ��ȭ���� �ڸ� ��� ���� ���� ��
   ���� ���� ���� ������ ���� ���� �ѹ� ���� ���� ���̸� ������ �� ���ٰ� �Ѵ�
   �̿� ���� ������ �׾��� �� �� ���̸� ���ϴ� ���α׷� �ۼ�
   ���� ������ �׷��� ���� �� ������ ���

   ���� ������ -10�� , 10���̱� ������ �Ϲ����� �迭�� Ǯ �� ����

   sweeping(������)
   � ���̳� ������ ���ʿ������� �� ��ĵ
   �� ���� ��ü ������ ��ĵ�ϸ鼭 ����ġ�� ��ҵ鿡 ���� ���

   ��ƴ�
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