//
// Created by onglu on 2022/3/5.
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
//const int N = 309
int n, m, a[N];
vector<int> v[N];
int save[N];

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int now = 1;
    for(int i = 1; i <= m; i++) {
        int opt, x, y;
        cin >> opt >> x;
        if(opt == 0) {
            now = v[now][x - 1];
        } else if(opt == 1) {
            save[x] = now;
            cout << now << endl;
        } else if(opt == 2) {
            now = save[x];
        }
    }
    cout << now << endl;
    return 0;
}