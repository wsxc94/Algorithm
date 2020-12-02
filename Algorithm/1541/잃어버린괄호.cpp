#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	int answer = 0;
	bool minus = false;
	string tmp = "";

	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
		{
			if (minus)
			{
				answer -= stoi(tmp);
			}
			else {
				answer += stoi(tmp);
			}

			tmp = "";

			if (str[i] == '-')
			{
				minus = true;
			}
			continue;
		}
		tmp += str[i];
	}

	cout << answer;

	return 0;
}