#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x7fffffff;

struct Edge {
	int next;	// ��һ���ߵı��
	int to;		// �����䵽��ĵ�
	int w;	    // ������Ȩ��
}edge[101];
int n, m;	// n�����㣬m����
int num_edge = 0;
int head[101], dis[101];
bool book[101];
queue<int> que;

void add_edge(int from, int to, int w);
int main() {
	cin >> n >> m;
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;

	// �����ڽӱ�
	for (int i = 1; i <= m; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		add_edge(from, to, w);
	}

	que.push(1);	 // ����һ�������
	book[1] = true;	 // ����һ������
	while (!que.empty()) {
		int cur = que.front();	// ��ǰ����Ϊ����Ԫ��
		int i = head[cur];		// �뵱ǰ�����ӵıߵ����
		book[cur] = false; 
		while (i) {
			int np = edge[i].to;	// ��ǰ�ߵ��յ�
			if (dis[np] > dis[cur] + edge[i].w) {
				dis[np] = dis[cur] + edge[i].w;

				if (!book[np]) {
					que.push(np);
					book[np] = true;
				}
			} 
			i = edge[i].next;

		}
		que.pop();
	}

	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	return 0;
}

void add_edge(int from, int to, int w) {
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;
	edge[num_edge].w = w;
}

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
