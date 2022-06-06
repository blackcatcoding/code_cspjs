#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define endtime first
#define ii second

typedef pair<int, int> PII;

struct Range{
    int begin, end;
    bool operator< (const Range &x) const{
        if(begin == x.begin)
            return end < x.end;
        return begin < x.begin;
    }
}range[1010];

int n;

int main() {

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%d%d", &range[i].begin, &range[i].end);

    sort(range + 1, range + n + 1);

    int ed = 0, ans = 0;

    for(int i = 0; i < n; i++){
        priority_queue<PII, vector<PII>, greater<PII> > heap;

        for(int j = i + 1; j <= n; j++){
            if(range[j].begin >= ed)
                heap.push(make_pair(range[j].end, j));
        }

        if(!heap.empty()){
            ed = heap.top().endtime;
            i = heap.top().ii;
            ans++;
        }
        else
            break;
    }

    printf("%d\n", ans);
	
	return 0;
}
