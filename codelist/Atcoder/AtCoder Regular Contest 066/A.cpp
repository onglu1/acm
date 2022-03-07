#include <bits/stdc++.h>
#define endl '\n'
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n, m, a[N];

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x < 0 || x > n - 1) {
            cout << "0" << endl;
            return 0;
        }
        a[x]++;
    }
    int f = (n & 1) + 1;
    int ans = 1;
    for(int i = f; i <= n; i += 2) {
        if(a[i] != 2) {
            cout << "0" << endl;
            return 0;
        } else {
            ans = ans * 2 % mod;
        }
    }
    if((n & 1) && a[0] != 1) {
        cout << "0" << endl;
        return 0;
    }
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}