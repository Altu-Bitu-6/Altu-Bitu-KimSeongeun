#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	int n, i, j;
	cin >> n;

	vector<int> v(n, 0);
	vector<int> d(n, 0); // d[i]: i 인덱스까지, i인덱스를 포함하는 최대 배열

	for (i = 0; i < n; i++)
	{
		int x;	cin >> x;
		v[i] = x;
	}

	for (i = 0; i < n; i++)
	{
		d[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (v[j] < v[i] && d[j]+1>d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	int max = 0;
	for (i = 0; i < n; i++)
	{
		if (max < d[i]) {
			max = d[i];
		}
	}

	cout << max;
	return 0;
}