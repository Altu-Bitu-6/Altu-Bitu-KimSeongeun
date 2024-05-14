#include <iostream>
#include <vector>

using namespace std;

int getSequence(int n, int k, vector<int> &a)
{
	int s = 0, e = 0; // 연속 배열의 시작과 끝
	int maxLen = 1;
	vector<int> check(100000, 0); // 연속 배열에 숫자가 몇개 있는지
	
	// [0,0]을 시작으로 조건을 만족하는동안 e를 1씩 증가시킨다.
	// 조건이 맞지 않으면 다시 맞을 때까지 s를 1 증가시킨다.

	check[a[0]] = 1;

	while(s <= e && e < n)
	{
		if (check[a[e]] <= k) 
		{
			maxLen = max(maxLen, e - s + 1);

			if (e == n - 1) { // 범위 넘침 해결
				return maxLen;
			}
			e++; check[a[e]]++;
		}
		else 
		{
			while (s <= e && check[a[e]] > k) {
				check[a[s]]--; s++;
			}
		}
	}

	return maxLen;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	int i;

	cin >> n >> k;
	vector<int> a(n, 0);
	for (i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
	}
	
	cout << getSequence(n, k, a);

	return 0;
}