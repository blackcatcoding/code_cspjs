#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m, n;
int f[31][201];

int main() {
	
    scanf("%d%d", &m, &n);

    for(int i = 1; i <= n; i++){
        int w, v;
        scanf("%d%d", &w, &v);

        for(int j = 1; j <= m; j++){
            if(j >= w)  f[i][j] = max(f[i-1][j], v + f[i-1][j-w]);
            else f[i][j] = f[i-1][j];
        }
    }

    printf("%d\n", f[n][m]);

	return 0;
}



