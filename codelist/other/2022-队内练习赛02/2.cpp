//
// Created by onglu on 2022/4/2.
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
int n, ocu[8 * 24 * 60];
struct node {
    string name;
    int t;
};
map<string, int> M, T;
vector<node> a;
void work() {
    int cnt;
    M.clear();
    T.clear();
    a.clear();
    memset(ocu, 0, sizeof(ocu));
    for(int i = 1; i <= n; i++) {
        node t;
        int w, m;
        cin >> t.name >> w >> m;
        t.t = w * (24 * 60) + (m / 100) * 60 + m % 100;
        T[t.name] = t.t;
        a.push_back(t);
    }
    cin >> cnt;
    int ok = 1;
    for(int i = 1; i <= cnt; i++) {
        int w, m;
        string name;
        cin >> name;
        m = T[name];
        M[name] = 1;
        for(int j = m; j < m + 30; j++) {
            if(ocu[j] == 1) ok = 0;
            ocu[j] = 1;
        }
    }
    if(!ok) {
        cout << "-1" << endl;
        return ;
    }
    std::sort(a.begin(), a.end(), [](const node &a, const node &b) {
        return a.t < b.t;
    });
    cnt = 0;
    int now = -100;
    for(auto x : a) {
        if(M.count(x.name)) {
            if(now + 30 <= x.t)
                cnt++;
            now = x.t;
        } else {
            if(now + 30 <= x.t) {
                cnt++;
                now = x.t;
            }
        }
    }
    cout << cnt << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        if(n == 0) break;
        work();
    }
    return 0;
}