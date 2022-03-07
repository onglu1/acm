#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
int f[N][3];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> f[1][0];
    f[1][1] = -(1ll << 61);
    f[1][2] = -(1ll << 61);
    for(int i = 2; i <= n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+') {
            f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]}) + x;
            f[i][1] = max(f[i - 1][1] - x, f[i - 1][2] + x);
            f[i][2] = f[i - 1][2] + x;
        } else {
            f[i][0] = max({f[i - 1][0] - x, f[i - 1][1] + x, f[i - 1][2] + x});
            f[i][1] = max(f[i - 1][1], f[i - 1][2]) + x;
            f[i][2] = f[i - 1][2] - x;

            f[i][1] = max(f[i][1], f[i - 1][0] - x);
            f[i][2] = max(f[i][2], f[i - 1][1] + x);
        }
    }
//    for(int i = 0; i < 3; i++) {
//        for(int j = 1; j <= n; j++) {
//            cout << f[j][i] << " ";
//        }
//        cout << endl;
//    }
    cout << max({f[n][0], f[n][1], f[n][2]}) << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}