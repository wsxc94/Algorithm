#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

string bigNumAdd(string num1, string num2){
	long long sum = 0;
	string result;

	//1의 자리부터 더하기 시작한다
	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		//다시 string 형태로 만들어 push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	//1의 자리부터 result에 넣었으므로 뒤집어줘야한다
	reverse(result.begin(), result.end());

	return result;
}
//2의 n승은 0으로 끝날 수 없으므로

string subtractOne(string num){
	vector<int> v;
	int back = num.back() - '0';
	num.pop_back();
	back -= 1;
	num.push_back(back + '0');
	return num;
}
void hanoi(int n, int start, int to, int bypass) {
	if (n == 1)
	{
		v.push_back({ start,to });
	}
	else {
		hanoi(n - 1, start, bypass, to);
		v.push_back({ start, to });
		hanoi(n - 1, bypass, to, start);
	}
}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	int num;
	cin >> num;

	if (num <= 20)
	{
		v.reserve(pow(2, num) + 1);
		hanoi(num, 1, 3, 2);
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}
	else {
		string str = "2";
		for (int i = 0; i < num - 1; i++)
		{
			string tmp = bigNumAdd(str, str);
			str = tmp;
		}
		cout << subtractOne(str) << "\n";
	}

	return 0;
}