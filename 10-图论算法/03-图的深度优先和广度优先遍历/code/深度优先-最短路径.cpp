#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x7fffffff;
int n, m, g[101][101], vis[101];
int mindis = INF;
void dfs(int cur, int dis);
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = z;
	}

	vis[1] = 1;
	dfs(1, 0);
	cout << mindis;
	return 0;
}

void dfs(int cur, int dis) {
	if (cur == 5) {
		if (dis < mindis)
			mindis = dis;
		return;
	}

	for (int j = 1; j <= n; j++) {
		if (g[cur][j]!=INF && !vis[j]) {
			vis[j] = 1;
			dfs(j, dis + g[cur][j]);
			vis[j] = 0;
		}
	}
}

/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/