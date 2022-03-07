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
int n, m, a[N], in[N];
int nxt[N], f[N];
vector<int> ver[N];


signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int y;
            cin >> y;
//            ver[i].push_back(y + 1);
            ver[y + 1].push_back(i);
            in[i]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            q.push(i);
            f[i] = 1;
        }
    }
    int maxn = 0;
    while(q.size()) {
        int x = q.front(); q.pop();
        maxn = max(maxn, f[x]);
        for(auto y : ver[x]) {
            in[y]--;
            if(f[y] < f[x] + 1) {
                f[y] = f[x] + 1;
                nxt[y] = x;
            } else if(f[y] == f[x] + 1) {
                nxt[y] = min(nxt[y], x);
            }
            if(in[y] == 0) {
                q.push(y);
            }
        }
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        if(f[i] == maxn) {
            int now = i;
            while(now != 0) {
                v.push_back(now);
                now = nxt[now];
            }
        }
    }
    cout << maxn << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] - 1 << " \n"[i + 1 == v.size()];
    }
    return 0;
}