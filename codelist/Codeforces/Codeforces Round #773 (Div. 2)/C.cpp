//
// Created by onglu on 2022/2/27.
//

#include <bits/stdc++.h>
#define int long long
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
vector<int> v;
map<int, int> M;
void work() {
    cin >> n >> m;
    M.clear();
    v.clear();
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        M[x]++;
    }
    sort(v.begin(), v.end());
//    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < n; i++) {
        int t = min(M[v[i]], M[v[i] * m]);
        M[v[i]] -= t;
        M[v[i] * m] -= t;
    }
    int ans = 0;
    for(auto x : M) {
        ans += x . second;
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}