//
// Created by onglu on 2022/3/19.
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
const int N = 1e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, a[N], vis[N];
int se[N], m[N], f[N];
vector<int> ver[N];
int check(int x, int y, int tg) {
    queue<pair<int, int> > q;
    q.push({x, 1});
    while(q.size()) {
        int x = q.front().first;
        int d = q.front().second;
        vis[x] = tg;
        q.pop();
        if(d == 5) continue;
        if(f[x] != -1) {
            q.push({f[x], d + 1});
        }
        if(m[x] != -1) {
            q.push({m[x], d + 1});
        }
    }
    queue<int> qq;
    qq.push(y);
    while(qq.size()) {
        int x = qq.front();
        qq.pop();
        if(vis[x] == tg) return true;
        if(f[x] != -1) {
            qq.push(f[x]);
        }
        if(m[x] != -1) {
            qq.push(m[x]);
        }
    }
    return false;
}
void work() {
    memset(f, -1, sizeof(f));
    memset(m, -1, sizeof(m));
    memset(se, -1, sizeof(se));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        char c;
        cin >> x >> c;
        cin >> f[x] >> m[x];
        se[x] = c == 'M';
        if(m[x] != -1) {
            se[m[x]] = 0;
            ver[m[x]].push_back(x);
        }
        if(f[x] != -1) {
            se[f[x]] = 1;
            ver[f[x]].push_back(x);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        static int tt = 0;
        int x, y;
        cin >> x >> y;
        if(se[x] == se[y]) {
            cout << "Never Mind" << endl;
            continue;
        }
        tt += 2;
        if(check(x, y, tt) || check(y, x, tt + 1)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
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
//  cin >> Case;
    while (Case--) work();
    return 0;
}