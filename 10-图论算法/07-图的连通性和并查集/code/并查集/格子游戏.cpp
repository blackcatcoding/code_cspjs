#include <iostream>
#include <cstdio>

using namespace std;
const int N = 201;

struct Node {
	int x;
	int y;
}father[N][N];

int n, m;

void buildset();
Node find(Node k);
void merge(Node u, Node v);
int main() {

	cin >> n >> m;

	buildset();

	for (int i = 1; i <= m; i++) {
		int x, y;
		char ch;
		cin >> x >> y >> ch;
		Node k1, k2;
		if (ch == 'D') {
			k1 = find(father[x][y]);
			k2 = find(father[x + 1][y]);
		}

		if (ch == 'R') {
			k1 = find(father[x][y]);
			k2 = find(father[x][y + 1]);
		}

		if ((k1.x == k2.x) && (k1.y == k2.y)) {
			cout << i << endl;
			return 0;
		}
		else
			merge(k1, k2);
	}
	cout << "draw" << endl;
	return 0;
}
void buildset() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			father[i][j].x = i;
			father[i][j].y = j;
		}
	}
}
Node find(Node k) {
	if (father[k.x][k.y].x != k.x || father[k.x][k.y].y != k.y)
		father[k.x][k.y] = find(father[k.x][k.y]);
	return father[k.x][k.y];
}
void merge(Node u, Node v) {
	father[u.x][u.y] = v;
}

