//
// Created by onglu on 2022/4/27.
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
int n, m, a[N], vis[N];
int b[N];
map<int, vector<int> > M;
vector<int> get(int x) {
    vector<int> v;
    v.push_back(x);
    vis[x] = 1;
    x = a[x];
    while(!vis[x]) {
        v.push_back(x);
        vis[x] = 1;
        x = a[x];
    }
    return v;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        auto v = get(i);
        if(v.size() % 2 == 1) {
            for(int j = 0; j < v.size(); j++) {
                b[v[j]] = v[(j + (v.size() + 1) / 2) % v.size()];
            }
        } else if(M.count(v.size())){
            for(int j = 0; j < v.size(); j++) {
                b[v[j]] = M[v.size()][j];
                b[M[v.size()][j]] = v[(j + 1) % v.size()];
            }
            M.erase(v.size());
        } else M[v.size()] = v;
    }
    if(M.size()) {
        cout << -1 << endl;
        return ;
    }
    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}