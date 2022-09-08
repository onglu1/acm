//
// Created by onglu on 2022/5/14.
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
int n, m, a[N];
int C, R, S;
int ceil(int x, int y) {
    if(x == 0) return 0;
    else return (x - 1) / y + 1;
}
void work() {
    cin >> C >> R >> S;
    if(R == 0) {
        cout << ceil(C, S) << " " << ceil(C, S) << endl;
        return ;
    }
    int cnt = (C + R - 1) / S + 1;
    cout << cnt - ceil(R, S) << " " << (R >= cnt ? 0 : cnt - R) << endl;
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