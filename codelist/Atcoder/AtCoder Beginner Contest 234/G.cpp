#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 1009;
int n, a[N], f[N], submax[N], submin[N];
struct node {
    int f, v;
};
stack<node> maxst, minst;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    maxst.push({1, a[1]});
    minst.push({1, a[1]});
    for(int i = 2; i <= n; i++) {
        int maxs = 0, mins = 0;
        f[i] = f[i - 1];
        while(!maxst.empty() && maxst.top().v < a[i]) {
            f[i] = (f[i] + maxst.top().f * (a[i] - maxst.top().v) % mod) % mod;
            maxs = (maxs + maxst.top().f) % mod;
            maxst.pop();
        }
        while(!minst.empty() && minst.top().v > a[i]) {
            f[i] = (f[i] + minst.top().f * (minst.top().v - a[i]) % mod) % mod;
            mins = (mins + minst.top().f) % mod;
            minst.pop();
        }
        maxst.push({(maxs + f[i - 1]) % mod, a[i]});
        minst.push({(mins + f[i - 1]) % mod, a[i]});
    }
    cout << f[n] << endl;
    return 0;
}