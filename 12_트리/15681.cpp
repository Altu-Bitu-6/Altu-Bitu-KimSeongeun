#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int root, vector<vector<int>>& tree, vector<int> &subNode, vector<int> &visit) {

	int size = tree[node].size(); // 연결된 간선 수

	// 리프 노드이면 1 저장
	if (size == 1 && node != root) {
		subNode[node] = 1;
		return;
	}

	// (자식 노드의 총합) + (본인 1) 저장
	int nodeSum = 0;
	for (int i = 0; i < size; i++) {

		int v = tree[node][i];
		if (visit[v] == 0) {
			visit[v] = 1;
			dfs(v, root, tree, subNode, visit);
			nodeSum += subNode[v];
		}
	}
	subNode[node] = nodeSum + 1;

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, r, q;
	int i;

	cin >> n >> r >> q;
	vector<vector<int>> tree(n + 1, vector<int>(0));
	for (i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x; cin >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	vector<int> subNode(n + 1, 0); // i가 루트인 서브트리의 정점 수
	vector<int> visit(n + 1, 0); // 노드 i를 계산했는지 체크 (자식 노드가 부모 노드를 더하지 않기 위해)

	visit[r] = 1;
	dfs(r, r, tree, subNode, visit); // 각 정점의 서브 노드 개수를 저장한다

	for (i = 1; i <= q; i++)
	{
		int u;
		cin >> u;
		cout << subNode[u] << "\n";
	}
	return 0;
}