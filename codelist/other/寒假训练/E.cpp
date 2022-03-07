#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 4e5 + 1009;
int n, osize, nsize, vis[N];
int nxt[N], tmp[N];
vector<int> sto;
vector<int> ori[N], nw[N], t;
vector<pair<int, int> > input;
void match(vector<int> &a, vector<int> &b) {
    unsigned long long t = 0;
    sto.clear();
    for(int i = 1; i < b.size(); i++) {
        t = t * 19260817 + (b[i] - b[i - 1]);
    }

}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        int a, b;
        a = x * 10000 + 0.5;
        b = y * 10000 + 0.5;
        input.push_back({a, b});
        t.push_back(a);
    }
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    osize = t.size();
    for(auto x : input) {
        ori[lower_bound(t.begin(), t.end(), x.first) - t.begin()].push_back(x.second);
    }
    for(int i = 0; i < osize; i++) sort(ori[i].begin(), ori[i].end());
    for(int i = 0; i < osize; i++) {
        int t = ori[i].size();
        for(int j = 0; j < t; j++) {
            ori[i].push_back(ori[i][j]);
        }
    }
    input.clear();
    t.clear();
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        int a, b;
        a = x * 10000 + 0.5;
        b = y * 10000 + 0.5;
        input.push_back({a, b});
        t.push_back(a);
    }
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    nsize = t.size();
    for(auto x : input) {
        nw[lower_bound(t.begin(), t.end(), x.first) - t.begin()].push_back(x.second);
    }
    for(int i = 0; i < nsize; i++) sort(nw[i].begin(), nw[i].end());
    if(osize != nsize) {
        cout << "Different" << endl;
        return 0;
    }
    int f = 1;
    for(int i = 0; i < osize; i++) {
        if(ori[i].size() != nw[i].size() * 2) {
            f = 0;
            break;
        }
    }
    if(f == 0) {
        cout << "Different" << endl;
        return 0;
    }

    for(int i = 0; i < osize; i++) {
        match(ori[i], nw[i]);
    }
    for(int i = 0; i < 3600000; i++) {
        if(vis[i] == osize) {
            cout << "Same" << endl;
            return 0;
        }
    }
    cout << "Different" << endl;
    return 0;
}