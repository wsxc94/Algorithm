#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*

   ��Ʈ����ũ�� Ȱ���� Ǯ��
   ���� https://onlytrying.tistory.com/154

   ���ĺ��� a~z ���� �� 26�� �����ϱ� ������ 
   32bit�� int���� 2������ a~z ���� ���ĺ��� 
   ������� �ȹ������ ���θ� ǥ���� �� �ִ�.

   �ٽ��� �Է¹��� �ܾ ���Ե� ���ĺ��� OR ������ ���� int�� 
   ���� word �� ���������ν�
   ��� ���ĺ��� ������ ������ �ִ� 
   learn�� AND �����Ͽ� ���� �Ұ��� ���θ� O(1) �� Ȯ���� �� �ִٴ� ���̴�.

   �ӵ��鿡�� ����Ž������ �ߴ� Ǯ�̿� ���� ���̰� ����
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