#include <iostream>
#include <cstdio>
#define N 101
using namespace std;

int n, m;
bool g[N][N];
int ans = 0;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u][v] = true;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != k && j != k && i != j)
					g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
	
	for (int i = 1; i <= n; i++) {
		int iless = 0, igreater = 0;
		for (int j = 1; j <= n; j++) {
			if (g[i][j])
				iless++;
			if (g[j][i])
				igreater++;
		}
		if (iless >= (n + 1) / 2 || igreater >= (n + 1) / 2)
			ans++;
	}

	cout << ans << endl;

	return 0;
}

/*
5 4
2 1
4 3
5 1
4 2
*/