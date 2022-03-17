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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], t[N];
vector<pair<int, int> > v;
void work() {
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        cin >> t[i];
    }
    for(int j = 1; j <= m; j++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.emplace_back(x, y);
    }
    int ans = 0;
    for(int s = 0; s < 1 << m; s++) {
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            a[i] = t[i];
        }
        for(int i = 0; i < m; i++) {
            if(s >> i & 1) {
                int minn = 1ll << 61;
                for(int j = v[i].first; j < v[i].second; j++) {
                    minn = min(minn, a[j]);
                }
                for(int j = v[i].first; j < v[i].second; j++) {
                    a[j] -= minn;
                }
                sum += minn;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    work();
    return 0;
}