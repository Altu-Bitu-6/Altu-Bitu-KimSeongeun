#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int binarySearch(int x, vector<int>& input, int n)
{
	int s = 0, e = n - 1; // 이진탐색 left, rignt, mid 변수 선언
	int mid;
	int ans = 0;

	while (true) {
		if (s > e) {
			break;
		}

		mid = (s + e) / 2;
		if (input[mid] == x) {
			ans = 1; // x가 input에 있으면 ans를 1로 변경하고 탐색을 끝낸다.
			break;
		}
		else if (input[mid] < x) {
			s= mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return ans;
}
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	int i;

	cin >> n;
	vector<int> input(n, 0);
	for (i = 0; i < n; i++) {
		int x; cin >> x;
		input[i] = x;
	}

	sort(input.begin(), input.end());
	
	cin >> m;
	for (i = 0; i < m; i++)
	{
		int x; cin >> x;
		int ans = binarySearch(x, input, n); // x가 input[]에 있는지 이진탐색 한다.
		cout << ans << " ";
	}

	return 0;
}