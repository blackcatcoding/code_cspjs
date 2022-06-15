#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// 创建一个队列容器que
queue<int> que;
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.pop();
    cout << que.size() << " " << que.empty() << endl;
    cout << que.front() << " " << que.back() << endl;


	// fclose(stdin);
	// fclose(stdout);

	return 0;
}
