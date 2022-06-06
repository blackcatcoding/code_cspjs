#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {

    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);

    cout << stk.size() << " " << stk.top() << endl;

    stk.pop();
    stk.pop();

    cout << stk.size() << " " << stk.top() << endl;

	return 0;
}

