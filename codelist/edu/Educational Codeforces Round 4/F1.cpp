//
// Created by onglu on 2022/4/27.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], s;
int f[2009][2009][2];
/*
 * f[i][0]表示停留在i，最后是往负走
 */
vector<int> b;
vector<int> pos[N];
int dis(int x, int y) {
    return min(abs(x - y), n - abs(x - y));
}
int pre(int x) {
    int cur = a[x];
    auto t = std::lower_bound(pos[cur].begin(), pos[cur].end(), x) - pos[cur].begin();
    return pos[cur][(t - 1 + pos[cur].size()) % pos[cur].size()];
}
int nxt(int x) {
    int cur = a[x];
    auto t = std::upper_bound(pos[cur].begin(), pos[cur].end(), x) - pos[cur].begin();
    return pos[cur][t % pos[cur].size()];
}
int solve(int l, int r, int dir) {
    int &ret = f[l][r][dir];
    if(ret != -1) return ret;
    int cur = a[l], now = dir ? r : l;
    int ll = pre(l);
    int rr = nxt(r);
    ret = 0x3f3f3f3f;
    if(ll == r) {
//    if(l == (*pos[cur].begin()) && r == (*pos[cur].rbegin())) {
        if(cur + 1 == b.size()) return ret = 0;
        for(auto & x : pos[cur + 1])
            ret = min(ret, solve(x, x, 0) + dis(now, x));
        return ret;
    }
    if(ll != -1) {
        ret = min(ret, solve(ll, r, 0) + dis(now, ll));
    }
    if(rr != -1) {
        ret = min(ret, solve(l, rr, 1) + dis(now, rr));
    }
    return ret;
}
void printdis(int s, int t) {
    if(abs(s - t) < n - abs(s - t)) {
        if(s > t) cout << "-" << s - t << endl;
        else cout << "+" << t - s << endl;
    } else {
        if(s > t) cout << "+" << n - abs(s - t) << endl;
        else cout << "-" << n - abs(s - t) << endl;
    }
}
void trace(int l, int r, int dir) {
    int cur = a[l], now = dir ? r : l;
    int &ret = f[l][r][dir];
    int ll = pre(l);
    int rr = nxt(r);
    if(ll == r) {
        if(cur + 1 == b.size()) return ;
        for(auto & x : pos[cur + 1]) if(solve(x, x, 0) + dis(now, x) == ret) {
            printdis(now, x);
            trace(x, x, 0);
            return ;
        }
    }
    if(ll != -1) {
        if(solve(ll, r, 0) + dis(now, ll) == ret) {
            printdis(now, ll);
            trace(ll, r, 0);
            return ;
        }
    }
    if(rr != -1) {
        printdis(now, rr);
        trace(l, rr, 1);
    }
}
void work() {
    cin >> n >> s;
    s -= 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    std::sort(b.begin(), b.end());
    b.resize(std::unique(b.begin(), b.end()) - b.begin());
    for(int i = 0; i < n; i++) {
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        pos[a[i]].push_back(i);
    }
    int ans = 0x3f3f3f3f;
    memset(f, -1, sizeof(f));
    for(auto & x : pos[0]) {
        ans = min(ans, solve(x, x, 0) + dis(s, x));
    }
    cout << ans << endl;
    for(auto & x : pos[0]) if(solve(x, x, 0) + dis(s, x) == ans) {
        printdis(s, x);
        trace(x, x, 0);
        break;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}