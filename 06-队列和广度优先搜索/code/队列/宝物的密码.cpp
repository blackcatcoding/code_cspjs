#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// 定义队列大小
const int N = 101;
// 队列数组
char que[N];

int head=0, tail=0; // 队首指针，队尾指针
void push(int elem);    // 在队尾插入元素
int pop();  // 弹出队首元素，返回值队首元素
bool empty();   // 如果是空队列 true，如果不是空队列 false
int size();     // 获取队列元素个数
int front();    // 获取队首元素
int back();     // 获取队尾元素
int main() {
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
    cin >> que;
    tail = strlen(que);

    while(!empty()){
        cout << front()-48;
        pop();
        if(!empty()){
            push(front());
            pop();
        }
    }


	// fclose(stdin);
	// fclose(stdout);

	return 0;
}

void push(int elem){
    if(tail < N)
        que[tail++] = elem;
}
int pop(){
    if(head != tail)
        return que[head++];
}
bool empty(){
    return head == tail;
}
int size(){
    return tail - head;
}
int front(){
    if(head != tail)
        return que[head];
}
int back(){
    if(head != tail){
       int i = tail - 1;
       return que[i];
    }
}

