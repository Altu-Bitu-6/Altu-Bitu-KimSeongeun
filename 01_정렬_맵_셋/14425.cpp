#include <iostream>
#include <set>

using namespace std;
int main(void)
{
	int n, m, i;
	set<string> s;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		s.insert(a);
	}

	int cnt = 0;
	for (i = 1; i <= m; i++)
	{
		string a;
		cin >> a;
		if (s.find(a) != s.end())
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}