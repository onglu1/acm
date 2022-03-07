#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n, m, a[N];
int cnt[N];
void get(int x) {
    for(int i = 2; i * i <= x; i++)  {
        while(x % i == 0) {
            cnt[i]++;
            x /= i;
        }
    }
    if(x > 1) cnt[x]++;
}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        get(i);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i]) {
            ans = (1ll * ans * (cnt[i] + 1)) % mod;
        }
    }
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}