//
// Created by onglu on 2022/3/9.
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
int n, m, k, a[N];
vector<int> v;
int work() {
    int now = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    v.clear();
    for(int i = 1; i <= n; i++) {
        while(v.empty() || v[v.size() - 1] != i) {
            if(v.size() == m + 1) return false;
            if(now == n + 1) return false;
            v.push_back(a[now++]);
        }
        v.pop_back();
    }
    return true;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
        cout << (work() ? "YES" : "NO") << endl;
    return 0;
}