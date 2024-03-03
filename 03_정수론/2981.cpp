#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, g;
	vector<int> input;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		input.push_back(x);
	}

	sort(input.begin(), input.end());

	g = input[1] - input[0];
	for (i = 2; i < n; i++)
	{
		g = gcd(g, input[i] - input[i - 1]);
	}

	// 수의 범위가 매우 커서 답을 바로 출력하지 않고 따로 배열에 저장한 뒤 출력하는 과정이 필요하다.
	vector<int> ans;
	for (i = 1; i*i <= g; i++)
	{
		if (i * i == g) {
			ans.push_back(i);
		}
		else if(g%i==0){
			ans.push_back(i);
			ans.push_back(g / i);
		}
	}

	sort(ans.begin(), ans.end());

	for (i = 1; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}