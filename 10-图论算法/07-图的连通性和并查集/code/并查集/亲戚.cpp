#include <iostream>
#include <cstdio>

using namespace std;
const int N = 20001;
int father[N];
int n, m;	// n����  m���ϵ 
void buildset();	// �������� 
int find(int k);	// �ҵ�k���ڼ��ϴ��� 
void merge(int u, int v);		// �ϲ����� 
int main() {
	cin >> n >> m;

	buildset();

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;		// 3 5 
		int u = find(x);
		int v = find(y);
		if (u != v)
			merge(u, v);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
void buildset() {
	for (int i = 1; i <= n; i++)
		father[i] = i;	// �����µļ��ϣ�����һ����Աi���Լ����ϴ�
}
int find(int k) {
	if (father[k] != k)
		return find(father[k]);
	return k;
}
void merge(int u, int v) {
	father[v] = u;
}

/*
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9
*/
