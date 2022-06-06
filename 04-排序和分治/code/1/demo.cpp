#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int a[10] = {1, 3, 3, 3, 4, 4, 4, 4, 8};

    int *lpos, *upos;
    lpos = lower_bound(a, a + 9 + 1, -1);
    upos = upper_bound(a, a + 9 + 1, -1);

    cout << lpos << " " << upos << endl;
    cout << lpos - a << " " << upos - a << endl;

    lpos = lower_bound(a, a + 9 + 1, 1);
    upos = upper_bound(a, a + 9 + 1, 1);
    cout << lpos - a << " " << upos - a << endl;

    lpos = lower_bound(a, a + 9 + 1, 3);
    upos = upper_bound(a, a + 9 + 1, 3);
    cout << lpos - a << " " << upos - a << endl;

    cout << upper_bound(a, a + 9 + 1, 6789) - a << endl;
	
	return 0;
}

