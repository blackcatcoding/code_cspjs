#include <iostream>
#include <cstdio>
using namespace std;

const int N = 6010;

int n, m;
int f[N];

int main() {
	
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        for(int j = m; j >= 1; j--){
            for(int k = 0; k <= s; k++){
                if(j - k * v < 0)
                    break;
                f[j] = max(f[j], k * w + f[j - k * v]);
            }
        }
    }

    printf("%d\n", f[m]);

	return 0;
}
