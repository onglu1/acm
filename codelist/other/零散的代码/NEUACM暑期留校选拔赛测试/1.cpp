//
// Created by onglu on 2022/5/29.
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
const int N = 2e3 + 10;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], b[N], M1[209], M2[209];
void work() {
    memset(M1, 0, sizeof(M1));
    memset(M2, 0, sizeof(M2));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        M1[a[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        M2[b[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int t = a[i] ^ b[j];
            if(M1[t] ^ M2[t]) {
                cout << "yes" << endl;
                return ;
            }
        }
    }
    cout << "no" << endl;

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
    while(cin >> n) work();
    return 0;
}