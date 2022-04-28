//
// Created by onglu on 2022/4/18.
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
int n, m, a[N], b[N];
int f[1000 * 30 + 1009];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = sum; j >= 0; j--) {
            f[j + b[i]] = min(f[j + b[i]], f[j] + a[i]);
        }
        sum += b[i];
    }
    for(int i = sum; i >= 0; i--) {
        if(f[i] <= m) {
            cout << i << endl;
            return ;
        }
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