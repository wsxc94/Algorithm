#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;
/*
   빠른 거듭제곱 알고리즘 O(logN)
   
   N이 홀수이면 A^N을 A * A^(N-1)로 바꾸고 A를 결과값에 곱한다
   N이 짝수이면 A^N을 (A^2)^(N/2) 즉 A를 제곱하고 N을 2로 나눈다
   N = 0 이면 종료

*/
typedef long long ll;

vector<vector<ll>> operator * (const vector<vector<ll>> &a, const vector<vector<ll>>& b) {
	ll size = a.size();
	vector<vector<ll>> res(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
	{
		for (ll j = 0; j < size; j++)
		{
			for (ll k = 0; k < size; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000;
		}
	}
	return res;
}
vector<vector<ll>> pow_matrix(vector<vector<ll>> a, ll n) {
	ll size = a.size();
	vector<vector<ll>> res(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
	{
		res[i][i] = 1;
	}
	
	while (n > 0)
	{
		if (n % 2 == 1) res = res * a; // operator *
		n /= 2;
		a = a * a; //operator *

	}
	return res;
}
void output_matrix(const vector<vector<ll>>& mat) {

	ll size = mat.size();
	for (ll i = 0; i < size; i++)
	{
		for (ll j = 0; j < size; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	ll n, m;
	cin >> n >> m;
	
	vector<vector<ll>> mat(n, vector<ll>(n));

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	output_matrix(pow_matrix(mat , m));
	
	return 0;
}