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

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int res;
	int idx = 1;

	// ķ������ �����ϴ� P���� L�ϵ��ȸ� ����� �� �ְ�
	// V�� ¥�� �ް��� �� �����ߴ�.
	// (V/P) * L = �����ϴ� P���� V���߿� ������� ���� P���� L�ϸ� ��밡������ ���Ѵ�
	// min(V%P , L) = ���ϴ� �κ��� ���� L,P,V�� 5,8,20 �̸�
	// �����ϴ� 8�Ͼ� ����ϰ� �� �� ������ 4��
	// �������� ��� ���� �ϼ��� ���ؼ� ������ ����ŭ ���Ѵ�.
	while (true)
	{
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		res = (V / P) * L + min(V%P, L);

		cout << "Case " << idx << ": " << res << "\n";
		idx++;
	}
	return 0;
}