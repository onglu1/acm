//
// Created by onglu on 2022/3/16.
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
const int N = 1e4 + 10;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int pre[N];
int fid(int x) {
    return pre[x] == x ? x : pre[x] = fid(pre[x]);
}
vector<int> id;
void work() {
    cin >> n;
    for(int i = 1; i < N; i++) pre[i] = i;
    for(int i = 1; i <= n; i++) {
        int k, p = -1;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            id.push_back(x);
            if(p != -1) {
                pre[fid(x)] = fid(p);
            }
            p = x;
        }
    }
    sort(all(id));
    id.resize(unique(all(id)) - id.begin());
    cout << id.size() << " ";
    int ttt = 0;
    for(auto x : id) {
        if(pre[x] == x) {
            ttt++;
        }
    }
    cout << ttt << endl;
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(fid(x) == fid(y)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
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