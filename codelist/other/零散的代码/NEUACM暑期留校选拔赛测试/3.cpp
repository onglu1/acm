//
// Created by onglu on 2022/5/29.
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
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
int f[N];
vector<int> pri;
void work() {
    f[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!f[i]) pri.push_back(i);
        for(int j = 0; j < pri.size() && pri[j] * i < N; j++) {
            f[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int y = sqrt(x) + 0.5;
        if(y * y == x && !f[y]) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
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
//    cin >> Case;
    while(Case--) work();
    return 0;
}