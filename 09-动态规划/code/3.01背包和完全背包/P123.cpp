#include <iostream>
#include <cstdio>
using namespace std;

const int N = 210;

int m, n;
int f[N];

int main() {

    scanf("%d%d", &m, &n);

    for(int i = 1; i <= n; i++){
        int w, v;
        scanf("%d%d", &w, &v);
        for(int j = w; j <= m; j++)
            f[j] = max(f[j], v + f[j-w]);
    }
	
    printf("max=%d\n", f[m]);

	return 0;
}



