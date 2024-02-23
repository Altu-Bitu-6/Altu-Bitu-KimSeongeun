#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string &s1, const string &s2)
{
	int len1 = s1.length();
	int len2 = s2.length();

	if (len1 < len2)
		return true;
	else if (len1 == len2)
	{
		int i, sum1 = 0, sum2 = 0;

		for (i = 0; i < len1; i++)
			if (isdigit(s1[i]))
				sum1 += s1[i]-'0';
		for (i = 0; i < len2; i++)
			if (isdigit(s2[i]))
				sum2 += s2[i]-'0';

		if (sum1 < sum2) return true;
		else if (sum1 == sum2)
		{
			if (s1 < s2)
				return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
int main(void)
{
	int n, i;
	string a[55];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, compare);

	for (i = 0; i < n; i++)
		cout << a[i] << "\n";

	return 0;
}