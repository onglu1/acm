//
// Created by onglu on 2022/3/23.
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
string s[109];
void work() {
    while(1) {
        n++;
        cin >> s[n];
        if(s[n] == ".") {
            n--;
            break;
        }
    }
    if(n < 2) {
        cout << "Momo... No one is for you ..." << endl;
    } else if(n < 14) {
        cout << s[2] << " is the only one for you..." << endl;
    } else {
        cout << s[2] << " and " << s[14] << " are inviting you to dinner..." << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}