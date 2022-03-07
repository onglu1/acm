#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 2e5 + 1009;
int n, m, p[N], vis[N];
vector<int> v;
void work() {
    cin >> n;
    memset(p, 0, sizeof(int) * (n + 10));
    memset(vis, 0, sizeof(int) * (n + 10));
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        v.clear();
        int k;
        cout << "? " << i << endl;
        cout.flush();
        cin >> k;
        v.push_back(k);
        while(1) {
            cout << "? " << i << endl;
            cout.flush();
            cin >> k;
            v.push_back(k);
            if(k == v[0]) break;
        }
        for(int j = 0; j + 1 < v.size(); j++) {
            p[v[j]] = v[j + 1];
            vis[v[j]] = 1;
        }
    }
    cout << "!";
    for(int i = 1; i <= n; i++) cout << " " << p[i];
    cout << "\n";
    cout.flush();
}

signed main() {
#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
