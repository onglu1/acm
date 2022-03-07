#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, m;
vector<int> a;
void work() {
    cin >> n >> m;
    a.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a.push_back(max(i - 1, n - i) + max(j - 1, m - j));
        }
//        cout << endl;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();

    return 0;
}