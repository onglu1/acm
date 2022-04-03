//
// Created by onglu on 2022/3/22.
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
const int N = 2e6 + 1009;
const int M = 1e6 + 5;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, c, a[N];
int cost[N], v[N];
void work() {
    cin >> n >> c ;
    for(int i = 1; i <= n; i++) {
        int cc, dd, hh;
        cin >> cc >> dd >> hh;
        cost[cc] = max(cost[cc], dd * hh);
    }
    for(int i = 1; i <= M; i++) {
        for(int j = i; j < M; j += i) {
            v[j] = max(v[j], j / i * cost[i]);
        }
    }
    for(int i = 1; i < M; i++) {
        v[i] = max(v[i], v[i - 1]);
    }
    cin >> m;
    while(m--) {
        int l = 0, r = 1e6;
        int dd, hh;
        cin >> dd >> hh;
        while(l <= r) {
            if(v[Mid] > dd * hh) r = Mid - 1;
            else l = Mid + 1;
        }
        if(l > c) {
            cout << -1 << " ";
        } else {
            cout << l << " ";
        }

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
//  cin >> Case;
    while (Case--) work();
    return 0;
}