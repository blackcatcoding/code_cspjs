#include <iostream>
#include <cstdio>
using namespace std;

const int N = 15;

int n = 9;
int a[N];
bool book[N];
int cnt = 0;

void dfs(int u){
    if(u > n){
        if(a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]){
            cnt++;
            printf("%d%d%d+%d%d%d=%d%d%d\n", a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;
    }

    for(int i = 1; i <= n; i++){
        if(book[i]) continue;
        a[u] = i;
        book[i] = true;
        dfs(u + 1);
        book[i] = false;
    }
}
int main() {

    // dfs depth first search
    dfs(1);

    cout << cnt / 2 << endl;

	
	return 0;
}

