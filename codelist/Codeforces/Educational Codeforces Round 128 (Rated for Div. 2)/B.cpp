//
// Created by onglu on 2022/5/13.
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
char c[10][10];
void work() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> c[i];
//    for(int i = 0; i < n; i++) cout << c[i] << endl;
    int minnx = n + 1, minny = m + 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == 'R') {
                minnx = min(minnx, i);
                minny = min(minny, j);
            }
        }
    }
//    cout << minnx << " " << minny << endl;
    if(c[minnx][minny] != 'R') {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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