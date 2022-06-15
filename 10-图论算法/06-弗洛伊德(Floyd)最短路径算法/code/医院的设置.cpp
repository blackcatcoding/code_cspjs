#include <iostream>
using namespace std;

const int INF = 0x7fffffff/3;
int g[101][101], people[101], n;
int main() {
	cin >> n;
	// ���˶Խ��ߣ�ȫ�����ݳ�ʼ��Ϊ�����
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

	// �н�����
	for (int k = 1; k <= n; k++)
		// ��һ�������
		for (int i = 1; i <= n; i++)
			// �ڶ��������
			for (int j = 1; j <= n; j++)
				if (i != j && i != k && j != k && g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];	// �ɳڲ���

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << g[i][j] << " ";
		cout << endl;
	}*/
	int mindis = 0x7fffffff;
	// ��ÿ�����ж���ΪҽԺ���ҳ���С����
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