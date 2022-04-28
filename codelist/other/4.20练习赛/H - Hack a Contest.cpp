//
// Created by onglu on 2022/4/20.
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
//const int N = 309;
int n, m, a[N];
int b[N];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++) cin >> b[j];
    sort(b + 1, b + 1 + m);
    reverse(b + 1, b + 1 + m);
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    int now = 0, ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += a[++now];
        for(int j = 2; j <= b[i]; j++) {
            ans += 20;
            now++;
        }
    }
    static int cnt = 0;
    cnt++;
    cout << "Case " << cnt << ": " << ans << endl;
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
    while (Case--) work();
    return 0;
}