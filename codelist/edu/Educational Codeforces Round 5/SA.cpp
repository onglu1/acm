//
// Created by onglu on 2022/4/29.
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
int cnt[N], sa[N], rk[N], id[N], oldrk[N];
char c[N];
void work() {
    cin >> (c +1);
    n = strlen(c + 1);
    m = max(n, 300);
    for(int i = 1; i <= n; i++) cnt[rk[i] = c[i]]++;
    for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
//    for(int i = 1; i <= n; i++) cout << cnt[rk[i]] << endl;

    for(int i = n; i > 0; i--) sa[cnt[rk[i]]--] = i;
//    for(int i = 1; i < n; i++) cout << sa[i] << " ";
//    cout << endl;
    for(int i = 1; i <= n; i++) cout << sa[i] << " " ;
    cout << endl;
    for(int w = 1; w < n; w <<= 1) {
        memset(cnt, 0, sizeof(cnt));
        memcpy(id, sa, sizeof(int) * (n + 1));
        for(int i = 1; i <= n; i++) cnt[rk[id[i] + w]]++;
        for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for(int i = n; i > 0; i--) sa[cnt[rk[id[i] + w]]--] = id[i];
        for(int i = 1; i <= n; i++) cout << sa[i] << " " ;
        cout << endl;
        memset(cnt, 0, sizeof(cnt));
        memcpy(id, sa, sizeof(int) * (n + 1));
        for(int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
        for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for(int i = n; i > 0; i--) sa[cnt[rk[id[i]]]--] = id[i];
        memcpy(oldrk, rk, sizeof(int) * (n + 1));
        rk[sa[1]] = 1;
        for(int p = 1, i = 2; i <= n; i++) {
            if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
                rk[sa[i]] = p;
            } else rk[sa[i]] = ++p;
        }
    }
    for(int i = 1; i <= n; i++) cout << sa[i] << " ";
    cout << endl;
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