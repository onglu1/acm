//
// Created by onglu on 2022/3/26.
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
string t = "chi1 huo3 guo1";
void work() {
    n = 0;
    int k = -1, cnt = 0;
    while(1) {
        string s;
        getline(cin, s);
        if(s == ".") break;
        n++;
        if(s.find(t) != s.npos) {
            cnt++;
            if(k == -1) k = n;
        }
    }
    cout << n << endl;
    if(cnt == 0) cout << "-_-#" << endl;
    else {
        cout << k << " " << cnt << endl;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}