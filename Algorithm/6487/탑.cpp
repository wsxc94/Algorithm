#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
/*
   ������ ����Ͽ� Ǯ �� �ִ� ����.

   �Է��� �����鼭 ����üŷ
   ó���� �Է��� ���� �� ������ ������� Ȯ���Ѵ�. ����� ��� �ش� ž�� �������� ���� �� ���� ������ 0 ���
   ���� ��� ���� �Է¹��� ž�� ���̿� ������ top�� ���̸� ���Ͽ� ���� ž ���� ũ�Ⱑ ���� ��� pop
   �ƴϸ� �� ������ �ε��� ��ȣ ��� top�� ����� ���̺��� Ŭ������ while�� ���ٺ��� ���� ���´�.

*/

int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	
	stack<pair<int,int>> s;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;

		while (!s.empty())
		{
			if (s.top().second > k) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}

		if (s.empty()) cout << 0 << " ";
		s.push({ i , k });
	}
	

	return 0;
}