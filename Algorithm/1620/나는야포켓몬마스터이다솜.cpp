#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

unordered_map<string, int> m_pokemonToInt;
unordered_map<int, string> m_pokemonToString;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	string s;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		m_pokemonToInt[s] = i;
		m_pokemonToString[i] = s;

	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') cout << m_pokemonToString[stoi(s)] << "\n";
		else cout << m_pokemonToInt[s] << "\n";
	}
	
	return 0;
}