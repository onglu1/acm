//
// Created by onglu on 2022/3/16.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 509;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, k, a[N];
vector<pair<int, int> > v;
void work() {
    cin >> n >> m >> k;
    v.clear();
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    int q;
    cin >> q;
    while(q--) {
        vector<int> t;
        t.clear();
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            t.push_back(a[i]);
        }
        sort(all(t));
        t.resize(unique(all(t)) - t.begin());
        if(t.size() != k) {
            cout << "No\n";
            goto qwq;
        }
        for(auto x : v) {
            if(a[x.first] == a[x.second]) {
                cout << "No\n";
                goto qwq;
            }
        }
        cout << "Yes\n";
        qwq:;
    }
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