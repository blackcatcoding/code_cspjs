#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1010;
char ac[N], bc[N];
int a[N], b[N], c[N];

int main() {

    cin >> ac + 1 >> bc + 1;
    a[0] = strlen(ac + 1);
    b[0] = strlen(bc + 1);

    for(int i = 1; i <= a[0]; i++){
        a[i] = ac[i] - '0';
        b[i] = bc[i] - '0';
        c[i] = a[i] + b[i];
        cout << c[i];
    }

	return 0;
}

