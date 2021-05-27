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
   Ai = A(i/P) + A(i/Q) �� ������ ������·� ���Ѵ�
   ���ʿ��� ����� ���ϱ� ���� map�� �̹� ���� ���� ��ȯ��

*/
long long N, P, Q;
map<long long, long long> m;

long long func(long long num) {

	if (m.count(num)) return m[num];
	else return m[num] = func(num / P) + func(num / Q);

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> P >> Q;

	m[0] = 1;

	cout << func(N) << "\n";

	return 0;
}