#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

string s;
queue<string> que;
int k;	// k个转换规则
char rules[20][2];
bool book[100001];
int ans;
int turn(string s);

void bfs();
int main() {
	cin >> s;	// 1234 
	cin >> k;	// 3
	cin.ignore();
	for (int i = 0; i < k; i++) 
		cin >> rules[i][0] >> rules[i][1];
	
	bfs();
	cout << ans;
	return 0;
}

int turn(string s) {
	int x = 0;
	for (int i = 0; i < s.size(); i++)
		x = x * 10 + s[i] - '0';
	return x;
}

void bfs() {
	book[turn(s)] = true;
	que.push(s);
	ans = 1;

	while (!que.empty()) {
		for (int i = 0; i < k; i++) {
			// 遍历k次转换
			/*
				2 3
				3 2
				3 5
			*/
			string headstr = que.front();	// 获取队首字符串 1234
			//cout << headstr << endl;
			for (int j = 0; j < headstr.size(); j++) {
				if (headstr[j] == rules[i][0]) {
					//cout << i << " " << j << " " << headstr[j] << " " << rules[j][0] << endl;
					string newstr = headstr;
					newstr[j] = rules[i][1];
				
					if (!book[turn(newstr)]) {
						ans++;
						//cout << ans << " " << headstr[j] << " " << rules[j][0] << " " << newstr << endl;
						book[turn(newstr)] = true;
						que.push(newstr);	
					}
				}
			}
		}
		que.pop();
	}
}

/*
1234
3
2 3
3 2
3 5

9
*/

/*
234
2
2 5
3 6
*/


