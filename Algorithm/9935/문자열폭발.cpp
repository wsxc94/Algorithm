#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

/*
    ���ڿ� �ΰ��� �Է¹ް� 
	ù��° ���ڿ����� �ι�° ���ڿ��� ���������������� �����ִ� ����

	stack�� ����� �������� �ѱ��ھ� �־��ָ� word �˻� �� word ���ڿ��� ������ ���ڿ� ������ ���� ���ڿ���
	Ȯ�����ָ� ���� �Ǻ��� �������ִ� ������ �����Ͽ���.
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s, word;
	cin >> s >> word;

	string ans = "";

	int w_len = word.length() - 1;

	for (int i = 0; i < s.length(); i++) {
		ans += s[i];
		if (ans[ans.length() - 1] == word[w_len]) {
			if (ans.length() >= word.length()) {
				int cnt = 1;
				for (int j = w_len - 1; j >= 0; j--) {
					if (ans[ans.length() - (w_len - j) - 1] == word[j]) {
						cnt++;
					}

				}
				if (word.length() == cnt) {
					for (int b = 0; b < word.length(); b++) {
						ans.pop_back();
					}
				}
			}
		}
	}
	if (ans.length() > 0) {
		cout << ans << endl;
	}
	else {
		cout << "FRULA" << endl;
	}

	return 0;
}