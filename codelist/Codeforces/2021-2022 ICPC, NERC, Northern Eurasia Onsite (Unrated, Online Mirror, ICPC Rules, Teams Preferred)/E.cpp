//
// Created by onglu on 2022/4/14.
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
// 最大值最小
// 是否所有长度都小于x
int checkMax(int x) {
    int now = 0;
    for(int i = 1; i < n; i++) {
        if(now + x < a[i]) return false;
        now = min(now + x, a[i + 1]);
    }
    return now + x >= a[n + 1];
}
//最小值最大
// 是否所有长度都大于x
int checkMin(int x) {
    int now = 0;
    for(int i = 1; i < n; i++) {
        if(now + x > a[i + 1]) return false;
        now = max(now + x, a[i]);
    }
    return now + x <= a[n + 1];

}
int u[N], d[N];
void work() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = m;
//    cout << checkMax(4) << endl;
//    return ;
//    for(int i = 1; i <= 10; i++) {
//        cout << checkMax(i) << " ";
//    }
//    cout << endl;
    int minn = m;
    int maxn = -1;
    int l = 0, r = m;
    while(l <= r) {
        if(checkMax(Mid)) r = Mid - 1;
        else l = Mid + 1;
    }
    maxn = l;
    l = 0; r = m;
    while(l <= r) {
        if(checkMin(Mid)) l = Mid + 1;
        else r = Mid - 1;
    }
    minn = r;
//    cout << minn << " " << maxn << endl;
//    cout << maxn - minn << endl;
    u[0] = d[0] = 0;
    for(int i = 1; i <= n; i++) {
        u[i] = min(u[i - 1] + maxn, a[i + 1]);
        d[i] = max(d[i - 1] + minn, a[i]);
    }
    vector<int> ans;
    ans.push_back(m);
    int now = m, pos = n - 1;
    while(now > 0) {
        int dd = now - maxn;
        now = max(dd, d[pos]);
        pos -= 1;
        ans.push_back(now);
    }
    std::reverse(ans.begin(), ans.end());
    for(int i = 0; i + 1 < ans.size(); i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
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