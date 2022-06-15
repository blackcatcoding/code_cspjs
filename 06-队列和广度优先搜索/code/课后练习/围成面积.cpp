#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
	int x;
	int y;
};

int np[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};


int a[11][11];
bool book[11][11];
int n, m;
int ans = 0;
void bfs(int x, int y);
int main() {

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> a[i][j];


	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if ((i == 1 || i == 10 || j == 1 || j == 10) && a[i][j] == 0 && !book[i][j])
				bfs(i, j);
		}
	}

	ans = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (a[i][j] == 0 && !book[i][j]) {
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

			if (nx >= 1 && nx <= 10 && ny >= 1 && ny <= 10 && !book[nx][ny] && a[nx][ny] == 0) {

				book[nx][ny] = true;	// 标记下一个连接点

				Node newnode;
				newnode.x = nx;
				newnode.y = ny;

				que.push(newnode);	// 新节点入队
				ans++;
			}
		}
		que.pop();	// 队首元素出队
	}
}

/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 1 1 1 1 0 0
1 0 0 0 0 1 1 0 1 0
0 0 1 0 0 1 1 0 1 1
1 1 1 1 1 1 0 0 1 1
1 1 1 1 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 1 1 0 0 0 0 0 0
*/