//
// Created by onglu on 2022/5/6.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, k, cnt;
int nco[N], eco[N];
struct node {
    int y, id;
};
vector<node> ver[N];
void dfs(int x, int pre, int f) {
    for(auto y : ver[x]) if(y.y != pre) {
        cnt++;
        if(f) {
            eco[y.id] = n + cnt;
            nco[y.y] = cnt;
        } else {
            eco[y.id] = cnt;
            nco[y.y] = n + cnt;
        }
        dfs(y.y, x, 1 - f);
    }
}
void work() {
    cin >> k;
    n = 1 << k;
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back({y, i});
        ver[y].push_back({x, i});
    }
    cnt = 0;
    nco[1] = n;
    dfs(1, 0, 1);
    cout << 1 << endl;
    for(int i = 1; i <= n; i++) cout << nco[i] << " " ;
    cout << endl;
    for(int i = 1; i < n; i++) cout << eco[i] << " ";
    cout << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}