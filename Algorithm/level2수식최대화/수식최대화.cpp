#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long cal(long long num1, long long num2, char op) {
	if (op == '+')  return num1 + num2;
	else if (op == '-')  return num1 - num2;
	else if (op == '*')  return num1 * num2;
	return 0;
}
long long solution(string expression) {
	long long answer = 0;

	vector<int> v;
	vector<char> exp;
	string oper = "+-*";
	sort(oper.begin(), oper.end());

	long long tmp = 0;
	for (int i = 0; i < expression.size(); i++)
	{

		if (expression[i] -'0' >= 0 && expression[i] - '0' <= 9 )
		{
			tmp *= 10;
			tmp += expression[i] - '0';
		}
		else {
			exp.push_back(expression[i]);
			v.push_back(tmp);
			tmp = 0;
			
		}
	}
	v.push_back(tmp);


	do { /* 숫자열과 연산자열을 q1에 저장. q2는 1차례 계산 후의 숫자열과 연산자열이 저장될 큐 */ 
		queue<long long, deque<long long>> num_q2, num_q1(deque<long long>(v.begin(), v.end())); 
		queue<char, deque<char>> op_q2, op_q1(deque<char>(exp.begin(), exp.end()));
		for (int i = 0; i < 3; ++i) {
			// last : 중간에 계산된 숫자를 저장 
			long long last = num_q1.front(); num_q1.pop(); 
			while (!op_q1.empty()) { 
				// 해당순위 연산자일 때 : 숫자 연산한 값을 last에 저장 
				if (op_q1.front() == oper[i]) {
					last = cal(last, num_q1.front(), op_q1.front()); 
				} 
				// 해당순위 연산자가 아닐 때 : last를 q2에 저장 후, q1의 다음 숫자로 교체 
				else { 
					op_q2.push(op_q1.front()); num_q2.push(last); last = num_q1.front(); 
				} 
				op_q1.pop(); 
				num_q1.pop(); 
			} 
			num_q2.push(last); 
			// 마지막에 남은 숫자큐의 원소가 1개일 때 : 최대 절대값 갱신 
			if (num_q2.size() == 1) { answer = max(abs(num_q2.front()), answer); } 
			// q1과 q2의 포인터 교환 
			num_q1.swap(num_q2); op_q1.swap(op_q2); 
		} 
	} while (next_permutation(oper.begin(), oper.end()));

	
	
	
	return answer;
}
int main() {

	string s = "100-200*300-500+20";
	cout << solution(s);

	return 0;
}