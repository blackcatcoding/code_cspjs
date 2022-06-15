#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110, M = N * N;

int n, m;
int h[N], to[M], w[M], ne[M], idx = 0;

void add(int a, int b, int c){
    to[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main() {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);

    }

    for(int i = 1; i <= n; i++){
        // cout << h[i] << " ";
        // for(int j = h[i]; ~j; j = ne[j])
        //     cout << to[j] << " ";
        // puts("");
        printf("顶点%d: ", i);
        
        for(int j = h[i]; ~j; j = ne[j])
            printf("%d %d  |  ", to[j], w[j]);
        puts("");
        
    }
	
	return 0;
}

/*
4 5
1 3 7
2 4 6
1 2 5
4 3 8
1 4 9
*/
