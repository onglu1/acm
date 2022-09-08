//
// Created by onglu on 2022/5/9.
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
int ans[N], lst[N];
char c[N];
void work() {
    cin >> n >> m;
    cin >> c;
    int cc = 0;
    for(int i = 0; i < m; i++) vis[i] = 0;
    for(int i = 0; i < n * m; i++) {
        if(c[i] == '1') {
            if(vis[i % m] == 0) {
                cc += 1;
                vis[i % m] = 1;
            }
        }
        ans[i] = cc;
    }
//    for(int i = 0; i < n * m; i++) {
//        cout << ans[i] << " ";
//    }
//    cout << endl;
    for(int i = 0; i < m; i++) lst[i] = 0;
    queue<char> q;
    cc = 0;
    for(int i = 0; i < m; i++) {
        q.push(c[i]);
        cc += c[i] == '1';
        lst[i] = cc > 0;
        if(cc) ans[i] += 1;
    }
    for(int i = m; i < n * m; i++) {
        q.push(c[i]);
        cc += c[i] == '1';
        cc -= q.front() == '1';
        q.pop();
        ans[i] += lst[i % m] + (cc > 0);
        lst[i % m] += (cc > 0);
    }
    for(int i = 0; i < n * m; i++) {
        cout << ans[i] << " ";
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
    while (Case--) work();
    return 0;
}
/*
 * 列是好处理的，唯一的是行
 *
 */