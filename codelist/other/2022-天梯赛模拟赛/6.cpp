//
// Created by onglu on 2022/4/18.
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
string s;
int ord(char c) {
    if('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a';
}
void work() {
    cin >> s;
    for(auto x : s) {
        if(!isalpha(x)) {
            cout << "N" << endl;
            return ;
        }
    }
    int ok = 1;
    for(int i = 1; i < s.size(); i++) {
        if(isupper(s[i - 1])) {
            if(islower(s[i])) {
                ok &= ord(s[i]) == ord(s[i - 1]);
            } else {
                ok &= ord(s[i]) == ord(s[i - 1]) + 1;
            }
        } else {
            if(isupper(s[i])) {
                ok &= ord(s[i]) == ord(s[i - 1]);
            } else {
                ok &= ord(s[i]) == ord(s[i - 1]) - 1;
            }
        }
    }
    if(ok) cout << "Y" << endl;
    else cout << "N" << endl;
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