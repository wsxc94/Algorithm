#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	stack<char> s;

	char str[101];

	while (true) {
		cin.getline(str, 101);
		if (str[0] == '.') break;
		
		bool check = true;

		int len = strlen(str);

		for (int i = 0; i < len; i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (s.empty() || s.top() == '[') {
					check = false;
					break;
				}
				else if (s.top() == '(')	s.pop();

			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() == '(') {
					check = false;
					break;
				}
				else if (s.top() == '[')	s.pop();
			}
		}

		if (!s.empty() || check == false) cout << "no" << "\n";
		else cout << "yes" << "\n";

		while (!s.empty()) {
			s.pop();
		}
	}
	return 0;
}