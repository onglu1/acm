//
// Created by onglu on 2022/3/5.
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(s.size() == 6) {
        for(int i = 0; i < 4; i++) cout << s[i];
        cout << "-";
        for(int i = 4; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        if((s[0] - '0') * 10 + s[1] - '0' < 22) {
            cout << "20";
        } else cout << "19";
        for(int i = 0; i < 2; i++) cout << s[i];
        cout << "-";
        for(int i = 2; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}