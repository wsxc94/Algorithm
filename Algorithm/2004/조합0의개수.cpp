#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

//숫자의 끝자리 0의 개수는 소인수 분해 했을 때 min(2의 개수 , 5의 개수)
//nCm = n! / (m!(n-m)!)
// -> min(n! 2의개수 - m!의 2의 개수 - (n-m)!의 2의 개수 ,
//        n!의 5의개수 - m!의 5의개수-(n-m)!의 5의 개수)이다.

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