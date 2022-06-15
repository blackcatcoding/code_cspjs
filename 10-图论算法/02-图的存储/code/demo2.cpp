#include <iostream>
#include <cstdio>
using namespace std;

const int N = 110;

int n, m;
int g[N][N];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << g[i][j] << " ";
        puts("");
    }
	
	return 0;
}

