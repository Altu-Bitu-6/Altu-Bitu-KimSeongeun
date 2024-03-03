#include <iostream>

using namespace std;

int gcd(int n, int m)
{
	if (m == 0) {
		return n;
	}
	return gcd(m, n % m);
}
int main(void)
{
	int a, b, c, d;
	int n, m;

	cin >> a >> b >> c >> d;

	m = b * d; //분모
	n = a * d + b * c; //분자

	int g; // 분모와 분자의 최대공약수
	g = gcd(max(n, m), min(n, m));

	cout << n / g << " " << m / g;
	return 0;
}