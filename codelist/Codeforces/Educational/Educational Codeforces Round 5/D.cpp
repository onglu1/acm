//
// Created by onglu on 2022/4/28.
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
int n, k, a[N];
int cnt[N], now, ansl, ansr;
void push(int x) {
    if(cnt[x] == 0) now++;
    cnt[x] += 1;
}
void pop(int x) {
    cnt[x]--;
    if(cnt[x] == 0) now--;
}
void work() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int r = 1;
    for(int i = 1; i <= n; i++) {
        while(r <= n && now <= k) {
            if(now == k && cnt[a[r]] == 0) break;
            push(a[r]), r++;
        }
        if(r - i > ansr - ansl) {
            ansl = i;
            ansr = r;
        }
        pop(a[i]);
    }
    cout << ansl << " " << ansr - 1 << endl;
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