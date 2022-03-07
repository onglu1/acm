#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, a[N];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int t = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            if(a[i - 1] > a[i]) {
                t = a[i - 1];
                break;
            } else {
                t = a[i];
            }
        }
    }
    for(int i = 1; i<= n; i++) {
        if(a[i] != t) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}