#include <iostream>
#include <vector>

using namespace std;
int main(void) {

	vector<int> v1, v2, v3;
	string s1, s2;
	int len, i;

	cin >> s1 >> s2; 

	if (s1.length() > s2.length()) { // s1와 s2 중 더 큰 자리수 구하기
		len = s1.length();
	}
	else { 
		len = s2.length();
	}

	v1.assign(len, 0); // 문자열 s1을 저장할 정수배열 v1
	v2.assign(len, 0); // 문자열 s2을 저장할 정수배열 v2
	v3.assign(len + 1, 0); // v1과 v2의 합을 저장할 정수배열 v3

	for (i = s1.length()-1; i>=0; i--) {
		v1[s1.length() - 1 - i] = s1[i] - '0'; // 문자열 s1을 정수형 배열 v1에 저장한다.
	}
	for (i = s2.length()-1; i>=0; i--) {
		v2[s2.length() - 1 - i] = s2[i] - '0'; // 문자열 s2을 정수형 배열 v2에 저장한다.
	}

	
	for (i = 0; i < len; i++) {
		v3[i] += v1[i] + v2[i];
		if (v3[i] >= 10) {
			v3[i + 1] += 1;
			v3[i] -= 10;
		}
	}

	if (v3[len] != 0) cout << v3[len];
	for (i = len - 1; i >= 0; i--)
		cout << v3[i];

	return 0;

}