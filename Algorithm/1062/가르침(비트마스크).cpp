#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*

   비트마스크를 활용한 풀이
   참고 https://onlytrying.tistory.com/154

   알파벳이 a~z 까지 총 26개 존재하기 때문에 
   32bit인 int형의 2진수로 a~z 까지 알파벳을 
   배웠는지 안배웠는지 여부를 표현할 수 있다.

   핵심은 입력받은 단어에 포함된 알파벳을 OR 연산을 통해 int형 
   변수 word 에 저장함으로써
   배운 알파벳의 정보를 가지고 있는 
   learn과 AND 연산하여 가능 불가능 여부를 O(1) 에 확인할 수 있다는 것이다.

   속도면에서 완전탐색으로 했던 풀이와 많은 차이가 난다
   124ms -> 24ms

*/
int learn, word[50], n, k;

int DFS(int idx, int cnt)
{
	int ret = 0;

	if (cnt == k)
	{
		for (int i = 0; i < n; i++)
			if ((word[i] & learn) == word[i])
				ret++;

		return ret;
	}

	for (int i = idx; i < 26; i++)
	{
		if ((learn & (1 << i)) == 0)
		{
			learn |= (1 << i);
			ret = max(ret, DFS(i + 1, cnt + 1));
			learn &= ~(1 << i);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('c' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++)
			word[i] |= (1 << (str[j] - 'a'));
	}

	if (k < 5 || k == 26)
		cout << (k == 26 ? n : 0) << endl;
	else
		cout << DFS(0, 5) << endl;

	return 0;
}