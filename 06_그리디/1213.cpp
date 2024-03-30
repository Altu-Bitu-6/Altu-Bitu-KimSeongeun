#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int getOdd(string s, int& odd_index) {

	int odd = 0, even = 0;
	int cnt = 1, i = 1;
	
	while (i < s.length())
	{  
		if (s[i] == s[i - 1]) {
			cnt++;
		}
		else {
			if (cnt % 2 == 1) {
				odd++;
				odd_index = i - 1;
			}
			else {
				even++;
			}
			cnt = 1;
		}
		i++;
	}
	if (cnt % 2 == 1) {
		odd++;
		odd_index = i - 1;
	}

	return odd;
}
int main(void)
{
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	
	int odd_index, i;
	vector<char> ans;

	if (getOdd(s, odd_index) == 0) 
	{
		for (i = 0; i < s.length(); i += 2) {
			ans.push_back(s[i]);
		}
		for (i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		for (i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
	}
	else if (getOdd(s, odd_index) == 1) 
	{
		char oddChar = s[odd_index]; // 홀수 문자를 저장한다
		s.erase(odd_index,1); // s에서 홀수 문자 하나 제거한다

		for (i = 0; i < s.length(); i += 2) {
			ans.push_back(s[i]);
		}

		for (i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << oddChar;

		for (i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}		
	}
	else 
	{
		cout << "I'm Sorry Hansoo";
	}

	return 0;
}