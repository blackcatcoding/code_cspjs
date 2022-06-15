#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 10001;
double dis[N], w[N];
int u[N], v[N], a[N][3], n, m, s, t;

int main() {
	cin >> n;	// n个顶点
	for (int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2];	// 读入坐标
	
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		double t1 = pow(a[u[i]][1] - a[v[i]][1], 2.0);
		double t2 = pow(a[u[i]][2] - a[v[i]][2], 2.0);
		w[i] = sqrt(t1 + t2);
	}
	cin >> s >> t;
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;

	for (int k = 1; k <= n - 1; k++) {
		for (int i = 1; i <= m; i++) {
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
			if (dis[u[i]] > dis[v[i]] + w[i])
				dis[u[i]] = dis[v[i]] + w[i];
		}
			
	}
	printf("%.2lf", dis[t]);
	return 0;
}