//
// Created by onglu on 2022/3/12.
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
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
const int N = 309;
int n, m;
string s[N];
char a[N][N];
char c;
void work() {
    cin >> c >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
    int ok = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] != s[n - i - 1][n - j - 1]) {
                ok = 0;
            }
        }
    }
    if(ok) cout << "bu yong dao le" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[n - i - 1][n - j - 1] != ' ') {
                cout << c;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    work();
    return 0;
}