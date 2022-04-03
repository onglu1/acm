//
// Created by onglu on 2022/3/24.
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
int n, m, a[N];

void work() {
    int have1 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        have1 |= a[i] == 1;
    }
    sort(a + 1, a + 1 + n);
    if(!have1) {
        cout << "YES" << endl;
        return ;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i - 1] + 1 == a[i]) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;

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