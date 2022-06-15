#include <iostream>
#include <cstdio>

using namespace std;
const int N = 205;
int que[N];
int head=0, tail=0;
int n;  // 小朋友人数
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    cin >> n;

    // 初始化队列
    for(int i=0;i<n;i++)
        que[i] = i+1;
    tail = n;

    while(tail - head >= 2){
        cout << que[head++] << " ";
        que[tail++] = que[head++];
    }
    
    if(tail - head == 1)
        cout << que[head++];
	// fclose(stdin);
	// fclose(stdout);

	return 0;
}

/*
5

1 3 5 4 2 
*/
