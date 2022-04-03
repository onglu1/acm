
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;

const int N = 5009;
int n, m, k, f[N][N];

int solve(int n, int k) {
    if(f[n][k] != -1) return f[n][k];
    if(n <= m) {
        if(n == 1) return f[n][k] = 0;
        if(k == 1 || k == n) return f[n][k] = 1;
        return f[n][k] = 2;
    }
    f[n][k] = 0x3f3f3f3f;
    int t = (k - 1) / m;
    if(t * m >= 1) f[n][k] = min(f[n][k], solve(n - t * m, k - t * m) + 1);

    t = (k - 1) / m;
    if(n > t * m) f[n][k] = min(f[n][k], solve(t * m, k) + 1);

    t = ((n - 1) / m + 1) * m;
    int xk = (k - 1) / m + 1, yk = (k - 1) % m + 1;
    if(n - t < yk) {
        f[n][k] = min(f[n][k], solve(n - (xk * (yk - 1)) - (t - xk - 1) * m - (n - t), k  - (xk * (yk - 1))) + 1);
    } else {
        f[n][k] = min(f[n][k], solve(n - (xk * (yk - 1)) - (t - xk) * m, k  - (xk * (yk - 1))) + 1);
    }

    if(n - t < yk) {
        if(t / m == xk) f[n][k] = min(f[n][k], solve(n - ((xk - 1) * (n - yk)) - (n - k), k - ((xk - 1) * (n - yk))) + 1);
        else f[n][k] = min(f[n][k], solve(n - ((xk - 1) * (n - yk)) - (n - k), k - ((xk - 1) * (n - yk))) + 1);

    } else {
        f[n][k] = min(f[n][k], solve(n - (xk * (yk - 1)) - (t - xk) * m, k  - (xk * (yk - 1))) + 1);
    }


}
void work() {
    memset(f, -1, sizeof(f));
    cin >> n >> m >> k;
    cout << solve(n, k) << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}