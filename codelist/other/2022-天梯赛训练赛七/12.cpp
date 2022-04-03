//
// Created by onglu on 2022/3/26.
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
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
const int N = 309;
int n, m, a[N];
int g[N][N];
vector<int> v;
void work() {
    cin >> n >> m;
    memset(g, -1, sizeof(g));
    for(int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        if(g[x][y] == -1) g[x][y] = g[y][x] = w;
        else {
            g[x][y] = min(g[x][y], w);
            g[y][x] = min(g[x][y], w);
        }
    }
    int t, cnt = 0;
    int minn = -1, mc = 0x3f3f3f3f;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        v.clear();
        v.push_back(0);
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        auto t = v;
        std::sort(t.begin(), t.end());
        t.resize(std::unique(t.begin(), t.end()) - t.begin());
//        cout << i << endl;
        if(t.size() != v.size() || v.size() != n + 1) continue;
        int ok = 1, cost = 0;
        for(int i = 0; i < v.size(); i++) {
            int nxt = (i + 1) % v.size();
            if(g[v[i]][v[nxt]] == -1) {
                ok = 0;
                break;
            }
            cost += g[v[i]][v[nxt]];
        }
        if(!ok) continue;
//        cout << i << " " << cost << endl;
        if(cost < mc) {
            minn = i;
            mc = cost;
        }
        cnt++;
    }
    cout << cnt << endl << minn << " " << mc << endl;
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