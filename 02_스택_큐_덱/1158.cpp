#include <iostream>
#include <queue>

using namespace std;
int main(void)
{
	queue<int> q;	
	int n, k, i;

	cin >> n;
	cin >> k;

	for (i = 1; i <= n; i++)
		q.push(i);

	cout << "<";

	while (!(q.empty())) {
		for (i = 1; i <= k - 1; i++)
		{
			int x = q.front();
			q.pop(); 
			q.push(x);
		}
		cout << q.front();
		q.pop();

		if (q.size() != 0) {
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}