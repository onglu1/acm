//
// Created by onglu on 2022/3/5.
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
int n, m, l, a[N];
vector<char> v[N];
vector<char> t;
void getst() {
    if(t.empty()) return ;
    cout << *t.rbegin();
    t.pop_back();
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) {
        char c;
        for(int j = 1; j <= m; j++) {
            cin >> c;
            v[i].push_back(c);
        }
        reverse(all(v[i]));
    }
    int opt = 0;
    while(cin >> opt) {
        if(opt == -1) break;
        if(opt == 0) {
            getst();
        } else {
            if(v[opt].empty()) continue;
            if(t.size() == l) getst();
            t.push_back(*v[opt].rbegin());
            v[opt].pop_back();
        }
    }
    return 0;
}