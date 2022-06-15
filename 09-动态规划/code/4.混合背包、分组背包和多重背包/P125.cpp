#include <iostream>
#include <cstdio>
using namespace std;

int m, n;
int f[210];

int main() {

    scanf("%d%d", &m, &n);

    for(int i = 1; i <= n; i++){
        int w, v, p;
        scanf("%d%d%d", &w, &v, &p);

        if(p == 0)
            for(int j = w; j <= m; j++)
                f[j] = max(f[j], f[j-w] + v);
        else{
            for(int j = m; j >= 1; j--){
                for(int k = 1; k <= p; k++){
                    if(j - k*w < 0)
                        break;
                    f[j] = max(f[j], f[j-k*w] + k*v);
                }
            }
        }
    }

    printf("%d\n", f[m]);
	return 0;
}
