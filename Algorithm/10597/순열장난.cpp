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
  ������ ������ ���� ���ڿ��� �����ϴ� ����
  ���ڿ��� ���� ���� ū ������ ���ڴ� ���� ���̱� ������ ó���� ���ڿ��� ���̸� ���� �������� �����.
  �׸��� ��͸� ���� ������ v �迭�� ���� �� ����Ѵ�.
*/
constexpr int MAX = 51;

int len, max_num;
string str;
bool ch[MAX];
vector<int> v;

void dfs(int ind) {
	// ���������� ������ ���� ���
	if (ind == len) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		exit(0);
	}

	// ������ 1�ڸ� �Ǵ� 2�ڸ��� �ڸ�
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

	// ������ ���̿� �ִ밪�� ����
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