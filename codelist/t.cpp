#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> f(n + 10);
    for(int i = 1; i <= n; i++) f[i] = (1e15);
    for(int i = 1; i <= m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        l = max(l, 1ll);
        r = min(r, n);
        for(int j = l; j <= r; j++) {
            f[j] = min(f[j], t);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += f[i];
    cout << ans << endl;
    return 0;
}
