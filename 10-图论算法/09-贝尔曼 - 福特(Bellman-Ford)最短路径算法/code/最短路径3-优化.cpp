#include <iostream>
#include <cstring>
using namespace std;

int dis[101], u[101], v[101], w[101], n, m, bak[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	for (int k = 1; k <= n - 1; k++) {
		for (int i = 1; i <= n; i++)
			bak[i] = dis[i];

		for (int i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];

		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (bak[i] != dis[i]) {
				check = true;
				break;
			}
		}
		if (!check)
			break;
	}
	
	// 检测负权回路
	bool flag = 0;
	for (int i = 1; i <= n; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = true;
	cout << flag << endl;
	if (flag)
		cout << "此图含有负权回路";
	else {
		for (int i = 1; i <= n; i++)
			cout << dis[i] << " ";
	}
	
	return 0;
}

/*
5 5
2 3 2
1 2 -3
1 5 -50
4 5 2
3 4 3
*/ 
