//
// Created by onglu on 2022/3/19.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
int n, m, tot, s, t;
int val[N];
map<int, string> rM;
map<string, int> M;
vector<pair<int, int> > ver[N];
void build_map() {
    cin >> n >> m;
    string _, __;
    cin >> _ >> __;
    M[_] = ++tot;
    rM[tot] = _;
    s = tot;
    M[__] = ++tot;
    rM[tot] = __;
    t = tot;
    for(int i = 1; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if(!M.count(s)) {
            M[s] = ++tot;
            rM[tot] = s;
        }
        val[M[s]] = x;
    }
    for(int i = 1; i <= m; i++) {
        string _, __;
        int x, y, z;
        cin >> _ >> __ >> z;
        x = M[_]; y = M[__];
        ver[x].push_back({y, z});
        ver[y].push_back({x, z});
    }
}

struct node {
    int x, d, cnt, kil, pre, ways;
};
bool operator<(const node &a, const node &b) {
    if(a.d != b.d) return a.d > b.d;
    if(a.cnt != b.cnt) return a.cnt < b.cnt;
    return a.kil < b.kil;
}
bool operator<<(const node &a, const node &b) {
    if(a.d != b.d) return a.d < b.d;
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.kil > b.kil;
}
node operator+(const node &a, const pair<int, int> &p) {
    node b{};
    b.x = p.first;
    b.d = a.d + p.second;
    b.cnt = a.cnt + 1;
    b.kil = a.kil + val[b.x];
    b.pre = a.x;
    b.ways = a.ways;
    return b;
}
node best[N];
void dijkstra(int s) {
    for(int i = 1; i <= tot; i++) {
        best[i] = {i, 0x3f3f3f3f3f3f3f3f, -0x3f3f3f3f3f3f3f3f, -0x3f3f3f3f3f3f3f3f, -1, 0};
    }
    best[s] = {s, 0, 0, 0, -1, 1};
    priority_queue<node> q;
    q.push(best[s]);
    while(q.size()) {
        node x = q.top();
        q.pop();
        if(x < best[x.x] || x.ways != best[x.x].ways) continue;
        for(auto y : ver[x.x]) {
            node to = x + y;
            if(to << best[to.x]) {
                if(to.d == best[to.x].d) to.ways += best[to.x].ways;
                best[to.x] = to;
                q.push(to);
            } else if(to.d == best[to.x].d) {
                best[to.x].ways += to.ways;
                q.push(best[to.x]);
            }
        }
    }
}
void print(int x) {
    if(best[x].pre == -1) {
        cout << rM[x];
    } else {
        print(best[x].pre);
        cout << "->" << rM[x];
    }
}
void work() {
    build_map();
    dijkstra(s);
    print(t);
    cout << endl;
    cout << best[t].ways << " " << best[t].d << " " << best[t].kil << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}