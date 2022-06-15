#include <iostream>
#include <cstdio> 
using namespace std;
double g[2001][2001], dis[2001];
int n, m, A, B;
bool book[2001];

void init();
void dijkstra(int A);
int main(){
	init();
	dijkstra(A);
	printf("%.8lf", 100/dis[B]);
	return 0;
}

void init(){
	cin >> n >> m;	// n¸ö¶¥µã mÌõ±ß
	int x, y;
	double z;
	for(int i=1;i<=m;i++){
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = (100-z)/100;
	}
	cin >> A >> B;
}
void dijkstra(int A){
	for(int i=1;i<=n;i++)
		dis[i] = g[A][i];
	dis[A] = 1;
	book[A] = true;
	int u = 0;
	for(int i=1;i<=n-1;i++){
		double maxnum = 0;
		for(int j=1;j<=n;j++){
			if(!book[j] && dis[j] > maxnum){
				u = j;
				maxnum = dis[j];
			}
		}
		book[u] = true;
		if(u == B)
			break;
		for(int v=1;v<=n;v++){
			if(!book[v] && dis[u]*g[u][v]>dis[v])
				dis[v] = dis[u]*g[u][v];
		}
	}
}


















