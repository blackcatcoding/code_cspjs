#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int g[101][101];
bool book[101];
int minw[101];  // 存放(u,v)最小生成边
int n;
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    cin >> n;   // 电脑数目

    // 读取邻接矩阵
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> g[i][j];

    memset(minw, 0x7f, sizeof(minw));
    minw[1] = 0;

    for(int i=1;i<=n;i++){
        int k = 0;
        for(int j=1;j<=n;j++){
            if(!book[j] && minw[j]<minw[k])
                k = j;
        }

        book[k] = true;

        for(int j=1;j<=n;j++){
            if(!book[j] && g[k][j]<minw[j])
                minw[j] = g[k][j];
        }
    }
    
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans += minw[i];

    cout << ans << endl;
	// fclose(stdin);
	// fclose(stdout);

	return 0;
}
