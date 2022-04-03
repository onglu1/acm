//
// Created by onglu on 2022/3/25.
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
const int N = 309;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, a[N];
int f[N][N], g[N][N];
struct node {
    int a, b, c, d;
};
vector<node> v;
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            g[i][j] = s[j - 1] == '1';
            f[i][j] = 0;
        }
    }
    if(g[1][1] == 1) {
        cout << -1 << endl;
        return ;
    }
    v.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = m; j > 1; j--) {
            if(g[i][j] == 1) {
                v.push_back({i, j - 1, i, j});
            }
        }
    }
    for(int i = n; i > 1; i--) {
        if(g[i][1] == 1) {
            v.push_back({i - 1, 1, i, 1});
        }
    }
    cout << v.size() << endl;
    for(auto x : v) {
        cout << x.a << " " << x.b << " " << x.c << " " << x.d << endl;
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