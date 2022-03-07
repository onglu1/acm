#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
char c[109];
int n, ans;
void dfs(int x, int sum, int lst) {
    if(x == n) {
        ans += sum + lst;
        return ;
    }
    dfs(x + 1, sum + lst, c[x] - '0');
    dfs(x + 1, sum, lst * 10 + c[x] - '0');
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    n = strlen(c);
    dfs(0, 0, 0);
    cout << ans / 2 << endl;
    return 0;
}