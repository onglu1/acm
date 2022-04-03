//
// Created by onglu on 2022/3/19.
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
const int N = 100;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], vis[N], f[N];
string name[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i] >> name[i];
    }
    for(int i = 1; i <= n; i++) if(!vis[i]){
        for(int j = n; j > 0; j--) if(!vis[j] && (f[i] ^ f[j]) == 1) {
            cout << name[i] << " " << name[j] << endl;
            vis[i] = vis[j] = 1;
            break;
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