#include <iostream>
using namespace std;

int g[1001][1001], du[1001], circuit[1001], n, e, cnt=0, x, y, k, istart=1;
void dfs(int i);
int main() {
	cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		cin >> x >> y;
		g[x][y] = g[y][x] = 1;
		du[x]++;
		du[y]++;
	}

	// 统计奇点个数
	for (int i = 1; i <= n; i++) {
		if (du[i] % 2 == 1) {
			istart = i;
			k++;
		}
	}

	if (k == 0 || k == 2) {
		dfs(istart);
		for (int i = 1; i <= cnt; i++)
			cout << circuit[i] << " ";

	}
	else {
		cout << -1;
	}
	return 0;
}

void dfs(int i) {
	for (int j = 1; j <= n; j++) {
		if (g[i][j]) {
			g[i][j] = g[j][i] = 0;
			dfs(j);
		}
	}
	circuit[++cnt] = i;
}
