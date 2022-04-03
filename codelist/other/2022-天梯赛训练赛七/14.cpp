//
// Created by onglu on 2022/3/26.
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
int n, m, a[N], f[N];
int pos[N];
struct node {
    int x, y, t;
};
vector<node> v;
int cmp(const node &a, const node &b) {
    if(a.t != b.t) return a.t < b.t;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
void work() {
    cin >> n >> m;
    while(m--) {
        char c;
        int x, y, t;
        cin >> c >> x >> y >> t;
        v.push_back({x, y, t});
        std::sort(v.begin(), v.end(), cmp);
        for(int i = 1; i <= n; i++) f[i] = i, pos[i] = i;
        for(auto p : v) {
            int pa = pos[p.x], pb = pos[p.y];
            pos[p.y] = pa;
            pos[p.x] = pb;
            swap(f[pa], f[pb]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += i * f[i];
        }
        cout << ans << endl;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}