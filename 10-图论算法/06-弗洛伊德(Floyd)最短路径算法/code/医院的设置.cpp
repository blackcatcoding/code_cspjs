#include <iostream>
using namespace std;

const int INF = 0x7fffffff/3;
int g[101][101], people[101], n;
int main() {
	cin >> n;
	// 除了对角线，全部数据初始化为无穷大
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (i != j)
				g[i][j] = INF;
	}

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> people[i] >> x >> y;
		if (x)
			g[x][i] = g[i][x] = 1;
		if (y)
			g[y][i] = g[i][y] = 1;
	}

	// 中介点遍历
	for (int k = 1; k <= n; k++)
		// 第一个点遍历
		for (int i = 1; i <= n; i++)
			// 第二个点遍历
			for (int j = 1; j <= n; j++)
				if (i != j && i != k && j != k && g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];	// 松弛操作

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << g[i][j] << " ";
		cout << endl;
	}*/
	int mindis = 0x7fffffff;
	// 将每个城市都作为医院，找出最小距离
	for (int i = 1; i <= n; i++) {
		int total = 0;
		for (int j = 1; j <= n; j++) {
			total += g[i][j] * people[j];
		}
		if (total < mindis)
			mindis = total;
	}
	cout << mindis;
	return 0;
}