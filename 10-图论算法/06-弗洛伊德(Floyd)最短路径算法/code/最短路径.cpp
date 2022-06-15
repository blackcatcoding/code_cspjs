#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double g[101][101];
int a[101][3], n, m, x, y, s, e;

double dist(int x, int y); 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2];
	cin >> m;
	memset(g, 0x7f, sizeof(g));
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		
		g[x][y] = g[y][x] = dist(x, y);
	}
	cin >> s >> e;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j && i != k && j != k && g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
	printf("%.2lf", g[s][e]);
	return 0;
}

double dist(int x, int y){
	double t1 = pow(double(a[x][1] - a[y][1]), 2);
	double t2 = pow(double(a[x][2] - a[y][2]), 2);
	double t = sqrt(t1 + t2);
	return t;
}
