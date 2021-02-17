#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int solution(string s) {

	int len = s.size(), mid = 0;

	if (len <= 1)
		return len;

	while (len > 1)
	{
		//���� �� �Ӹ������ ã�ƾ� �ϹǷ� s�� ���̺��� ����.
		for (int i = 0; i <= s.size() - len; i++)
		{
			bool ch = true;
			mid = len / 2;

			if (len % 2) // Ȧ�� ¦�� ����
			{
				for (int j = 0; j < mid; j++)
				{
					if (s[j + i] != s[i + mid * 2 - j])
					{
						ch = false;
						break;
					}
				}
			}
			else
			{
				for (int j = 0; j < mid; j++)
				{
					if (s[j + i] != s[i + mid * 2 - 1 - j])
					{
						ch = false;
						break;
					}
				}
			}
			if (ch) return len;
		}
		len--;
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s = "abacde";
	
	cout << solution(s) << "\n";
	return 0;
}