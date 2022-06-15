#include <iostream>
using namespace std;
const int N = 1005;
int n, m, x, length, g[N][N], ans[N];
bool vis[N], nodex[N];

void dfs(int last, int cur);
int main() {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}
	
	for (x = 1; x <= n; x++) {
		if (!nodex[x]) {
			length = 0;
			dfs(0, x);
			nodex[x] = true;
		}
	}
	
	return 0;
}

void dfs(int last, int cur) {
	vis[cur] = true;
	ans[++length] = cur;
	for (int i = 1; i <= n; i++) {
		if (g[cur][i] && i == x && x != last) {
			ans[++length] = i;
			for (int j = 1; j <= length; j++) {
				cout << ans[j] << " ";
			}
			cout << endl;

			length--;
		}
		if (!vis[i] && g[cur][i] && !nodex[i])
			dfs(cur, i);
	}
	length--;
	vis[cur] = false;
}
