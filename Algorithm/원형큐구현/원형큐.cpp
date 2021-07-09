#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
using namespace std;

constexpr int MAX = 101;

template<class T> class Queue 
{
private:
	int front;
	int rear;
	int size;
	T *values;
public:
	Queue() {
		size = MAX;
		values = new T[size];
		front = 0;
		rear = 0;
	}
	~Queue() {
		delete[] values;
	}

	int Front() {
		if(!empty()) return values[front];
		cout << "Queue is empty" << '\n';
		return 0;
	}

	void push(T value) {
		if (!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}
		else {
			cout << "Queue is Full" << "\n";
		}
	}
	void pop() {
		if (!empty()) front = (front + 1) % size;
		else cout << "Queue is empty" << "\n";
	}
	bool empty() {
		if (rear == front) return true;
		return false;
	}
	bool isFull() {
		if ((rear + 1) % size == front) return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	Queue<int> q;
	q.push(3);
	q.pop();
	q.push(5);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);
	q.push(11);
	q.pop();

	while (!q.empty())
	{
		cout << q.Front() << " ";
		q.pop();
	}

	queue<int> qqq;

	return 0;
}