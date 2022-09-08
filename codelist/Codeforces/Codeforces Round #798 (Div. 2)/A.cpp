//
// Created by onglu on 2022/6/11.
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
int n, m, k;

int lst, ct;
void update(int x) {
    if(x != lst) {
        ct = 1;
        lst = x;
    } else ct += 1;
}
void work() {
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<char> v[2];
    v[0] = vector<char> (s.begin(), s.end());
    cin >> s;
    v[1] = vector<char> (s.begin(), s.end());
    std::sort(v[0].begin(), v[0].end());
    std::sort(v[1].begin(), v[1].end());
    reverse(all(v[0]));
    reverse(all(v[1]));
    vector<char> ans;
    ct = 0, lst = 0;
    for(int i = 0; i < n + m; i++) {
        if(v[0].empty() || v[1].empty()) break;
        if(ct == k) {
            update(1 - lst);
            ans.push_back(v[lst].back());
            v[lst].pop_back();
        } else {
            if(v[0].back() < v[1].back()) {
                ans.push_back(v[0].back());
                v[0].pop_back();
                update(0);
            } else {
                ans.push_back(v[1].back());
                v[1].pop_back();
                update(1);
            }
        }
    }
    for(auto x : ans) {
        cout << x ;
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
    cin >> Case;
    while(Case--) work();
    return 0;
}