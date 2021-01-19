#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int>& stones , int mid , int k) {

	int cnt = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] - mid <= 0)
			cnt++;
		else
			cnt = 0;

		if (cnt >= k) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> stones = { 2,4,5,3,2,1,4,2,5,1 };
	int k = 3;

	int answer = 0;
	int front = 1, back = *max_element(stones.begin(), stones.end());

	while (front <= back)
	{
		int mid = (front + back) / 2;

		if (binarySearch(stones, mid, k))
			back = mid - 1;
		else
			front = mid + 1;
	}
	cout << front << "\n";
}