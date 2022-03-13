//
// Created by onglu on 2022/3/10.
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
int n, m, a[N], b[N];
map<int, int> Ma, Mb;
int fid(int x, map<int, int> &M) {
    auto it = M.lower_bound(x);
    int minn = 1ll << 61;
    if(it != M.end()) minn = min(minn, abs(it->first - x));
    if(it != M.begin()) {
        it--;
        minn = min(minn, abs(it->first - x));
    }
    return minn;
}
void work() {
    cin >> n;
    Ma.clear();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Ma[a[i]] = 1;
    }
    Mb.clear();
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        Mb[b[i]] = 1;
    }
    int ans = 1ll << 61;
    ans = min({abs(a[1] - b[1]) + abs(a[n] - b[n]),
               abs(a[1] - b[1]) + fid(a[n], Mb) + fid(b[n], Ma),
               abs(a[1] - b[n]) + abs(a[n] - b[1]),
               abs(a[1] - b[n]) + fid(a[n], Mb) + fid(b[1], Ma),
               fid(a[1], Mb) + abs(a[n] - b[1]) + fid(b[n], Ma),
               fid(a[1], Mb) + abs(a[n] - b[n]) + fid(b[1], Ma),
               fid(a[1], Mb) + fid(a[n], Mb) + fid(b[1], Ma) + fid(b[n], Ma)
               });
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
