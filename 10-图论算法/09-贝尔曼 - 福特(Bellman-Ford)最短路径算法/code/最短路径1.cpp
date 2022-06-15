#include <iostream>
#include <cstring>
using namespace std;

int dis[101], u[101], v[101], w[101], n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	for (int k = 1; k <= n - 1; k++)
		for (int i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	return 0;
}

/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
*/ 
