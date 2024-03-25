#include <iostream>
#include <vector>

using namespace std;
long long process(int n, vector<long long>& v) 
{
	int i;
	long long min = v[n-1];

	for (i = n - 2; i >= 0; i--)
	{
		if (v[i] > min) {
			min = v[i];
		}
		else if(v[i] < min) {
			if (min % v[i] != 0) {
				min = (min / v[i] + 1) * v[i];
			}
		}
	}

	return min;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, i;
	cin >> n;

	vector<long long> v;
	for (i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}

	long long ans = process(n, v);
	cout << ans;

	return 0;
}