//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, pos[N], dis[N], h[N];
struct node {
    int x, v;
} ;
vector<int> ver[N];
bool operator<(const node &a, const node &b) {
    return a.v > b.v;
}
priority_queue<node> q;
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
//    sort(a + 1, a + 1 + n, [](const node &a, const node &b) {
//        return a.v > b.v;
//    }) ;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
//    for(int i = 1; i <= n; i++) {
//        pos[a[i].x] = i;
//    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({1, 0});
    while(q.size()) {
        int x = q.top().x, v = q.top().v;
        q.pop();
        if(v > dis[x]) continue;
        for(auto y : ver[x]) {
            int del = h[x] - h[y];
            if (del > 0) del = 0;
            del = -del;
            if (dis[y] > dis[x] + del) {
                dis[y] = dis[x] + del;
                q.push({y, dis[y]});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, h[1] - h[i] - dis[i]);
    }
    cout << ans << endl;
    return ;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}