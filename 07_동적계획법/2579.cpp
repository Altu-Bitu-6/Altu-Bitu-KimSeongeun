#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	int n, i;
	cin >> n;

	vector<int> v(n + 1, 0); // v[i]: i번째 계단
	vector<int> d(n + 1, 0); // d[i]: i번째 계단을 포함한 최댓값

	for (i = 1; i <= n; i++) {
		int x; cin >> x;
		v[i] = x;
	}

	//for문으로 계산할 수 없는 d[i]에 초기값을 넣는다
	d[1] = v[1];
	d[2] = v[1] + v[2];

	for (i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + v[i], d[i - 3] + v[i - 1] + v[i]);
	}

	cout << d[n];

	return 0;
}