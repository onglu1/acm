#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
struct node {
    int l, r, x;
} ;
vector<pair<int, pair<int, int>> > a;
vector<int> pre, val;
int fid(int x) {
    return (pre[x] == x) ? x : (pre[x] = fid(pre[x]));
}
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    val = vector<int> (n + 1);
    pre = vector<int> (n + 1);
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        l = max(l, 1ll);
        r = min(r, n);
        if(l <= r)
            a.push_back({t, {l, r}});
    }
    sort(a.begin(), a.end());
    for(auto p : a) {
        int now = fid(p.second.second);
        while(now >= p.second.first) {
            val[now] = p.first;
            pre[now] = fid(now - 1);
            now = fid(now);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += val[i];
    cout << ans << endl;
    return 0;
}
/*
 5
 3
 1 2 30
 1 5 20
 3 5 10
 */