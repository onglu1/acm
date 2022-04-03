//
// Created by onglu on 2022/4/2.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 129;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], pre[N], vis[N];
int in[N];
struct node {
    int to, w;
};
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
vector<node> ver[N];
vector<node> cir;

void getcir() {
    cir.clear();
    memset(vis, 0, sizeof(vis));
    queue<int> q;
//    for(int i = 1; i <= n; i++) {
//        cout << i << " : ";
//        for(auto y : ver[i]) {
//            cout << "(" << y.to << ", " << y.w << ") -> ";
//        }
//        cout << endl;
//    }
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }
//    for(int i = 1; i <= n; i++) {
//        cout << in[i] << " " ;
//    }
//    cout << endl;
    while(!q.empty()) {
        int x = q.front();
        vis[x] = 1;
        q.pop();
        for(auto y : ver[x]) {
            in[y.to]--;
            if(in[y.to] == 0) {
                q.push(y.to);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            for(auto y : ver[i]) {
                if(vis[y.to] == 0) {
//                    cout << i << " " << y.to << " " << y.w << endl;
                    cir.push_back(y);
                }
            }
        }
    }
//    cout << cir.size() << endl;
//    for(auto y : cir ) {
//        cout << y.to << " " << y.w << endl;
//    }
}
void work() {
    int ans = 0;
    assert(m <= n);
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x += 1;
        y += 1;
        if(w <= 0) ans += w;
        else if(x != y) {
            ver[y].push_back({x, w});
//            ver[y].push_back({x, w});
            in[x]++;
//            in[y]++;
            pre[fid(x)] = fid(y);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += fid(i) == i;
    }
    if(cnt > 1) {
        cout << ans << endl;
        return ;
    }
//    cout << ver[2].size() << endl;
    getcir();
//    cout << cir.size() << endl;
    if(cir.size() == 0) {
        int minedge = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            for(auto y : ver[i]) {
                minedge = min(minedge, y.w);
            }
        }
        cout << ans + minedge << endl;
        return ;
    }
    std::sort(cir.begin(), cir.end(), [](const node &a, const node &b) {
        return a.w < b.w;
    });
//    for(auto y : cir) {
//        vis[y.to] = 1;
//    }
    int p = ans + cir[0].w + cir[1].w;
    for(int i = 1; i <= n; i++) {
        for(auto y : ver[i]) {
            if(vis[i] || vis[y.to]) {
                p = min(p, ans + y.w);
            }
        }
    }
    cout << p << endl;


}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m) {
        if(n + m == 0) break;
        work();
    }
    return 0;
}