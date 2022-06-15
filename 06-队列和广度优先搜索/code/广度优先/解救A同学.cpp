#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// 创建一个结构体
struct Node{
    int x;
    int y;
    int step;   // 到达当前点（x,y）所需最少步数
};

int a[101][101];    // 用于存储迷宫原始数据
bool book[101][101];    

int n, m;
int start_x, start_y, end_x, end_y;

bool flag = false;  // 假定不能到达终点

int np[4][2] = {
    {0, 1}, // 向右
    {1, 0}, // 向下
    {0, -1}, // 向左
    {-1, 0}, // 向上
};

queue<Node> que;
void bfs();
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    cin >> n >> m;
    
    // 初始化迷宫
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    cin >> start_x >> start_y >> end_x >> end_y;

    bfs();

    if(flag)
        cout << que.back().step;
    else
        cout << -1;

	// fclose(stdin);
	// fclose(stdout);

	return 0;
}


void bfs(){
    // 起点入队 并 标记
    Node startnode;
    startnode.x = start_x;
    startnode.y = start_y;
    startnode.step = 0;    //初始（1,1）位置步数为0
    book[start_x][start_y] = true;  // 标记起点
    que.push(startnode);    // 起点入队

    while(!que.empty()){
        // 右下左上，一次扩展四个方向
        for(int i=0;i<4;i++){
            int nx = que.front().x + np[i][0];
            int ny = que.front().y + np[i][1];

            // 下一个点是否可以走
            // 条件：不能越界，不能是墙，不能被访问过即没有入过队
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]==0 && !book[nx][ny]){
                book[nx][ny] = true;
                Node newnode;
                newnode.x = nx;
                newnode.y = ny;
                newnode.step = que.front().step + 1;
                que.push(newnode);
            }

            // 检测是否到达终点
            if(nx==end_x && ny==end_y){
                flag = true;    // 表示找到A同学
                return;
            }
        }
        que.pop();
    }
}
