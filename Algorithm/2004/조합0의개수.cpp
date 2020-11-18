#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

//������ ���ڸ� 0�� ������ ���μ� ���� ���� �� min(2�� ���� , 5�� ����)
//nCm = n! / (m!(n-m)!)
// -> min(n! 2�ǰ��� - m!�� 2�� ���� - (n-m)!�� 2�� ���� ,
//        n!�� 5�ǰ��� - m!�� 5�ǰ���-(n-m)!�� 5�� ����)�̴�.

pair<long long, long long> zero(long long n) {
	long long two = 0, five = 0;
	for (long long i = 2; i <= n; i*=2)
	{
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5)
	{
		five += n / i;
	}
	return { two , five };
}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	
	long long n, m;
	cin >> n >> m;

	vector<pair<long long, long long>> v(3);

	v[0] = zero(n);
	v[1] = zero(m);
	v[2] = zero(n - m);
	
	cout <<
		min(v[0].first - v[1].first - v[2].first,
			v[0].second - v[1].second - v[2].second) << "\n";

	return 0;
}