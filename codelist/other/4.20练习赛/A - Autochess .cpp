//
// Created by onglu on 2022/4/20.
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
int n, m, k, a[N];
map<string, int > sti;
map<int, string> its;
priority_queue<int, vector<int>, greater<int> > q;
struct node {
    vector<int> pos[3];
    node() {
        pos[0].clear();
        pos[1].clear();
        pos[2].clear();
    }
};
int level[N], id[N];
vector<node> v;
void clr(vector<int> &v) {
    for(auto x : v) q.push(x);
    v.clear();
}
void work() {
    static int cnt = 0;
    cnt++;
    cout << "Case " << cnt << ": ";
    sti.clear(); its.clear();
    cin >> n >> m >> k;
    v.clear();
    while(q.size()) q.pop();
    for(int i = 1; i <= m; i++) q.push(i);
    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        int id, lev = 0;
        if(!sti.count(name)) {
            sti[name] = v.size();
            its[v.size()] = name;
            v.push_back(node());
        }
        id = sti[name];
        if(!v[id].pos[2].empty()) continue;
        if(v[id].pos[0].size() == k - 1) {
            clr(v[id].pos[0]);
            lev += 1;
            if(v[id].pos[1].size() == k - 1) {
                clr(v[id].pos[1]);
                lev += 1;
            }
        }
        if(q.empty()) continue;
        v[id].pos[lev].push_back(q.top());
        q.pop();
    }
    for(int i = 1; i <= m; i++) id[i] = -1;
    for(int d = 0; d < v.size(); d++) {
        for(int i = 0; i < 3; i++) {
           for(auto x : v[d].pos[i]) {
                id[x] = d;
                level[x] = i;
           }
        }
    }
    for(int i = 1; i <= m; i++) {
        if(id[i] == -1) cout << -1;
        else {
            cout << its[id[i]];
            if(level[i] != 0) cout << level[i] + 1;
        }
        cout << " \n"[i == m];
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
    cin >> Case;
    while (Case--) work();
    return 0;
}