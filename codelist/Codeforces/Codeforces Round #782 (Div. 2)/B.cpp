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
int n, k, a[N], ff[N];
string s;
void work() {
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < n; i++) ff[i] = 0;
    int used = k;
    for(int i = 0; i < s.size() && used; i++) {
        if((s[i] - '0' + k) % 2 == 0) {
            used -= 1;
            ff[i] = 1;
        }
    }
    if(used) {
        for(int i = 0; i + 1 < s.size(); i++) {
            cout << "1";
        }
        if(used % 2 == 0) cout << "1";
        else cout << "0";
        ff[s.size() - 1] += used;
    } else {
        for(int i = 0; i < s.size(); i++) {
            if(ff[i]) cout << "1";
            else {
                cout << (s[i] - '0' + k) % 2;
            }
        }
    }
    cout << endl;
    for(int i = 0; i < s.size(); i++) {
        cout << ff[i] << " ";
    }
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