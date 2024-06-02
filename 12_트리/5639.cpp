#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void pushNode(int x, int node, vector<int>& input, vector<pair<int,int>>& tree_child)
{
	if (input[x] < input[node]) { // input[x]가 현재 노드보다 작으면
		if (tree_child[node].first == -1){
			tree_child[node].first = x;
		}
		else {
			pushNode(x, tree_child[node].first, input, tree_child);
		}
	}
	else {							// input[x]가 현재 노드보다 크면
		if (tree_child[node].second == -1) {
			tree_child[node].second = x;
		}
		else {
			pushNode(x, tree_child[node].second, input, tree_child);
		}
	}
}
void postorder(int node, vector<int>& input, vector<pair<int, int>>& tree_child)
{
	if (tree_child[node].first != -1) {
		postorder(tree_child[node].first, input, tree_child);
	}
	if (tree_child[node].second != -1) {
		postorder(tree_child[node].second, input, tree_child);
	}
	cout << input[node] << "\n";
}
int main() {

	vector<int> input; 
    
	int x;							 // cin으로 하는 방법들이 visual studio 에서 잘 안돼서,,,
	while (scanf("%d", &x) != EOF)   // scanf로 입력을 받는 방법밖에 모르겠습니당ㅠㅠ..😂
	{
		input.push_back(x);
	}

	int n = input.size(); // 노드의 수
	int i;
	vector<pair<int, int>> tree_child(n, { -1,-1 }); //각 노드의 left, right
	
	for (i = 1; i < n; i++)
	{
		pushNode(i, 0, input, tree_child); // input[i]을 트리에 넣는다. root노드는 0번 인덱스.
	}
	
	postorder(0, input, tree_child); // 후위순회 결과를 출력한다

	return 0;
}