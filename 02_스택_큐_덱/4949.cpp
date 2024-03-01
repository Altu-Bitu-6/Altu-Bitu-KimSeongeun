#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void)
{
	while (true) {
		string c;
		stack<char> s;

		getline(cin, c); //getline 함수로 공백이 있는 문장 입력 받기

		if (c==".") {
			break;
		}
		else {
			int i;
			for (i = 0; i < c.length(); i++)
			{
				if (c[i] == '(' || c[i] == '[') {
					s.push(c[i]);
				}
				else if (c[i] == ')') {
					if (!(s.empty()) && s.top() == '(') {
						s.pop();
					}
					else {
						break;
					}
				}
				else if (c[i] == ']') {
					if (!(s.empty()) && s.top() == '[') {
						s.pop();
					}
					else {
						break;
					}
				}
			}
			if (i == c.length() && s.empty()) { //i가 문장 처음부터 끝까지 순회했을 때(문장에 문제가 없을 때), 스택이 비어있을 때
				cout << "yes\n";
			}
			else
				cout << "no\n";
		}
	}
	return 0;
}