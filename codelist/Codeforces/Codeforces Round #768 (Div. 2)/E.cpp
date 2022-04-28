//
// Created by onglu on 2022/4/15.
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
int n, m, a[N];
int mr[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mr[a[i]] = i;
    }
//    cout << mr[7] << endl;
//    return ;
    int ans = 0;
    int l = 1;
    while(l <= n) {
//        cerr << "      " << l << endl;
        int r = mr[a[l]];
        int pl = l, cnt = 1;
        while(1) {
//            cerr << r << endl;
            int nr = r;
            for(int i = pl + 1; i < r; i++) {
                nr = max(nr, mr[a[i]]);
            }
            if(nr <= r) break;
            cnt += 1;
            pl = r;
            r = nr;
        }
        if(r != l)
            ans += r - l + 1 - cnt - 1;
//        cerr << "    " << l << " " << r << endl;
        l = r + 1;
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
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}