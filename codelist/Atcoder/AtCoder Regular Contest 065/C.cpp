#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N], d, ans, vis[N];
pair<int, int> p[N], tp[N];
map<int, set<int> > vx, vy;
map<int, vector<int> > vvx, vvy;
map<pair<int, int>, int> id;
queue<int> q;
queue<int> del;
int dis(int a, int b) {
    return max(abs(p[a].first - p[b].first), abs(p[a].second - p[b].second));
}
void get(int a) {
    int x = p[a].first;
    int y = p[a].second;
    if(id[{x, y}] == -1) return ;

    for(int f = -1; f <= 1; f += 2) {
        if(vx.count(x + d * f)) {
            ans += upper_bound(vvx[x + d * f].begin(), vvx[x + d * f].end(), y + d) -
                   lower_bound(vvx[x + d * f].begin(), vvx[x + d * f].end(), y - d);
            set<int> :: iterator it = vx[x + d * f].lower_bound(y - d);
            for( ; it != vx[x + d * f].end(); it++) {
                if((*it) > y + d) break;
                int t = id[{x + d * f, *it}];
                if(!vis[t]) {
                    q.push(t);
                    del.push(*it);
                    vis[t] = 1;
                }
            }
            while(del.size()) {
                vx[x + d * f].erase(del.front());
                del.pop();
            }
        }
    }
    for(int f = -1; f <= 1; f += 2) {
        if(vy.count(y + d * f)) {
            ans += upper_bound(vvy[y + d * f].begin(), vvy[y + d * f].end(), x + d - 1) -
                   lower_bound(vvy[y + d * f].begin(), vvy[y + d * f].end(), x - d + 1);
            set<int> :: iterator it = vy[y + d * f].lower_bound(x - d);
            for (; it != vy[y + d * f].end(); it++) {
                if ((*it) > x + d) break;
                int t = id[{*it, y + d * f}];
                if(!vis[t]) {
                    q.push(t);
                    del.push(*it);
                    vis[t] = 1;
                }
            }
            while(del.size()) {
                vy[y + d * f].erase(del.front());
                del.pop();
            }
        }
    }
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> n >> a >> b;
    q.push(a);
    q.push(b);
    vis[a] = 1;
    vis[b] = 1;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        vx[x + y].insert(x - y);
        vy[x - y].insert(x + y);
        p[i] = {x + y, x - y};
        tp[i] = {x + y, x - y};
        id[{x + y, x - y}] = i;
    }
    sort(tp + 1, tp + 1 + n, [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    });
    for(int i = 1; i <= n; i++) {
        vvy[tp[i].second].push_back(tp[i].first);
    }
    sort(tp + 1, tp + 1 + n, [](const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    });
    for(int i = 1; i <= n; i++) {
        vvx[tp[i].first].push_back(tp[i].second);
    }
    d = dis(a, b);
    while(q.size()) {
        int a = q.front();
        q.pop();
        get(a);
    }
    cout << ans / 2 << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}