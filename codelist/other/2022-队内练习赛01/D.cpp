//
// Created by onglu on 2022/3/2.
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
string s;
int check(int l, int r) {
    l++; r--;
    int pos1, pos2;
    pos1 = l;
    while(s[pos1] != '&') pos1++;
    pos2 = pos1 + 1;
    while(s[pos2] != '&') pos2++;
    char c1 = s[pos1 - 1];
    char c2 = s[pos2 - 1];
    char c3 = s[r];
    int f1 = (pos1 - l) == 2;
    int f2 = (pos2 - pos1 - 1) == 2;
    int f3 = (r - pos2) == 2;
    if(c1 == c2 && f1 != f2) return 0;
    if(c1 == c3 && f1 != f3) return 0;
    if(c2 == c3 && f2 != f3) return 0;
    return 1;
}
void work() {
    int l = 0;
    s = s + '|';
    while(l < s.size()) {
        int r = l;
        while(s[r + 1] != '|') r++;
        if(check(l, r)) {
            cout << "yes" << endl;
            return ;
        }
        l = r + 2;
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
    while(cin >> s) {
        if(s == "#") break;
        work();
    }
    return 0;
}