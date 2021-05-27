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
   Ai = A(i/P) + A(i/Q) 의 수열을 재귀형태로 구한다
   불필요한 계산을 피하기 위해 map에 이미 나온 값을 반환할

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