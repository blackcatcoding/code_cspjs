#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int g[N][N];

int main() {

    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%10d ", g[i][j]);
        puts("");
    }
	
	return 0;
}

