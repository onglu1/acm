#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1009;
const int M = 1e6 + 1009;
int n, a[N], f[M];
vector<int> pri;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f[1] = 1;
    for(int i = 2; i < M; i++) if(!f[i]) {
            pri.push_back(i);
            for(int j = i * 2; j < M; j += i) {
                f[j] = 1;
            }
        }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1, cnt;
    for(auto x : pri) {
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] % x == 0)
                cnt++;
            while(a[i] % x == 0) {
                a[i] /= x;
            }
        }
        ans = max(ans, cnt);
    }
    int p = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > 1) {
            a[++p] = a[i];
        }
    }
    n = p;

    for(int i = 1; i <= n; i++) {
        int p = -1, q = -1;
        for(int j = 1; j <= n; j++) if(a[i] != a[j]) {
                int t = gcd(a[i], a[j]);
                if(t != a[i] && t != 1) {
                    p = t;
                    q = a[i] / t;
                    break;
                }
            }
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j] % a[i] == 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        if(p == -1 || q == -1) continue;
        cnt = 0;
        for(int j = 1; j <= n; j++)  {
            if(a[j] % p == 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j] % q == 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);

    }
    cout << ans << endl;
    return 0;
}