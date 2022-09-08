#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 1e6 + 1009;
int n, m, a[N], b[N];
int s[N];
int cal(int h, int a) {
    if(h > a) {
        return (1 + a) * a / 2;
    }
    return (1 + h) * h / 2 + h * (a - h);
}
int cal(int h, int a, int l, int r, int b) {
    // cout << h << " " << a << " " << l << " " << r << " " << b << endl;
    if(b == 1) {
        l = a - l + 1;
        r = a - r + 1;
        swap(l, r);
    }
    if(l >= h) return (r - l + 1) * h;
    else if(r <= h) return (l + r) * (r - l + 1) / 2;
    else {
        return (r - h) * h + (l + h) * (h - l + 1) / 2;
    }
}
int check(int h, int l, int r, int L, int R, int maxn) {
    if(L == R) {
        return cal(h, a[L], l - s[L - 1], r - s[L - 1], b[L]) >= maxn;
    }
    int t1 =cal(h, a[L], l - s[L - 1], a[L], b[L]);
    maxn -= t1;
    // cout << t1 << endl;
    int t2 = cal(h, a[R], 1, r - s[R - 1], b[R]);
    maxn -= t2;
    // cout << t2 << endl;
    // cout << maxn << endl;
    // cout << cal(2, 4) << endl;
    if(maxn <= 0) return 1;
    for(int i = L + 1; i <= R - 1; i++) {
        maxn -= cal(h, a[i]);
        if(maxn <= 0) return 1;
    }
    return 0;
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    // cout << cal(3, 5, 2, 4, 0) << endl;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        s[i] = a[i] + s[i - 1];
    }
    while(m--) {
        int x, y, v;
        cin >> x >> y >> v;
        int L = lower_bound(s + 1, s + 1 + n, x) - s;
        int R = lower_bound(s + 1, s + 1 + n, y) - s;
        // cout << L << " " << R << endl;
        // cout << check(2, x, y, L, R, 12) << endl;
        int l = 1, r = 1e6 + 1;
        while(l <= r) {
            if(check(Mid, x, y, L, R, v)) r = Mid - 1;
            else l = Mid + 1;
        }
        if(l > 1e6) {
            cout << -1 << endl;
        } else cout << l << endl;
    }
    return 0;
}