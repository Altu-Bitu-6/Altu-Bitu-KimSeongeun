#include <iostream>
#include <vector> 

using namespace std;
int getBig(int x) // x보다 큰 종말수를 구하는 함수
{
	while (1) {
		x += 1;
		
		//x에 1을 계속 더해서 종말수가 나올때까지 loop
		int tmp = x, cnt = 0;
		while (tmp != 0) 
		{
			if (tmp % 10 == 6) {
				cnt++;
			}
			else {
				cnt = 0;
			}
			tmp /= 10;

			if (cnt == 3) {
				return x;
			}
		}
	}
}
int main(void)
{
	int n, i;
	cin >> n;

	int x=666;
	for (i = 1; i < n; i++) {
		x = getBig(x);
	}
	cout << x;

	return 0;
}