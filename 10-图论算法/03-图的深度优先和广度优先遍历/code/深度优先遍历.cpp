#include <iostream>
using namespace std;

int g[101][101], vis[101], n, m, a, b;
void dfs(int i);
int main() {
	cin >> n >> m;
	for (int k = 1; k <= m; k++) {
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	
	// ÿ������Ϊ��㣬����ͼ����Ϊ��һ��ÿ�����㶼���Ա�������ͼ 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	return 0;
}

void dfs(int i) {
	cout << i << " ";
	vis[i] = 1;
	for (int j = 1; j <= n; j++) {
		if (g[i][j] && !vis[j]) {
			dfs(j);
		}
	}
}
