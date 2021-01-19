#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

//�ڵ��� ���ڵ��� ���� �迭�� ��� 0���� �ʱ�ȭ�̹Ƿ� �����
//0,1,2,3,4,5,6,7,8,9
vector<string> phone = { "" , ".QZ","ABC","DEF","GHI","JKL" , "MNO" , "PRS" , "TUV" , "WXY" };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	char before = ' '; // �� �ε����� ���ڸ� �����ϱ����� ó������ ����� �Ǹ� �ȵǱ⶧���� ������ �����̽� ' ' �� ������ �ε����� 1���� �����ϰ� before�� s[0]������ ���� �����ϴ� ����� ����.
	int cnt = 0; // �ߺ� ��ȣ ī��Ʈ
	string ans = ""; // ��

	for (int i = 0; i < s.size(); i++)
	{
		if (before != ' ' && s[i] == before) { // �� ���ڰ� ' ' �̰�  ���� �ε����� ���ڹ�ư�� ������ �ߺ��̱⶧���� ī��Ʈ�� �ø�
			cnt++;
		}
		else {
			if (before != ' ' && before != '0') { // �� ���ڰ� ' ' �� �ƴϰ� �ʱ�ȭ��ư�� 0�� �ƴ϶��
				ans += phone[before - '0'][cnt]; // �信 before �� ���ڷιٲ��� ��ư ��ȣ�� ���� �ߺ�Ƚ�� cnt�� �մ� ���ڸ� ������ ex) 2���� 3�� Ŭ�������� C��� ���ڰ� ��ȯ�� 
			}
				cnt = 0; //���ڸ� ��������� ī��Ʈ �ʱ�ȭ�ϰ�
				before = s[i]; // ���� �˻��� ��ư�� ��ȣ�� ������ 
		}
	}
	// s�� �ٵ������� �������� ���� �κ��� ó�������� ���߱� ������ ������ ������ ����.
	ans += phone[before - '0'][cnt];

	cout << ans << "\n";

	return 0;
}