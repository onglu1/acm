//
// Created by onglu on 2022/3/6.
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

void work() {

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        if(a[i]) {
            cnt++;
            for(int j = i * 2; j <= 100; j++) {
                a[j] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}