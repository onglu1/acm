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
int n, m, a[N], p[N] = {0, 3, 6, 1, 5, 2, 4};
vector<int> v[N];
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = 1; i <= m; i++) p[i] = i;
    do {
        int now = 1, ok = 1;
        for(int i = 1; i <= m; i++) {
            for(auto x : v[p[i]]) {
                if(x != a[now]) {
                    ok = 0;
                    break;
                }
                now++;
            }
            now--;
            if(ok == 0) break;

        }
        if(ok == 1) {
            for(int i = 1; i <= m; i++) {
                cout << p[i] << " \n"[i == m];
            }
            break;
        }
    } while(next_permutation(p + 1, p + 1 + m));
    return 0;
}