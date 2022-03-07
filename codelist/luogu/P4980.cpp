#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
int n;
int getphi(int x) {
    int phi = 1;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) {
            while(x % i == 0) {
                if(x / i % i == 0) phi = phi * i;
                else phi = phi * (i - 1);
                x /= i;
            }
        }
    if(x > 1) phi *= x - 1;
    return phi;
}
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
void work() {
    int ans = 0;
    cin >> n;
    for(int i = 1; i * i <= n; i++) if(n % i == 0) {
        int d = i;
        ans = (ans + Pow(n, d) * getphi(n / d) % mod) % mod;
        if(i * i != n) {
            d = n / i;
            ans = (ans + Pow(n, d) * getphi(n / d) % mod) % mod;
        }
    }
    cout << ans * Pow(n, mod - 2) % mod << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}