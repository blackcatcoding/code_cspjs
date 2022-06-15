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
				
	// 检测负边权回路
	bool flag = false;
	for(int i=1;i<=m;i++){
		if(dis[v[i]]>dis[u[i]] + w[i])
			flag = true;
	} 
	if(flag)
		cout << "含有负权回路";
	else{
		for (int i = 1; i <= n; i++)
			cout << dis[i] << " ";
	} 
	
	return 0;
}

/*
5 5
2 3 2
1 2 -3
5 1 -50
4 5 2
3 4 3

5 5
2 3 2
1 2 -3
1 5 -50
4 5 2
3 4 3
*/ 
