#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, dis[N];
set<int> arr[N];
int head[N], nxt[N], ver[N], edge[N], tot = 1, vis[N];
struct node {
    int x, d;
};
bool operator<(const node &a, const node &b) {
    if(a.d == b.d) return a.x < b.x;
    return a.d > b.d;
}
void add(int x, int y, int z) {
    ver[++tot] = y;  nxt[tot] = head[x]; head[x] = tot; edge[tot] = z;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis)); dis[1] = 0;
    q.push({1, 0});
    while(q.size()) {
        int x = q.top().x;
        int d = q.top().d;
        q.pop();
        if(d > dis[x]) continue;
//        if(vis[x] == 1) continue;
//        if(x == 3) cout << x << " " << dis[x] << endl;
//        vis[x] = 1;
        for(int i = head[x]; i; i = nxt[i]) {
            int cost;
            if(arr[x].find(edge[i]) != arr[x].end()) cost = 0;
            else cost = 1;
//            if(x == 1 && ver[i] == 3) cout << "!" << endl;
            if(dis[ver[i]] > dis[x] + cost) {
                arr[ver[i]].clear();
                arr[ver[i]].insert(edge[i]);
                dis[ver[i]] = dis[x] + cost;
                q.push({ver[i], dis[ver[i]]});
            } else if(dis[ver[i]] == dis[x] + cost) {
                arr[ver[i]].insert(edge[i]);
            }
        }
    }
//    cout
//    for(auto x : arr[2]) cout << x << endl;
    if(dis[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << dis[n] << endl;
    return 0;
}