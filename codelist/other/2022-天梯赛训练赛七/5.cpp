//
// Created by onglu on 2022/3/26.
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
int a, b, c, d, e, f;
vector<int> p;
void work() {
    int t;
    cin >> a >> b >> c >> d >> e >> f;
    t = max({a, b, c, d});
    p.clear();
    if(a < t - f || a < e) p.push_back(1);
    if(b < t - f || b < e) p.push_back(2);
    if(c < t - f || c < e) p.push_back(3);
    if(d < t - f || d < e) p.push_back(4);
    if(p.size() == 0) cout << "Normal" << endl;
    else if(p.size() == 1) cout << "Warning: please check #" << p[0] << "!" << endl;
    else cout << "Warning: please check all the tires!" << endl;
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