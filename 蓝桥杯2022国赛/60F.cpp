#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e5 + 1009;
int d[109][109], g[109][109], l[109][109];
int nxt[109][109], pre[109][109];
int nt[109], pr[109], head[109];
int n, q;
int test() {
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) g[i][j] = l[i][j];
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int nq = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) nq += g[i][j];
    if(nq > q) return 1;
    else return 0;
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> d[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> l[i][j];

    if(test()) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) g[i][j] = d[i][j];
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)g[i][j] = min(g[i][j], g[i][k] + g[k][j]);


    int nq = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) nq += g[i][j];
    if(nq <= q) {
        cout << 0 << endl;
        return 0;
    }



    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            nxt[i][j] = j + 1;
        }
        nxt[i][n] = 0;
        head[i] = 1;
    }
    for(int i = 1; i <= n; i++) nt[i] = i + 1, pr[i] = i - 1;
    nt[n] = 1; pr[1] = n;
    int now = 0, city = n;
    while(nq > q) {
        if(nt[city] > city) {
            now += nt[city] - city;
        } else {
            now += n - city + nt[city];
        }
        city = nt[city];
        int ok = 1, p = head[city];
        for(int k = head[city]; k; k = nxt[city][k]) {
            if(d[city][k] <= l[city][k]) {
                if(k == head[city]) head[city] = nxt[city][k];
                else {
                    nxt[city][p] = nxt[city][k];
                }
            } else {
                d[city][k] -= 1;
                d[k][city] -= 1;
                p = k;
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) {
                        if(g[i][city] + d[city][k] + g[k][j] < g[i][j]) {
                            nq -= g[i][j] - (g[i][city] + d[city][k] + g[k][j]);
                            g[i][j] = g[i][city] + d[city][k] + g[k][j];
                        }
                        if(g[i][k] + d[k][city] + g[city][j] < g[i][j]) {
                            nq -= g[i][j] - (g[i][k] + d[k][city] + g[city][j]);
                            g[i][j] = g[i][k] + d[k][city] + g[city][j];
                        }
                    }
                }
                ok = 0;
            }
        }
        if(ok) {
            nt[pr[city]] = nt[city];
            pr[nt[city]] = pr[city];
        }
        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << now << endl;
    return 0;
}