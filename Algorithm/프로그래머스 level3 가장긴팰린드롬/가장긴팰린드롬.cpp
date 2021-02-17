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
		//가장 긴 팰린드롬을 찾아야 하므로 s의 길이부터 시작.
		for (int i = 0; i <= s.size() - len; i++)
		{
			bool ch = true;
			mid = len / 2;

			if (len % 2) // 홀수 짝수 구분
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