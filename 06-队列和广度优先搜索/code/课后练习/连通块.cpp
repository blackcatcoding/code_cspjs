#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node{
	int x;
	int y;
};
int np[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
int a[101][101];
bool book[101][101];
int n, m;
int ans = 0;

void bfs(int x, int y);
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1 && !book[i][j]) {
				bfs(i, j);
			}
		}
	}

	cout << ans;
	return 0;
}

void bfs(int x, int y) {
	queue<Node> que;
	Node startnode;
	startnode.x = x;
	startnode.y = y;

	book[x][y] = true;
	que.push(startnode);
	ans++;
	while (!que.empty()) {

		for (int i = 0; i < 4; i++) {

			int nx = que.front().x + np[i][0];
			int ny = que.front().y + np[i][1];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !book[nx][ny] && a[nx][ny] == 1) {

				book[nx][ny] = true;	// 标记下一个连接点

				Node newnode;
				newnode.x = nx;
				newnode.y = ny;
				que.push(newnode);	// 新节点入队
			}
		}
		que.pop();	// 队首元素出队
	}
	return;
}
