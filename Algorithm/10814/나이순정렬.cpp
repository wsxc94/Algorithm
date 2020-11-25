#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct member
{
	string name;
	int age;
	int order;
};
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n;
	cin >> n;

	vector<member> v;

	v.reserve(n + 1);

	for (int i = 0; i < n; i++)
	{
		member tmp;
		cin >> tmp.age >> tmp.name;
		tmp.order = i;
		v.push_back(tmp);
	}

	stable_sort(v.begin(), v.end(), [](const member& a, const member& b) -> bool{
		if (a.age == b.age) return a.order < b.order;
		return a.age < b.age;
		});


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].age << " " << v[i].name << "\n";
	}


	return 0;
}