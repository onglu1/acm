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
const int N = 2009;
const double EPS = 1e-15;
//const int N = 309
int n, m, a[N];
int vis[N];
double g[N][N];
vector<int> v;
void print(int a, int b) {
    if(vis[a]) cout << "-";
    cout << a - 1 << " ";
    if(vis[b]) cout << "-";
    cout << b - 1 << endl;
}
int read() {
    string s = "";
    int x = 0;
    cin >> s;
    if(s[0] == '-') {
        for(int t = 1; t < s.size(); t++) x = x * 10 + s[t] - '0';
    } else {
        for(char t : s) x = x * 10 + t - '0';
    }
    x += 1;
    if(s[0] == '-') vis[x] = 1;
    return x;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        v.clear();
        for(int j = 1; j <= k; j++) {
            int x = read();
            v.push_back(x);
        }
        for(auto x : v) {
            for(auto y : v) {
                g[x][y] += 1.0 / k;
            }
        }
    }
    int a = read(), b = read();
    double maxa = 0, maxb = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] ^ vis[a]) maxa = max(maxa, g[a][i]);
        if(vis[i] ^ vis[b]) maxb = max(maxb, g[b][i]);
    }
    if(fabs(maxa - g[a][b]) < EPS && fabs(maxb - g[a][b]) < EPS) {
        print(a, b);
    } else {
        for(int i = 1; i <= n; i++) {
            if((vis[i] ^ vis[a]) && fabs(maxa - g[a][i]) < EPS) {
                print(a, i);
            }
        }
        for(int i = 1; i <= n; i++) {
            if((vis[i] ^ vis[b]) && fabs(maxb - g[b][i]) < EPS) {
                print(b, i);
            }
        }
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