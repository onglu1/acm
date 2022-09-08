#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1009;
int n, m, ca[N], cb[N];
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ca[x] += 1;
        cb[y] += 1;
    }
    for(int i = 1; i <= n; i++) {
        if(ca[i] == n || cb[i] == n) {
            cout << n - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}