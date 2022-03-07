#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 3009;
const int mod = 1e9 + 7;
int n, m, a[N], cnt[N], r[N];
int f[N][N];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%1d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        cnt[i] = a[i] + cnt[i - 1];
    }
    for(int i = 1; i <= n; i++) r[i] = i;
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        r[x] = max(r[x], y);
    }
    r[n + 1] = n + 1;
    for(int i = 1; i <= n; i++) r[i] = max(r[i], r[i - 1]);
    f[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= r[i] - i + 1; j++) if(f[i][j]) {
            int nj = j + cnt[r[i + 1]] - cnt[r[i]];
            if(j != r[i] - i + 1) {
                f[i + 1][nj] = (f[i + 1][nj] + f[i][j]) % mod;
            }
            if(j != 0) {
                f[i + 1][nj - 1] = (f[i + 1][nj - 1] + f[i][j]) % mod;
            }
        }
    }
    int ans = 0;
    ans = f[n][0] + f[n][1];
    cout << ans % mod << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * f[i][j]表示处理到i，最后还有j个1可以随便摆放
 * 每个位置可以选择的范围可以由之前拓展
 * 每一位填0或者1就行
 */