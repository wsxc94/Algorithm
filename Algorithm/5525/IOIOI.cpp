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

using namespace std;
/*
    for�� �տ������� s�� Ȯ���� I�� ������ while������ IOI �� �����Ͽ� size �� +1 ���ش�
	 size == n �� �Ǹ� size -1 �׸��� ����� ans +1�� ���ָ� �ȴ�.

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, len, ans = 0;
	string s;

	cin >> n >> len >> s;

	for (int i = 0; i < len; i++)
	{
		int size = 0;

		if (s[i] == 'O') continue;
		else {
			while (s[i+1] == 'O' && s[i+2] == 'I')
			{
				size++;
				if (size == n) {
					size--;
					ans++;
				}
				i += 2;
			}
			size = 0;
		}
	}
	cout << ans << "\n";

	return 0;
}