#include <iostream>
#include <cmath>
#include <cstdio> 
using namespace std;
const int INF = 0x7fffffff;
double g[101][101];	// �ڽӾ���
double dis[101];  // dis[i] ��ʾ����㵽i����̾���
bool book[101];	// ��ǽڵ��Ƿ񱻷��ʹ�
int a[101][3];	// �洢����
int n, m, x, y, s, t; 
int main(){
	cin >> n;
	// ��ȡ����ֵ 
	for(int i=1;i<=n;i++)
		cin >> a[i][1] >> a[i][2];
	
	// ��ʼ���ڽӾ���
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				g[i][j] = 0;
			else
				g[i][j] = INF;
		}
	} 
	cin >> m;	// ��ȡm����
	for(int i=1;i<=m;i++){
		cin >> x >> y;
		double t1 = pow(double(a[x][1]-a[y][1]) ,2);
		double t2 = pow(double(a[x][2]-a[y][2]) ,2);
		g[x][y] = g[y][x] = sqrt(t1+t2);
	} 
	
	// Dijkstra�㷨
	cin >> s >> t;
	book[s] = true;
	for(int i=1;i<=n;i++)
		dis[i] = g[s][i]; 
	int u=0;
	for(int i=1;i<=n-1;i++){
		double minnum = INF;
		for(int j=1;j<=n;j++){
			if(!book[j] && dis[j]<minnum){
				minnum = dis[j];
				u = j;
			}
		}
		book[u] = true;
		for(int v=1;v<=n;v++){
			if(g[u][v]<INF){
				if(dis[v]>dis[u]+g[u][v])
					dis[v] = dis[u]+g[u][v];
			}
		}
	}
	
	printf("%.2lf", dis[t]);
	return 0;
}
