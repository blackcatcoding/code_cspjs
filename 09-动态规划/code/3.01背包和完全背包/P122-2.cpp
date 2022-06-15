#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m, n;
int f[201];

int main() {
	
    scanf("%d%d", &m, &n);

    for(int i = 1; i <= n; i++){
        int w, v;
        scanf("%d%d", &w, &v);

        for(int j = m; j >= w; j--){
            f[j] = max(f[j], v + f[j-w]);
        }
    }

    printf("%d\n", f[m]);

	return 0;
}



