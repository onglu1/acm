//
// Created by onglu on 2022/4/2.
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
const int N = 10;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];

void work() {
    for(int i = 1; i <= 4; i++) a[i] = 1e6;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 4; j++){
            int x;
            cin >> x;
            a[j] = min(a[j], x);
        }
    }
    static int cnt = 0;
    cnt++;
    cout << "Case #" << cnt << ":";
    int sum = a[1] + a[2] + a[3] + a[4];
    if(sum < 1e6) {
        cout << " IMPOSSIBLE" << endl;
        return ;
    }
    int res = 1e6;
    for(int i = 1; i <= 4; i++) {
        int cost = min(a[i], res);
        a[i] -= cost; res -= cost;
        cout << " " << cost;
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
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}