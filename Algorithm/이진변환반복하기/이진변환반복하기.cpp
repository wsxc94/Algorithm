#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

string binary(int num) {
	/*stack<int> st;
	string str = "1";
	while (num != 1)
	{
		st.push(num % 2);
		num /= 2;
	}
	while (!st.empty())
	{
		str += to_string(st.top());
		st.pop();
	}*/
	int tmp;
	string str = "";

	while (num > 0)
	{
		tmp = num % 2;
		str += to_string(tmp);
		num /= 2;
	}

	return str;
}
vector<int> solution(string s) {
	vector<int> answer(2);

	int cnt = 0, zeroCnt = 0;
	while (s.length() != 1) {
		string tmp = "";

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') {
				tmp += s[i];
			}
			else {
				zeroCnt++;
			}
		}
		s = binary(tmp.length());
		cnt++;
	}
	answer[0] = cnt;
	answer[1] = zeroCnt;

	return answer;
}
int main() {
	vector<int> result;
	result = solution("110010101001");

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}