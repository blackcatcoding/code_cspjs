#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 110;

struct Node{
    int v, w;
};

int n, m;
vector<Node> h[N];

int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        h[u].push_back({v, w}); 
        // h[v].push_back({u, w});  无向图
    }

    for(int i = 1; i <= n; i++){
        printf("顶点%d: ", i);
        for(auto x : h[i])
            printf("%d %d  |  ", x.v, x.w);
        puts("");
    }
	
	return 0;
}

