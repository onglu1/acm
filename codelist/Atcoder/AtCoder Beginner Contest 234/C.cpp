#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n;

void work() {

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    while(n) {
        ans.push_back(n % 2 * 2);
        n /= 2;
    }
    if(ans.size() == 0) cout << 0 << endl;
    else {
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}