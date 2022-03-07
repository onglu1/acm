#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 2009;
int g[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("data.out", "w", stdout);
    g[0][0] = 1;
    for(int i = 1; i < N; i++) {
        g[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            g[i][j] = (g[i - 1][j - 1] + g[i - 1][j]) % 7;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(g[i][j] == 0) {
                cout << "#";
            }
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}
