#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 4;
const int g[5][5] = {
        {0, -1, 1},
        {1, 0, -1},
        {-1, 1, 0}
};
struct node {
    int x, y, id;
} a[3], b[3];
bool operator<(const node &a, const node& b) {
    return a.x - a.y > b.x - b.y;
}
int n, k;
void work() {
    a[0].id = 0; a[1].id = 1; a[2].id = 2;
    cin >> a[0].x >> a[1].x >> a[2].x;
    cin >> a[0].y >> a[1].y >> a[2].y;
    int ans = (1ll << 61) - 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) if(i != j) {
            for(int k = 0; k < 3; k++) if(i != k && j != k) {
                b[0] = a[0]; b[1] = a[1]; b[2] = a[2];
                int t;
                int sc = 0;
                for(int p = 0; p < 3; p++) {
                    int tt = 0;
                    if(p == 0) tt = i;
                    else if(p == 1) tt = j;
                    else tt = k;

                    t = min(b[tt].x, b[(tt + 3 + 1) % 3].y);
                    b[tt].x -= t;
                    b[(tt + 3 + 1) % 3].y -= t;
                    sc += t;
                    if(b[tt].x > 0) {
                        t = min(b[tt].x, b[tt].y);
                        b[tt].x -= t;
                        b[tt].y -= t;
                    }
                    if(b[tt].x > 0) {
                        t = min(b[tt].x, b[(tt + 3 - 1) % 3].y);
                        b[tt].x -= t;
                        b[(tt + 3 + 1) % 3].y -= t;
                        sc -= t;
                    }
                }
                ans = min(ans, sc);

            }
        }
    }
    cout << ans << endl;

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}