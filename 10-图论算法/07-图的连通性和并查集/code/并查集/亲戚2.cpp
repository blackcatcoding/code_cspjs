#include <iostream>
#include <cstdio>

using namespace std;
const int N = 201;
int father[N];
int a[N];
int n, m;
inline int read();
void buildset();
int find(int k);
void merge(int u, int v);
int main() {
	n = read();
	m = read();

	buildset();

	for (int i = 1; i <= m; i++) {
		int x, y;
		x = read();
		y = read();
		int u = find(x);
		int v = find(y);
		if (u != v)
			merge(u, v);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		x = read();
		y = read();
		if (find(x) == find(y))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
void buildset() {
	for (int i = 1; i <= n; i++)
		father[i] = i;	// 建立新的集合，仅有一个成员i，自己是老大
}
int find(int k) {
	if (father[k] != k)
		father[k] = find(father[k]);	// 寻找根节点标号并压缩路径
	return father[k];
}
void merge(int u, int v) {
	father[v] = u;
}

inline int read() {
	int x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}

	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}
