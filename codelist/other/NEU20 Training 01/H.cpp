#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define ll long long

using namespace std;
int n, m;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll exgcd(ll &x, ll &y, ll a, ll b) {
    if(b == 0) return x = 1, y = 0, a;
    ll t = exgcd(y, x, b, a % b);
    y -= a / b * x;
    return t;
}
inline ll mul(ll x, ll y, ll mod){
    return (x * y - (ll)((long double)x / mod * y) * mod + mod) % mod;
}

ll excrt(ll n, ll *a, ll *b) {
    ll ans = a[1], M = b[1];
    for(ll i = 2; i <= n; i++) {
        ll c = ((a[i] - ans) % b[i] + b[i]) % b[i], x, y;
        ll t = exgcd(x, y, M, b[i]), pb = b[i] / t;
        if(c % t != 0) return -1;
        x = mul(x, c / t, pb);
        ans = ans + x * M;
        M = M *pb;
        ans = (ans % M + M) % M;
    }
    return ans;
}
void work() {
    int a[10];
    int b[10];
    cin >> b[1] >> b[2] >> b[3];
    cin >> a[1] >> a[2] >> a[3];
    cout << (int)(pow(excrt(3, a, b), 1.0 / 3) + 0.5) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
