#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int n, m;

void work() {
    cin >> n >> m;
    if((m - 1) * 2 + 1 > n) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j && i % 2 == 1 && cnt < m) {
                    cout << "R";
                    cnt++;
                } else cout << ".";
//                cout << ((i == j && j <= m && i % 2 == 1) ? 'R' : '.');
            }
            cout << "\n";
        }
    }

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
