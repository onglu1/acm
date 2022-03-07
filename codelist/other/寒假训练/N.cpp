#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int p, q;
int issq(int x) {
    int p = sqrt(x) + 0.5;
    return x == p * p;
}
void work() {
    cin >> p >> q;
    if(p * p - 4 * q * q < 0 || !issq(p * p - 4 * q * q)) {
        cout << "0 0\n";
        return ;
    }
    int b = 2 * q;
    int a = p + sqrt(p * p - 4 * q * q) + 0.5;
    int t = __gcd(a, b);
    a /= t; b /= t;
    if(a > b) swap(a, b);
    cout << a << " " << b << endl;
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