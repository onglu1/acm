#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 10009;
const int mod = 1e9 + 7;
int n, m;
vector<int> v;
int qpow(int a, int p) {
    int ans = 1;
    a %= mod;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
int inv(int x) {
    return qpow(x, mod - 2);
}
int f[N], pow7[N];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    pow7[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        pow7[i] = pow7[i - 1] * 7;
    }
    f[0] = 0;
    for(int i = 1; i <= 1000; i++) {
        int t = pow7[i] % mod;
        f[i] = (f[i - 1] * 4 * 7 % mod + t * ((t - 1 + mod) % mod) % mod * inv(2) % mod * 21 % mod);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, tx;
        cin >> x;
        tx = x;
        v.clear();
        while(tx) {
            v.push_back(tx % 7);
            tx /= 7;
        }
        int ans = 0, base = 1;
        for(int j = v.size() - 1; j >= 0; j--) if(v[j] > 0) {
            x -= pow7[j] * v[j];
            int s = pow7[j] % mod * ((pow7[j] - 1 + mod) % mod) % mod * inv(2) % mod;
            //计算上方完整的倒三角多少个
            ans = (ans + (v[j] - 1) * v[j] / 2 * s % mod * base % mod) % mod;
            //计算上方完整的子三角形多少个
            if(j >= 1)
                ans = (ans + v[j] * (v[j] + 1) / 2 * f[j - 1] % mod * base % mod) % mod;
            //计算一半的倒三角多少个
            ans = (ans + ((pow7[j] - 1 + pow7[j] - 1 - x) % mod + mod) % mod * ((x + 1) % mod) % mod * inv(2) % mod * base % mod * v[j] % mod) % mod;
            base = base * (v[j] + 1) % mod;
        }
        cout << "Case " << i << ": ";
        cout << ans << endl;
    }
    return 0;
}
