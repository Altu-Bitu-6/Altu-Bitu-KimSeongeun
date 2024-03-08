#include <iostream>
#include <vector>

using namespace std;
void getPrime(vector<int>& v, int size)
{
	int i, j;
	v[1] = 0;

	for (i = 2; i * i <= size; i++)
	{
		if (v[i] == 1)
		{
			for (j = i * 2; j <= size; j += i)
			{
				v[j] = 0;
			}
		}
	}
}
int getSum(int a)
{
	int s = 0;
	while (a != 0) {
		s += (a % 10) * (a % 10);
		a /= 10;
	}
	return s;
}
int sumRelay(int x, vector<int>& sum, vector<int>& check)
{
	if (x == 1) {
		return 1;
	}
	if (check[x] == 1) {
		return -1;
	}
	check[x] = 1;
	return sumRelay(sum[x], sum, check);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> isPrime(1000001, 1);
	vector<int> sum(1000001, 0);
	int n, i;

	cin >> n;

	getPrime(isPrime, n); // n 이하의 소수 구한다. 소수는 isprime[]이 1 

	for (i = 1; i <= 1000000; i++) {
		sum[i] = getSum(i); // 1000000까지 각 자리수 제곱합 구한다.
	}

	for (i = 1; i <= n; i++)
	{
		if (isPrime[i] == 1)
		{
			vector<int> check(600, 0); // 각 자리수 제곱합의 최대값은 81*7=567
			int s = sumRelay(sum[i], sum, check);

			if (s == 1) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}