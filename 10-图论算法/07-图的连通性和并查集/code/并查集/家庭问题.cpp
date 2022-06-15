#include <iostream>
#include <cstdio>

using namespace std;
const int N = 101;
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
	
	for(int i=1;i<=n;i++)
		a[find(i)]++;
		
	int cnt1=0, cnt2=0;
    for(int i=1;i<=n;i++) // 计算家庭最大成员 
        if(a[i]>cnt2)
            cnt2=a[i];
    for(int i=1;i<=n;i++)
        if(father[i]==i)// 自己是这个家庭的father，那就是一个家庭 
            cnt1++;
	cout << cnt1 << " " << cnt2 << endl;
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
