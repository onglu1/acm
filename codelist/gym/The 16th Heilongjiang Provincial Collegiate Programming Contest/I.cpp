//
// Created by onglu on 2022/5/12.
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
int n, a[N];
map<int, int> M;
void work() {
    cin >> n;
    int sg = 0;
    for(int i = 1; i <= n; i++) {
        int m, e;
        cin >> m >> e;
        M.clear();
        int now = 0;
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            M[e - x - (m - j)] += 1;
        }
        for(auto it : M) {
            if(it.first & 1) {
                sg ^= it.second;
                now ^= it.second;
            }
        }
    }
    if(sg == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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
/*
 * 每个车道是独立的，硬算sg就行
 * 全部在终点是0，最后一个位置离开1，就是1
 *
 *
 *
 */