#include <iostream>
using namespace std;
int g[101][101], vis[101], n, e, temp, a, b, q[101];
void bfs(int cur);
int main() {
   cin >> n >> e;
   for (int i = 1; i <= e; i++) {
      cin >> a >> b;
      g[a][b] = 1;
   }
   cin >> temp;
   bfs(temp);
   return 0;
}

void bfs(int cur) {
   int head = 1, tail = 1;
   q[tail++] = cur;
   cout << cur << " ";
   vis[cur] = 1;
   while (head < tail) {
      for (int j = 1; j <= n; j++) {
         if (g[q[head]][j] == 1 && !vis[j]) {
            cout << j << " ";
            vis[j] = 1;
            q[tail++] = j;
         }
      }
      head++;
   }
}

