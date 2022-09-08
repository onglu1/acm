//
// Created by onglu on 2022/5/29.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
vector<pair<int, int> > v;
int work() {
    cin >> m >> n;
    v = vector<pair<int, int> >(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    std::sort(v.begin(), v.end());
    for(auto t : v) {
        if(m <= t.first) return false;
        m += t.second;
    }
    return true;
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
    while(Case--) cout << (work() ? "YES" : "NO") << endl;
    return 0;
}