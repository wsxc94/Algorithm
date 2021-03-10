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
   �� 3���� ������ �ð�������� �ݽð�������� ���������� �Ǵ��ϴ� �˰���
   �������� �̷���� �ﰢ���� ������ ���� ������ ���Ѵ�
   ���� > 0 �ݽð�
   ���� < 0 �ð�
   ���� = 0 ������

   ù��° �� (x1, y1)���� �ΰ� ������ �������� ���̸� ����

*/
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int v = x1 * y2 + x2 * y3 + x3 * y1;
	v = v - y1 * x2 - y2 * x3 - y3 * x1;

	if (v > 0) {
		return 1;
	}
	else if (v < 0) {
		return -1;
	}
	
	return 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	cout << ccw(x1, y1, x2, y2, x3, y3) << "\n";

	return 0;
}