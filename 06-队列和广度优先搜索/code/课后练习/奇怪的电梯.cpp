#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
	int floor;	// ���ݲ���
	int step;	// ��������
};

int n, a, b;
int k[201];
bool book[201];
bool flag = false;
queue<Node> que;
void bfs();
int main() {
	cin >> n >> a >> b;		// 5 1 5
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	if (a == b) {
		cout << 0;
		return 0;
	}
	bfs();

	if (flag)
		cout << que.back().step;
	else
		cout << -1;

	return 0;
}

void bfs() {
	Node startnode;
	startnode.floor = a;
	startnode.step = 0;
	book[a] = true;
	que.push(startnode);

	while (!que.empty()) {
		int cur = que.front().floor;	// ��ȡ����¥����
		int up = cur + k[cur];	// ������
		int down = cur - k[cur]; // ������
		// ������
		if ((up <= n) && !book[up]) {
			book[up] = true;
			Node newnode;
			newnode.floor = up;
			newnode.step = que.front().step + 1;
			que.push(newnode);
		}
		// ������
		if ((down >= 1) && !book[down]) {
			book[down] = true;
			Node newnode;
			newnode.floor = down;
			newnode.step = que.front().step + 1;
			que.push(newnode);
		}
		// ����Ƿ񵽴�Ŀ���
		if (up == b || down == b) {
			flag = true;
			return;
		}
		que.pop();
	}
}

/*
5 5 5
3 3 1 2 5
*/