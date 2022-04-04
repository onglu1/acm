//
// Created by onglu on 2022/4/3.
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

void work() {
    cin >> n;
    for(int i = 0; i < 1 << n; i++) {
        cin >> a[i];
    }
    for(int x = 0; x < 1 << n; x++) {
        for(int y = 1; y < 1 << n; y <<= 1) if(!(x & y)) {
            for(int z = 1; z < 1 << n; z <<= 1) if(!(x & z) && y != z) {
                if(a[x + y] + a[x + z] < a[x] + a[x + y + z]) {
                    cout << x + y << " " << x + z << endl;
                    return ;
                }
            }
        }
    }
    cout << -1 << endl;
    return ;
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