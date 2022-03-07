#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
int f[N];
int solve() {
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            f[i] = max(f[i], f[j] + (i - j) * (i - j + 1) / 2 - (a[i] - a[j]));
        }
        f[i] = max(f[i], f[i - 1]);
    }
    for(int i = n - 1; i >= 1; i--) a[i + 1] -= a[i];
    return f[n];
}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
//        a[i] += a[i - 1];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int p, x;
        cin >> p >> x;
        swap(x, a[p]);
        cout << solve() << endl;
        swap(x, a[p]);
    }
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}