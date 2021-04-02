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
#include <algorithm>
using namespace std;
/*
  공백이 없어진 순열 문자열을 복구하는 문제
  문자열의 길이 보다 큰 찢어진 숫자는 없을 것이기 때문에 처음에 문자열의 길이를 구해 기준으로 만든다.
  그리고 재귀를 통해 나누어 v 배열에 넣은 후 출력한다.
*/
constexpr int MAX = 51;

int len, max_num;
string str;
bool ch[MAX];
vector<int> v;

void dfs(int ind) {
	// 정상적으로 순열을 나눈 경우
	if (ind == len) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		exit(0);
	}

	// 순열을 1자리 또는 2자리로 자름
	string p = "";
	int cur = 0;
	for (int i = ind; i <= ind + 1; i++) {
		p += str[i];
		cur = stoi(p);

		if (cur > max_num) continue;
		if (ch[cur]) continue;

		v.push_back(cur);
		ch[cur] = true;
		dfs(i + 1);
		ch[cur] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> str;

	// 순열의 길이와 최대값을 구함
	len = str.size();

	if (len < 10) {
		max_num = len;
	}
	else {
		max_num = (len - 9) / 2 + 9;
	}

	dfs(0);


	return 0;
}