//
// Created by onglu on 2022/3/12.
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
//const int N = 309
int n, m, a[N];
vector<int> ver[N], v;
int root, dth;
int dfs1(int x, int dd) {
//    cout << x << endl;
    dth = max(dth, dd);
    for(auto y : ver[x])
        dfs1(y, dd + 1);
}
void dfs2(int x, int dd) {
    if(dd == dth) {
        v.push_back(x);
    }
    for(auto y : ver[x])
        dfs2(y, dd + 1);

}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == -1) {
            root = i;
        } else {
            ver[x].push_back(i);
        }
    }
    dfs1(root, 1);
    dfs2(root, 1);
    sort(all(v));
    cout << dth << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " \n"[i == v.size() - 1] ;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}