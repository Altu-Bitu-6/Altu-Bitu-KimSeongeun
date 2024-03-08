#include <iostream>
#include <vector>

using namespace std;
void checkPrime(vector<int>& prime)
{
	int i, j;
	for (i = 2; i * i <= 1000000; i++)
	{
		if (prime[i] == 1)
		{
			for (j = i * i; j <= 1000000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> isPrime(1000001, 1);
	isPrime[1] = isPrime[2] = 0;
	checkPrime(isPrime); // 홀수 소수이면 isPrime[]이 1

	int x;
	cin >> x;

	while (x != 0)
	{
		int getAns = 0;
		for (int i = 3; i <= x / 2; i += 2)
		{
			if (isPrime[i] == 1 && isPrime[x - i] == 1)
			{
				cout << x << " = " << i << " + " << x - i << "\n";
				getAns = 1; break;
			}
		}
		if (getAns == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}

		cin >> x;
	}

	return 0;
}