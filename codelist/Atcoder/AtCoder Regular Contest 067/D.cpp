#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 5e3 + 1009;
int n, m, a[N];
int maxv[N], g[N][209];

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = -(1ll << 61) + 1;
    cin >> n >> m;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        int dis = 0, now = 0;
        for(int j = 1; j <= m; j++) maxv[j] = g[i][j], now += maxv[j];
        ans = max(ans, now);
        for(int j = i + 1; j <= n; j++) {
            dis = a[j] - a[i];
            for(int k = 1; k <= m; k++) {
                if(g[j][k] > maxv[k]) {
                    now += g[j][k] - maxv[k];
                    maxv[k] = g[j][k];
                }
            }
            ans = max(ans, now - dis);
//            if(i == 1 && j == 5) {
//                cout << now << " " << dis << endl;
//                for(int k = 1; k <= m; k++) cout << maxv[k] << endl;
//            }
        }
    }
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * 假设枚举最终走到哪个餐厅，那么每张票只会在最好用的餐厅被用掉？那不是傻逼题吗
 *
 */