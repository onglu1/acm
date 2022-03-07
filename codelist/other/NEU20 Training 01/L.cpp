#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 1009;
int n, m, g[N][N];
int cnt[N];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int l = 1, r = min(n, m);
    while(l <= r) {
        int x = Mid;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i < x; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[j] += g[i][j];
            }
        }
        int f = 0;
        for(int i = x; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[j] += g[i][j];
            }
            int now = 0;
            for(int j = 1; j < x; j++) {
                now += cnt[j];
            }
            for(int j = x; j <= m; j++) {
                now += cnt[j];
                if(now <= 1) {
                    f = 1;
                    goto qwq;
                }
                now -= cnt[j - x + 1];
            }
            for(int j = 1; j <= m; j++) {
                cnt[j] -= g[i - x + 1][j];
            }
        }
        qwq:
        if(f == 1) {
            l = x + 1 ;
        } else r = x - 1;

    }
    cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
/*
2
10 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
20 10
1 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0
 */