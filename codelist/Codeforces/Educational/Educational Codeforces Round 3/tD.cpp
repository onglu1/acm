//
// Created by onglu on 2022/4/27.
//

#include <bits/stdc++.h>
#define int long long
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
int n, m, k, s;
int d[N], p[N];
struct node {
    int d, p;
} a[N];
vector<pair<int, int> > ans;
int check(int x) {
    int md = d[0], mp = p[0];
    int td = 0, tp = 0;
    for(int i = 1; i <= x; i++) {
        if(md > d[i]) td = i;
        if(mp > p[i]) tp = i;
        md = min(md, d[i]);
        mp = min(mp, p[i]);
    }
    vector<pair<int, pair<int, int> > > obj;
    for(int i = 0; i < m; i++) {
        if(a[i].d == 1) {
            obj.push_back({a[i].p * md, {i, td}});
        } else {
            obj.push_back({a[i].p * mp, {i, tp}});
        }
    }
    std::sort(obj.begin(), obj.end());
//    for(auto x : obj) {
//        cout << x.first << endl;
//    }
    int sum = 0;
    ans.clear();
    for(int i = 0; i < k; i++) {
        ans.push_back(obj[i].second);
        sum += obj[i].first;
    }
//    cout << md << " " << mp << " " << sum << " " << s << endl;
    return sum <= s;
}
void work() {
    cin >> n >> m >> k >> s;
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < m; i++) {
        cin >> a[i].d >> a[i].p;
    }
    int l = 0, r = n - 1;
    while(l <= r) {
        if(check(Mid)) r = Mid - 1;
        else l = Mid + 1;
    }
    if(l == n) cout << -1 << endl;
    else {
        cout << l + 1 << endl;
        check(l);
        std::sort(ans.begin(), ans.end());
        for(auto x : ans) {
            cout << x.first + 1 << " " << x.second + 1 << endl;
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
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}