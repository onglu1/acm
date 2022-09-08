//
// Created by onglu on 2022/5/14.
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
int k;
vector<pair<int, int> > ans;
void dfs(int n, int t, int res, int base) {
    if(n == 1) return ;
    if(res - ((n - 1) * 4 - t + 1) >= (n - 2) / 2 * 2) {
        dfs(n - 2, 1, res - ((n - 1) * 4 - t + 1), base + (n - 1) * 4);
        return ;
    }

    for(int i = t; i < (n - 1) * 4; i++) {
        if(i == 1 || i == n || i == 2 * n - 1 || i == 3 * n - 2) continue;
        int nxtpos = 0;
        if(i < n) nxtpos = i - 1;
        else if(i < 2 * n - 1) nxtpos = i - n + (n - 2 - 1);
        else if(i < 3 * n - 2) nxtpos = i - (2 * n - 1) + 2 * (n - 2 - 1);
        else nxtpos = i - (3 * n - 2) + 3 * (n - 2 - 1);
        if(res - (i - t + 1) <= (n - 2) * (n - 2) - nxtpos) {
//            cout << i << " " << res << " " << nxtpos << " " << base << " " << res - (i - t + 1) << " " << (n - 2) * (n - 2) - nxtpos << endl;
            ans.push_back({i + base, nxtpos + base + (n - 1) * 4});
            dfs(n - 2, nxtpos, res - (i - t + 1), base + (n - 1) * 4);
            return ;
        }
    }

}
void work() {
    static int cnt = 0;
    cnt += 1;
    cout << "Case #" << cnt << ": ";
    cin >> n >> k;
    if(k % 2 != 0 || n / 2 * 2 > k) {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }
    ans.clear();
    dfs(n, 1, k, 0);
//    int base = 0;
//    while(n != 1) {
//        if(k > (n - 1) * 4) {
//            k -= (n - 1) * 4;
//        } else {
//            int step = k - (n - 1) * (n - 1);
//            if(step <= 0) {
//                ans.push_back({1 + base, (n - 1) * 4 + base});
//                k -= 2;
//            } else {
//                int pos =
//            }
//        }
//        base += (n - 1) * 4;
//        n -= 2;
//    }
    cout << ans.size() << endl;
    for(auto t : ans) {
        cout << t.first << " " << t.second << endl;
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
    cin >> Case;
    while (Case--) work();
    return 0;
}