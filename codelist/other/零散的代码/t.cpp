#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N], cnt[N], fa[N], wf[N];
vector<pair<int, int> > ver[N];
signed main() {
    memset(fa, -1, sizeof(fa));
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x, w;
        cin >> x >> w;
        fa[i] = x; wf[i] = w;
        ver[x].push_back({i, w});
        if(w == 1) cnt[x]++;
    }
    for(int x = 1; x <= n; x++) {
        int ans = 0;
        for(auto y : ver[x]) {
            if(y.second <= 2) ans++;
            if(y.second == 1) {
                ans += cnt[y.first];
            }
        }
        if(fa[x] != -1) {
            if(wf[x] == 2) ans++;
            else if(wf[x] == 1) {
                ans++;
                ans += fa[fa[x]] != -1 && wf[fa[x]] == 1;
                ans += cnt[fa[x]] - 1;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}