#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 5e5 + 1009;
int n, k, a[N];
int tree[N];
void add(int x, int y) {
    for( ; x <= n; x += x & -x)
        tree[x] += y;
}
int query(int x) {
    int ans = 0;
    for( ; x; x -= x & -x)
        ans += tree[x];
    return ans;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <  k; i++) add(n - a[i] + 1, 1);
    for(int i = k; i <= n; i++) {
        add(n - a[i] + 1, 1);
        int l = 1, r = n;
        while(l <= r) {
            if(query(Mid) >= k) r = Mid - 1;
            else l = Mid + 1;
        }
        cout << n - r << endl;
     }
    return 0;
}