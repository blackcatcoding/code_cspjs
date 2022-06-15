#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// 节点数1-8  A-H
int map[9][9] = {
	{0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,1,0,1,1},
	{0,0,1,1,1,1,0,1,1},
	{0,0,1,1,0,0,1,1,1},
	{0,0,1,0,1,1,1,0,1},
	{0,1,1,0,1,1,1,0,0},
	{0,0,0,1,1,1,1,1,0},
	{0,1,1,1,0,0,1,1,0},
	{0,1,1,1,1,0,0,0,1} 
};

bool book[101];
int pre[101];   // pre[i]保存的是每一个点的前驱节点

queue<int> que;
void bfs();
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    bfs();
    int k = 8;
    cout << char(k+64);
    while(pre[k]){
        cout << "-" << char(pre[k]+64);
        k = pre[k];
    }

	// fclose(stdin);
	// fclose(stdout);

	return 0;
}

void bfs(){
    que.push(1);
    book[1] = true;
    while(!que.empty()){
        int cur = que.front();  // 获取队首节点
        for(int i=1;i<=8;i++){ // 遍历与队首相连的点
            if(map[cur][i]==0 && !book[i]){
                book[i] = true;
                que.push(i);
                pre[i] = cur;
            }
        }
        que.pop();
    }
}
