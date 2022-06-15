#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string que[101];
int head=0, tail=0;

int main() {
	freopen("宴请宾客.in", "r", stdin);
	freopen("宴请宾客.out", "w", stdout);
    char ch;
    while(cin >> ch){
        if(ch == 'B')
            cin >> que[tail++];
        
        else{
            if(head!=tail)
                cout << que[head++] << endl;
            
            else
                cout << "None" << endl;
        }
    }

	fclose(stdin);
	fclose(stdout);

	return 0;
}
