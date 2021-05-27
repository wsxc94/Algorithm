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
   �޸� �������� ���� �Է°��� ���� ť�� ������ �޸��ʰ��� �߻���

   �ּ����� ������ �켱���� ť�� �����
   ť�� ���� ū �� n���� �� �� �ֵ��� ��

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;

	cin >> n;

	priority_queue<int , vector<int> , greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num, qSize;
			cin >> num;

			qSize = pq.size();
			// ť�� ����� n���� ������ �־���
			if (qSize < n) pq.push(num);
			else if (num > pq.top()) { // �ԷµȰ��� ť�� top������ ũ�� �ְ� �ּҰ��� ��
				pq.push(num);
				pq.pop();
			}
			else continue;
			
		}
	}


	cout << pq.top() << "\n";
	return 0;
}