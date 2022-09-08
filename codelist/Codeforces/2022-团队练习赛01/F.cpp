//
// Created by onglu on 2022/5/7.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, goal;
struct germ {
    int s, ty;
    vector<pair<int, int> > req;
} g[N];
struct pri {
    int s;
    vector<pair<int, int> > req;
} p[N];
int check(int *v) {
    int ok = 0, ng = 1000, s = v[0] + v[1] + v[2] + v[3] + v[4];
    while(ng - ok > 1){
        int md = (ok + ng) / 2, sum = 0;
        for(int i = 0; i < 5; i++) sum += min(v[i], md);
        if(sum >= 3 * md) ok = md;
        else ng = md;
    }
    if((s - ok * 3) & 1) return ok + (s - ok * 3) / 2 + 1;
    else return ok + (s - ok * 3) / 2;
}
void work() {
    cin >> n >> m >> goal;
    for(int i = 0; i < n; i++) {
        cin >> g[i].s >> g[i].ty;
        g[i].ty -= 1;
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            g[i].req.push_back({x - 1, y});
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> p[i].s;
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            p[i].req.push_back({x - 1, y});
        }
    }
    int ans = 0x3f3f3f3f, tt = 0;
    for(int i = 0; i < (1 << n); i++) {
        int has[5], scr = 0;
        int gy[5];
        memset(gy, 0, sizeof(gy));
        memset(has, 0, sizeof(has));
        for(int j = 0; j < n; j++) if(i >> j & 1) {
//            if(i == 46) cout << j << " ";
            for(auto k : g[j].req) {
                has[k.first] += k.second;
            }
            gy[g[j].ty] += 1;
            scr += g[j].s;
        }
//        if(i == 46) cout << endl;
        for(int j = 0; j < m; j++) {
            int ok = 1;
            for(auto k : p[j].req) {
                if(gy[k.first] < k.second) {
                    ok = 0; break;
                }
            }
            if(ok) scr += p[j].s;
        }
        if(scr >= goal) {
            if(i == 46) {
                for(int j = 0; j < 5; j++) cout << has[j] << " ";
                cout << endl;
            }
            int q = check(has);
            if(q < ans) {
                ans = q, tt = i;
            }
        }
    }
    cout << tt << endl;
    for(int i = 0; i < n; i++) if((tt >> i & 1)) {
        cout << i << endl;
    }
    cout << endl;
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}