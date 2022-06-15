#include <iostream>
#include <cstdio>

using namespace std;
// 定义队列大小
const int N = 8;
// 队列数组
int que[N];

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
    push(3);
    push(5);
    push(1);
    push(4);
    push(9);
    push(6);
    push(7);
    pop();
    pop();
    pop();
    pop();
    pop();
    push(2);
    push(8);
    push(5);
    push(1);
    push(4);
    push(9);
    cout << size() << endl;
    cout << empty() << endl;
    cout << front() << endl;
    cout << back() << endl;
	// fclose(stdin);
	// fclose(stdout);

	return 0;
}

void push(int elem){
    if((tail+1)%N != head%N){
        que[tail] = elem;
        tail = (tail+1) % N;
    }
    else{
        cout << "队列已满，不可继续添加元素" << endl;
    }
}

int pop(){
    if(head != tail){
        int ret = que[head];
        head = (head+1)%N;
        return head;
    }
    return -1;
}
bool empty(){
    return head == tail;
}
int size(){
    return (tail - head + N) % N;
}
int front(){
    if(head != tail)
        return que[head];
}
int back(){
    if(head != tail){
        int i = (tail-1+N)%N;
        return que[i];
    }
}

