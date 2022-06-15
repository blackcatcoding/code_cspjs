#include <iostream>
#include <queue>
using namespace std;

int head[101], vis[101], num_edge=0, n, m, a, b;
struct Edge {
	int next;
	int to;
}edge[1001];

void add_edge(int from, int to);
void bfs(int i);
int main() {
	cin >> n >> m;
	for (int k = 1; k <= m; k++) {
		cin >> a >> b;
		add_edge(a, b);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i);
		}
	}
	return 0;
}

void add_edge(int from, int to) {
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;
}

void bfs(int i) {
	cout << i << " ";
	vis[i] = 1;
	queue<int> q;
	q.push(i);
	int cur, nextNum, to;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		nextNum = head[cur];
		while (nextNum) {
			to = edge[nextNum].to;
			if (!vis[to]) {
				vis[to] = 1;
				cout << to << " ";
				q.push(to);
			}
			nextNum = edge[nextNum].next;
		}
		
	}
}
