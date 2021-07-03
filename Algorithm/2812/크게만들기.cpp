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
    ���� N�ڸ� ���ڰ� �־� ���� �� ���� k���� ������ ���� �� �ִ� ���� ū���� ���ϱ�
	���� ����Ͽ� ���� �߰��� ���ڰ� �� �� ���ں��� ���� �� ���� pop_back�� ���ش�

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;

	deque<char> dq;

	for (int i = 0; i < s.size(); i++)
	{
		while (k && !dq.empty() && dq.back() < s[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(s[i]);
	}

	for (int i = 0; i < dq.size() - k; i++)
	{
		cout << dq[i];
	}



	
	return 0;
}