//
// Created by onglu on 2022/5/23.
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
int n, m, a[N], b[N];
vector<pair<int, int> > v;
vector<int> ans;
void work() {
    v.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        v.push_back({a[i], b[i]});
    }
    std::sort(v.begin(), v.end());
    v.resize(std::unique(v.begin(), v.end()) - v.begin());
    int maxn = 0;
    for(auto x : v) {
        maxn = max(maxn, x.second);
        if(x.second < maxn) {
            cout << -1 << endl;
            return ;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[j].first == a[i] && v[j].second == b[i]) {
                a[i] = j;
                break;
            }
        }
    }
    ans.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = n; j > i; j--) {
            if(a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                ans.push_back(j);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x << " " << x - 1 << endl;
    }
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
    while(Case--) work();
    return 0;
}