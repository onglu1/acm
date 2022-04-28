//
// Created by onglu on 2022/4/17.
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
int n, m;
int a, b, t[N];
void work() {
    cin >> n >> a >> b;
    char ca = 'R', cb = 'B';
    int res = n;
    int len = a / (b + 1);
//    cout << len << endl;
    int plus = a - len * (b + 1);
    while(a >= len) {
        for(int i = 1; i <= len + (plus > 0); i++) {
            cout << ca;
        }
        a -= len + (plus > 0);
        if(a > 0) cout << cb;
        plus -= 1;
    }
//    for(int i = 1; i <= a; i++) {
//        cout << ca;
//    }
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