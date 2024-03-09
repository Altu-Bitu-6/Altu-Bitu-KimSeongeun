#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> d(21, 0); // d[]가 1이면 존재, 0이면 없음

	cin >> n;
	string s;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "add") {
			cin >> x;
			d[x] = 1;
		}
		else if (s == "remove") {
			cin >> x;
			d[x] = 0;
		}
		else if (s == "check") {
			cin >> x;
			cout << d[x] << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			d[x] = 1 - d[x];
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				d[i] = 1;
			}
		}
		else { //"empty"일때
			for (int i = 1; i <= 20; i++) {
				d[i] = 0;
			}
		}
	}

	return 0;
}