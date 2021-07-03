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
    문제 N자리 숫자가 주어 졌을 때 숫자 k개를 지워서 얻을 수 있는 가장 큰수를 구하기
	덱을 사용하여 현재 추가할 숫자가 그 전 숫자보다 작을 때 까지 pop_back을 해준다

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