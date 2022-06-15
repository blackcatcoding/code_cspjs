#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x7fffffff, N = 501;

int n, m, g[N][N], du[N], path[N];
int ibegin = INF;
int cnt = 0;

void dfs(int i);
int main() {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x][y]++;
		g[y][x]++;
		du[x]++;
		du[y]++;
		n = max(n, max(x, y));
		ibegin = min(ibegin, min(x, y));
	}
	int istart = ibegin;
	for (int i = ibegin; i <= n; i++) {
		if (du[i] % 2 == 1) {
			istart = i;
			break;
		}
	}
	dfs(istart);
	for (int i = cnt; i >= 1; i--)
		cout << path[i] << endl;
	return 0;
}

void dfs(int i) {
	for (int j = ibegin; j <= n; j++) {
		if (g[i][j]) {
			g[i][j]--;
			g[j][i]--;
			dfs(j);
		}
	}
	path[++cnt] = i;
}
