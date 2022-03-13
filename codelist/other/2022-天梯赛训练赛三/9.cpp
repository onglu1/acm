//
// Created by onglu on 2022/3/12.
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
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 10009;
//const int N = 309
int n, m;
int vis[N];
struct node {
    int x, y;
} a[N];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;
    }
    int q;
    cin >> q;

    while(q--) {
        int k;
        cin >> k;
        memset(vis, 0, sizeof(int) * (n + 5));
        for(int i = 1; i <= k; i++) {
            int x;
            cin >> x;
            vis[x] = 1;
        }
        for(int i = 1; i <= m; i++) {
            if(vis[a[i].x] == 0 && vis[a[i].y] == 0) {
                cout << "NO" << endl;
                goto qwq;
            }
        }
        cout << "YES" << endl;
        qwq:;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}