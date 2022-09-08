//
// Created by onglu on 2022/5/27.
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
int n, m, a[11];
vector<int> ans;
void work() {
    int n = 0;
    for(int i = 0; i < 10; i++) cin >> a[i], n += a[i];
    int maxn = 0, sum = 0;
    for(int i = 0; i < 10; i++) {
        maxn = max(maxn, a[i]);
    }
    if(n == 1 && a[0] == 1) {
        cout << 0 << endl;
        return ;
    }
    ans = vector<int>(n);
    if(maxn > n - maxn + 1) {
        cout << -1 << endl;
        return ;
    }
    int pre = -1;
    for(int i = 0; i < n; i++) {
        int ok = 0;
        int maxn = 0;
        for(int j = i == 0 ? 1 : 0; j < 10; j++) if(j != pre && a[j] > 0) {
            maxn = 0;
            for(int k = 0; k < 10; k++) if(k != j) {
                maxn = max(maxn, a[k]);
            }
            // if(i == 2 && j == 9) {
            //     for(int j = 0; j < 10; j++) cout << a[j] << " ";
            //     cout << endl;
            //     cout << maxn << " " << (n - i - 1) - maxn + 1 << " " << j << endl;
            // }
            if(maxn <= (n - i - 1) - maxn + 1 && (n - i - 2) - (a[j] - 1) >= (a[j] - 1) - 1) {
                ans[i] = j;
                ok = 1;
                a[j] -= 1;
                pre = j;
                break;
            }
        }
        if(!ok) {
            // cout << "false : " << i << endl;
            // cout << ans[0] << " " << ans[1] << " " << maxn << endl;
            cout << -1 << endl;
            return;
        }
    }
    for(auto x : ans) {
        cout << x;
    }
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
   cin >> Case;
    while(Case--) work();
    return 0;
}