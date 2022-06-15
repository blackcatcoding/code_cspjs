#include <iostream>
#include <cstdio>
#define N 201
using namespace std;
int n;
bool g[N][N];
int father[N];

int ans = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		while (cin >> t && t != 0)
			g[i][t] = true;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != k && j != k && i != j)
					g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j])
				father[j] = father[i];
	for (int i = 1; i <= n; i++)
		if (father[i] == i)
			ans++;

	cout << ans << endl;
	return 0;
}

/*
5
2 4 3 0
4 5 0
0
0
1 0
*/
