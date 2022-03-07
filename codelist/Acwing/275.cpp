#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, f[109][59][59];
int g[59][59];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(f, -1, sizeof(f));
    f[0][1][1] = 0;
    for(int i = 0; i <= n + m - 2; i++) {
        for(int j = 1; j <= i + 1; j++) {
            for(int k = 1; k <= i + 1; k++) if(f[i][j][k] != -1) {
                int a = i + 2 - j;
                int b = i + 2 - k;
                for(int p = 0; p < 4; p++) {
                    int xx1 = j + (p & 1), yy1 = a + !(p & 1);
                    int xx2 = k + (p >> 1 & 1), yy2 = b + !(p >> 1 & 1);
                    if(xx1 > n || yy1 > m || xx2 > n || yy2 > m) continue;
                    if(xx1 == xx2 && yy1 == yy2) f[i + 1][xx1][xx2] = max(f[i + 1][xx1][xx2], f[i][j][k] + g[xx1][yy1]);
                    else f[i + 1][xx1][xx2] = max(f[i + 1][xx1][xx2], f[i][j][k] + g[xx1][yy1] + g[xx2][yy2]);
                }
            }
        }
    }
    cout << f[n + m - 2][n][n] << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}