//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 5009;
//const int N = 309
int n, m;
string s;
int check(int l, int r) {
    for(int i = 0; l + i < r - i; i++) {
        if(s[l + i] != s[r - i]) {
            return 0;
        }
    }
    return 1;
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int l = 0, r = (int)s.size() - 1;
    while(l <= r && s[r] == 'a') {
        if(s[l] == 'a') l++;
        r--;
    }
    if(l > r) {
        cout << "Yes" << endl;
    } else {
        cout << (check(l, r) ? "Yes" : "No") << endl;
    }
    return 0;
}