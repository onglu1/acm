//
// Created by onglu on 2022/4/18.
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
//const int N = 309;
int n, m, a[N];
int f[N];
vector<int> pri;
void work() {
    f[1] = 1;
    cin >> n >> m;
    for(int i = 2; i < N; i++) {
        if(!f[i]) {
            pri.push_back(i);
        }
        for(int j = 0; j < pri.size() && pri[j] * i < N; j++) {
            f[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    int cnt = 0;
    for(int i = 0; pri[i] <= m; i++) {
        if(pri[i] < n) continue;
        for(int j = i + 1; pri[j] <= m; j++) {
            for(int k = j + 1; pri[k] <= m; k++) {
                int p = pri[i], q = pri[j], r = pri[k];
                if(!f[p * q + r] && !f[q * r + p] && !f[r * p + q]) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
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
    while (Case--) work();
    return 0;
}