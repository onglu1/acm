//
// Created by onglu on 2022/3/5.
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
//const int N = 309
int n, m;
struct node {
    vector<int> v;
} ;
bool operator<(const node &a, const node &b) {
    for(int i = 0; i < a.v.size(); i++) {
        if(a.v[i] != b.v[i]) {
            return a.v[i] > b.v[i];
        }
    }
    return a.v[0] < b.v[0];
}
map<node, int> cnt;
struct node1 {
    int cnt;
    vector<int> v;
} ;
vector<node1> v;
bool operator<(const node1 &a, const node1 &b) {
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    for(int i = 0; i < a.v.size(); i++) {
        if(a.v[i] != b.v[i]) {
            return a.v[i] < b.v[i];
        }
    }
    return a.v[0] < b.v[0];
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        node t;
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            t.v.push_back(x);
        }
        cnt[t]++;
    }
    cout << cnt.size() << endl;
    for(auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        v.push_back({it->second, it->first.v});
    }
    sort(all(v));
    for(auto x : v) {
        cout << x.cnt << " ";
        for(int i = 0; i < x.v.size(); i++) {
            cout << x.v[i] << " \n"[i + 1 == x.v.size()];
        }
    }
    return 0;
}