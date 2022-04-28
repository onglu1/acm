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
int n, m, cnt[N], a[N];

void work() {
    cin >> n >> m;
    memset(cnt, 0, sizeof(int) * (n + 2));
    int ans = n, sum = -n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int r = 0;
    int ansL = 1, ansR = n;
    for(int i = 1; i <= n; i++) {
        while(r < n && sum < m) {
            sum += 2 * cnt[++r];
        }
        if(sum < m) break;
        if(r - i + 1 < ans) {
            ansL = i;
            ansR = r;
            ans = r - i + 1;
        }
        sum -= 2 * cnt[i];
    }
    cout << ansL << " " << ansR << endl;
    int res = m, pre = 0;
    sum = 0;
    for(int i = 1; i <= n && res > 1; i++) {
        if(ansL <= a[i] && a[i] <= ansR) {
            sum += 1;
        } else {
            sum -= 1;
        }
        if(sum > 0) {
            cout << pre + 1 << " " << i << endl;
            sum = 0;
            pre = i;
            res--;
        }
    }
    cout << pre + 1 << " " << n << endl;
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