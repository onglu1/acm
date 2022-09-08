//
// Created by onglu on 2022/6/11.
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
int b[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if(n == 1) {
        cout << -1 << endl;
        return ;
    }
    sort(b + 1, b + 1 + n);
    for(int i = 1; i < n; i++) {
        if(b[i] == a[i]) {
            swap(b[i + 1], b[i]);
        }
    }
    if(b[n] == a[n]) swap(b[n], b[n - 1]);
    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
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
    cin >> Case;
    while(Case--) work();
    return 0;
}