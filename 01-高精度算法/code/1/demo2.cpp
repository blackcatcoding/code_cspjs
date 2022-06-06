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
    c[0] = max(a[0], b[0]);

    for(int i = 1; i <= a[0]; i++)
        a[i] = ac[a[0] + 1 - i] - '0';

    for(int i = 1; i <= b[0]; i++)
        b[i] = bc[b[0] + 1 - i] - '0';

    for(int i = 1; i <= c[0]; i++)
        c[i] = a[i] + b[i];

    for(int i = c[0]; i >= 1; i--)
        cout << c[i];

	return 0;
}

