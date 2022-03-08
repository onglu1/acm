//
// Created by onglu on 2022/3/8.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 100009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
//vector<vector<int> > v(N);
map<int, map<int, int> > M, P;
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            M[c][j] += 1;
            P[c][i] += 1;
        }
    }
    int ans = 0;
    for(int i = 1; i < N; i++) {
        int cnt = 0, dis = 0, pre = 0;
        for(auto x : M[i]) {
            dis += cnt * (x.first - pre);
            pre = x.first;
            ans += dis * (x.second);
            cnt += x.second;
        }
    }
    for(int i = 1; i < N; i++) {
        int cnt = 0, dis = 0, pre = 0;
        for(auto x : P[i]) {
            dis += cnt * (x.first - pre);
            pre = x.first;
            ans += dis * (x.second);
            cnt += x.second;
        }
    }
    cout << ans << endl;
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