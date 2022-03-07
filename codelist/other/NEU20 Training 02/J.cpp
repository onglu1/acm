#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, m, x, pp;
vector<int> v, t, p;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    m++;
    int qwq;
    cin >> qwq;
    t.push_back(0);
    p.push_back(qwq);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 2; i <= m; i++) {
        int qwq;
        cin >> qwq;
        t.push_back(qwq);
    }
    for(int i = 2; i <= m; i++) {
        int qwq;
        cin >> qwq;
        p.push_back(qwq);
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        while(cnt < n && x <= (p[i] - t[i]) * v[cnt]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}