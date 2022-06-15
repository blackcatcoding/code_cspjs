#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);

	long long istart, iend;
	long long x1, y1, x2, y2;
	double dis = 0;
	cin >> istart >> iend;
	while (cin >> x1 >> y1 >> x2 >> y2)
		dis += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	double ans = dis * 2 / 1000 / 20;
	long long h = (long long)(ans);
	long long m = (long long)((ans - h) * 60 + 0.5);

	printf("%lld:%02lld", h, m);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
