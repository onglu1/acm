#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[20];
int ans, n;
void work(int d) {
    if(d == n + 1) {
        ans ++;
        return ;
    }
    for(int i = 1; i <= n; i++) if(i != d && !vis[i]) {
        vis[i] = 1;
        work(d + 1);
        vis[i] = 0;
    }
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int f[100];
    f[1] = 0;
    for(int i = 2; i <= 14; i++) {
        f[i] = i * f[i - 1] + ((i & 1) ? -1 : 1);
        cout << "f(" << i << ") = " << f[i] << endl;
    }
    cout << f[14] << endl;
    // for(int i = 1; i <= 12; i++) {
    //     memset(vis, 0, sizeof(vis));
    //     ans = 0;
    //     n = i;
    //     work(1);
    //     cout << "f(" << i << ") = " << ans << endl;
    //     // cout << ans << endl;
    // }
    return 0;
}