//
// Created by onglu on 2022/3/23.
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
map<string, int> M;
vector<pair<string, int> > v;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        M[s] = 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        string s;
        int cnt;
        cin >> s >> cnt;
        v.emplace_back(s, cnt);
    }
    int total = 0;
    std::sort(v.begin(), v.end());
    for(auto x : v) total += x.second;
    int ok = 0 ;
    for(auto x : v) if(!M.count(x.first)) {
        if(x.second * m > total) {
            cout << x.first << endl;
            ok = 1;
        }
    }
    if(!ok) cout << "Bing Mei You" << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}