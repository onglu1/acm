//
// Created by onglu on 2022/3/9.
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
int p, h, w;
int sh, sw;
void print() {
    if(h > sh) cout << "ni li hai! ";
    else if(h < sh) cout << "duo chi yu! ";
    else cout << "wan mei! ";
    if(w > sw) cout << "shao chi rou!" << endl;
    else if(w < sw) cout << "duo chi rou!" << endl;
    else cout << "wan mei!" << endl;
}
void work() {
    cin >> p >> h >> w;
    if(p == 1) sh = 130, sw = 27;
    else sh = 129, sw = 25;
    print();
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}